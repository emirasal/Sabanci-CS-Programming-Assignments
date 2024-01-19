#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>
#include <string.h>
#include <cstring>
#include <sys/wait.h>
#include <cstdio>
#include <pthread.h>

using namespace std;

vector<int> processes;
vector<pthread_t> threads;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int backgroundJobsCount = 0;

struct commandLine {
    string command;
    string input;
    string option;
    string redirection;
    string fileName;
    bool isBackgroundJob;
    int length;
};

commandLine parse(string line, ofstream & parseFile){

    commandLine myLine;
    myLine.isBackgroundJob = false;
    myLine.length = 0;

    stringstream ss(line); 
    vector<string> words;
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    int pos = 0;
    parseFile << "----------" << endl;
    myLine.command = words[pos];
    parseFile << "Command: " << words[pos] << endl;
    pos++;
    myLine.length++;
    if (pos < words.size() && words[pos].find('-') == string::npos && words[pos].find('<') == string::npos && words[pos].find('>') == string::npos && words[pos].find('&') == string::npos) {
        myLine.input = words[pos];
        parseFile << "Inputs: " << words[pos] << endl;
        pos++;
        myLine.length++;
    }
    else parseFile << "Inputs: " << endl;

    if (pos < words.size() && words[pos].find('-') != string::npos) {
        myLine.option = words[pos];
        parseFile << "Options: " << words[pos] << endl;
        pos++;
        myLine.length++;
    }
    else parseFile << "Options: " << endl;

    if (pos < words.size() && ((words[pos].find('<') != string::npos) || (words[pos].find('>') != string::npos))) {
        myLine.redirection = words[pos];
        parseFile << "Redirection: " << words[pos] << endl;
        pos++;
        myLine.length++;
        myLine.fileName = words[pos];
        pos++;
        myLine.length++;
    }
    else parseFile << "Redirection: -" << endl;

    if (pos < words.size() && words[pos].find('&') != string::npos) {
        myLine.isBackgroundJob = true;
        parseFile << "Background Job: y" << endl;
        myLine.length++;
    }
    else parseFile << "Background Job: n" << endl;

    parseFile << "----------" << endl;
    return myLine;
}


void *threadFunctionForPrint(void *arg){
    pthread_mutex_lock(&lock);
    int pFD = *((int *)arg);
    cout << "---- " << pthread_self() << endl;

    // Pipe File Stream
    FILE *fp = fdopen(pFD, "r");
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      printf("%s", buffer);
    }
    cout << "---- " << pthread_self() << endl;

    fflush(stdout);
    pthread_mutex_unlock(&lock);
}

void waitForAllProcessesandThreads(){
    // Waiting for Forks
    for (int i = 0; i < processes.size(); i++) {
        int status;
        waitpid(processes[i], &status, 0);
    }
    // Waiting for Threads
    for (int i = 0; i < threads.size(); i++) {
        pthread_join(threads[i], NULL);
    }
    backgroundJobsCount = 0;
}

void AssignArrayValues(char * array[], commandLine CL) {
    
    int pos = 0;

    array[pos] = strdup(CL.command.c_str());
    pos++;
    if (!CL.input.empty()){
        array[pos] = strdup(CL.input.c_str());
        pos++;
    }
    if (!CL.option.empty()) {
        array[pos] = strdup(CL.option.c_str()); 
        pos++;
    }
    array[pos] = NULL;
}

int main() {

    vector<commandLine> commands;
    
    ifstream commandsFile("commands.txt");
    string line;

    ofstream parseFile("parse.txt");
    while (getline(commandsFile, line)) {
        commandLine command = parse(line, parseFile);
        commands.push_back(command);   
    }
    commandsFile.close();
    parseFile.close();

    // Execution
    for (int i=0; i < commands.size(); i++){

        commandLine currentCommand = commands[i];

        // When outputing to a file
        if (currentCommand.redirection == ">") {

            int pid = fork();
            if (pid == 0) {
                //Child 
                // Repleacing console output with file output
                FILE *file = fopen(currentCommand.fileName.c_str(), "w");
                dup2(fileno(file), STDOUT_FILENO);
                        	
                char *myargs[currentCommand.length + 1];
                AssignArrayValues(myargs, currentCommand);
                
                execvp(myargs[0], myargs);
            }
            else {
                // Parent
                if (currentCommand.isBackgroundJob) {
                    backgroundJobsCount++;
                    processes.push_back(pid);
                    // Keep going to next command line
                }
                else {
                    // We have to wait for the execution
                    int status;
                    waitpid(pid, &status, 0);
                }
            }
        }
        else if (currentCommand.command == "wait") {

            waitForAllProcessesandThreads();
        }
        else {
            // Everything will output to a console from now (File output is handled above)
            // Threads will be used to output to console
            int *myPipe = new int[2];
            pipe(myPipe); 
            pthread_t myThread;

            int pid = fork();
            if (pid == 0) {
                // Child
                // Output is done to a pipe
                close(myPipe[0]);
                FILE *fp = fdopen(myPipe[1], "w");
                dup2(fileno(fp), STDOUT_FILENO);

                // We check if input is from file
                if (currentCommand.redirection == "<") {
                    FILE *file = fopen(currentCommand.fileName.c_str(), "r");
                    dup2(fileno(file), STDIN_FILENO);
                }
                
     	        char *myargs[currentCommand.length + 1];
                AssignArrayValues(myargs, currentCommand);

                execvp(myargs[0], myargs);
            }
            else {
                // Parent
                close(myPipe[1]);
                pthread_create(&myThread, NULL, threadFunctionForPrint, (void *)&myPipe[0]);

                if (currentCommand.isBackgroundJob){
                    threads.push_back(myThread);
                    processes.push_back(pid);
                    backgroundJobsCount++;
                }
                else {
                    // Have to wait for it to finish
                    int status;
                    waitpid(pid, &status, 0);
                    pthread_join(myThread, NULL);
                }
            }

        }
    }

    // When command are finished we wait for everything to finish before exiting the program.
    waitForAllProcessesandThreads();

    return 0;
}