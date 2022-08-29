// Emir Asal 27933

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct cell {
		char letter;
		char color;
	};

// This function returns true if every character in a string is lowercase
bool is_all_lowercase(string word) {
	for (unsigned int i = 0; i < word.length(); i++) {
		if (word.at(i) < 'a' || word.at(i) > 'z') {
			return false;
		}
	}
	return true;
}
// This function return true if the same letter is repeated in a string
bool does_contain_repeated_letters(string word) {
	for (unsigned int i = 0; i < word.length(); i++) {
		for (unsigned int j = i + 1; j < word.length(); j++) {
			if (word[i] == word[j]) {
				return true;
			}
		}
	}
	return false;
}

// This function checks if the green letters are in the same position with the guess, and return true if they match.
// Positions that are not green is replaced with the '-' character inside the function below "update_matrix".
bool green_letter_check (string guess, string green_positions) {
	for (unsigned int i = 0; i < green_positions.length(); i++) {
		if (green_positions[i] != '-' && green_positions[i] != guess[i]) {
			return false;
		}
	}
	return true;
}

//Using the functions above this function checks if the given guess is correct and returns true when every possibility is considered.
bool input_check(string secret, string guess, string previous_tries, string green_positions) {
	if (secret.length() < guess.length()) {
		cout << "The word is too long!" << endl;
		return false;
	}
	if (secret.length() > guess.length()) {
		cout << "The word is too short!" << endl;
		return false;
	}
	if (!is_all_lowercase(guess)) {
		cout << "Your input has illegal letters!" << endl;
		return false;
	}
	if (does_contain_repeated_letters(guess)) {
		cout << "Your input has a duplicate letter!" << endl;
		return false;
	}
	if (previous_tries.find(guess) != string::npos) {
		cout << "You've already tried this word!" << endl;
		return false;
	} 
	if (!green_letter_check(guess, green_positions)) {
		cout << "You did not use the green letter in your word!" << endl;
		return false;
	}
	return true;
}

// This function update the matrix according to given guess and notes the positions of the green letters
// Positions that are not green are replaced with the '-'. 
void update_matrix (vector<vector <cell>> &matrix, string secret, string guess, string &green_positions, int current_row) {
	green_positions = "";
	for (unsigned int i = 0; i < guess.length(); i++) {
		// Checks if it is GREEN. And if it is green, position of that character is saved to the green_positions string.
		if (secret[i] == guess[i]) {
			green_positions += guess[i];
			matrix[current_row][i].color = 'G';
		}
		//Checks if it is YELLOW when it is not GREEN
		else if (secret.find(guess[i]) != string::npos) {
			green_positions += '-';
			matrix[current_row][i].color = 'Y';
		}
		else {
			green_positions += '-';
			matrix[current_row][i].color = 'B';
		}
		matrix[current_row][i].letter = guess[i];
	}
}

void print_matrix(vector<vector <cell>> matrix) {
	for (unsigned int i = 0; i < matrix.size(); i++) {
		for (unsigned int k = 0; k < matrix[0].size(); k++) {
			cout << "|| " << matrix[i][k].letter << " , " << matrix[i][k].color << " ";
		}
		cout << "|| " << endl;
	}
}

int main() {
	cout << "Welcome to SWordle!" << endl;
	ifstream file;
	string filename;
	cout << "Please enter the filename: ";
	cin >> filename;
	file.open(filename.c_str());
	while (file.fail()) {
		file.close();
		cout << "Couldn't find the file!" << endl;
		cout << "Please enter the filename: ";
		cin >> filename;
		file.open(filename.c_str());
	}
	
	// Data inside the txt file is transfered to variables here
	int attempts;
	string secret;
	file >> attempts >> secret;
	cout << "The word that you will guess has " << secret.length() << " letters and you have " << attempts << " attempts." << endl;

	// Creates a 2D matrix (every value starts with '-')
	cell initializer;
	initializer.letter = '-', initializer.color = '-';
	vector <vector <cell>> matrix(attempts, vector <cell> (secret.length(), initializer));

	// Positions of the green letters are going to be saved inside the "green_positions" variable inside the function "update_matrix".
	string guess, previous_tries = "", green_positions = "";
	int current_row = 0;
	bool correct = false;
	while (attempts > 0 && !correct) {
		cout << "What's your guess? ";
		cin >> guess;
		if (input_check(secret, guess, previous_tries, green_positions)) {
			update_matrix(matrix, secret, guess, green_positions, current_row);
			print_matrix(matrix);
			if (guess == secret) {
				correct = true;
			}
			else {
				// After input check has passed and matrix updated, if guess is not correct: current_row incremanted and attempts are decreased.
				attempts--;
				current_row++;
				previous_tries += guess;
				previous_tries += " ";
			}
		}
	}
	if (attempts == 0) {
		cout << "You lose!" << endl;
	}
	else {
		cout << "You win!" << endl;
	}
	return 0;
}
