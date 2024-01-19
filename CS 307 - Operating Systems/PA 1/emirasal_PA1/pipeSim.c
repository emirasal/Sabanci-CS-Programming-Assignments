#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    printf("I'm SHELL process, with PID: %d - Main command is: man ls | grep -A 1 -e --all > output.txt\n", (int) getpid());

    int rc = fork();
    if (rc == 0) {
        // child: MAN Process
        int my_pipe[2];
        pipe(my_pipe);

        int rc1 = fork();
        if (rc1 == 0) {
            // grandchild: GREP Process
            printf("I'm GREP process, with PID: %d - My command is: grep -A 1 -e --all\n", (int) getpid());

            close(my_pipe[1]);
            dup2(my_pipe[0], STDIN_FILENO);
            close(my_pipe[0]);

            close(STDOUT_FILENO);
            open("./output.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
            
            char *myargs[6];
            myargs[0] = strdup("grep");
            myargs[1] = strdup("-A");
            myargs[2] = strdup("1");
            myargs[3] = strdup("-e");
            myargs[4] = strdup("--all");
            myargs[5] = NULL;
            execvp(myargs[0], myargs);
        }
        else {
            // MAN Process
            printf("I'm MAN process, with PID: %d - My command is: man ls\n", (int) getpid());

            close(my_pipe[0]);
            dup2(my_pipe[1], STDOUT_FILENO);
            close(my_pipe[1]);

            char *myargs[3];
            myargs[0] = strdup("man");
            myargs[1] = strdup("ls");
            myargs[2] = NULL;
            execvp(myargs[0], myargs);
        }

    } else {
        // SHELL Process
        int rc_wait = wait(NULL);
        printf("I'm SHELL Process, with PID: %d - execution is completed, you can find the results in output.txt\n", (int) getpid());
    }
    return 0;
}