#include <iostream>
#include <string>

using namespace std;

bool doescontain_alph (string word) {
	for (int i = 0; i < word.length(); i++) {
		if (word.at(i) >= 'a' && word.at(i) <= 'z') {
			return true;
		}
	}
	return false;
}

void to_lower (string & word) {
	int upper_lower_difference = 'a' - 'A';
	for (int i = 0; i < word.length(); i++) {
		if (word.at(i) >= 'A' && word.at(i) <= 'Z') {
			word.at(i) = word.at(i) + upper_lower_difference;
		}
	}
}

bool isPalindrome (string word) {
	string reversed = "";
	for (int length = word.length()-1; length >= 0; length--) {
		reversed += word[length];
	}
	if (word == reversed) {
		return true;
	}
	else {
		return false;
	}
}

string string_correction (string s, int no_of_sentences) {
	string New = ". ";
	int count = 0;
	for (int i = 0; i < s.length(); i++) {
		if ((s.at(i) >= 'a' && s.at(i) <= 'z') || s.at(i) == ' ' || s.at(i) == '.') {
			New += s.at(i);
		}
		if (s.at(i) == '.') {
			count ++;
			if (count == no_of_sentences) {
				break;
			}
		}
	}
	return New;
}

int sentence_calculator (string input) {
	int number = 0;
	int k = 0;
	while (k != input.length()) {
		if (input[k] == '.') {
			number++;
		}
		k++;
	}
	return number;
}

string sentence_extractor (string & sentences) {
	string sentence = " ";
	int sentence_start, sentence_end, length;
	sentence_end = sentences.rfind('.'); 
	sentences.at(sentences.rfind('.')) = 'X';
	sentence_start = sentences.rfind('.')+2;
	length = sentence_end - sentence_start;
	sentence += sentences.substr(sentence_start, length);
	sentence += " ";
	return sentence;
}

int word_counter (string sentence) {
	int count = -1;
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence.at(i) == ' ') {
			count++;
		}
	}
	return count;
}

string word_extractor (string & sentence) {
	string word;
	int start, end, length;
	end = sentence.rfind(' ');
	sentence.at(sentence.rfind(' ')) = 'X';
	start = sentence.rfind(' ')+1;
	length = end - start;
	word = sentence.substr(start, length);
	return word;
}

int main () {
	string word, input = "";
	bool word_check = true;
	cout << "Please enter the input sentences: ";
	while (word != "@") {
		cin >> word;
		to_lower(word);
		if (doescontain_alph(word) == false && word != "@") {
			word_check = false;
		}
		input += word;
		input += " ";
		if (word == "@") {
			if (input != "@ ") {
				if (input.find(".") != string::npos) {
					if (word_check == false) {
						cout << "There should be no words without alphabetical characters." << endl << endl;
						word = "";
						input = "";
						word_check = true;
						cout << "Please enter the input sentences: ";
					}
				}
				else {
					cout << "There should be at least one sentence." << endl << endl;
					word = "";
					input = "";
					cout << "Please enter the input sentences: "; 
				}
			}
			else {
				cout << "Input string should not be empty." << endl << endl;
				word = "";
				input = "";
				cout << "Please enter the input sentences: ";
			}
		}

	}
	cout << endl;
	int no_of_sentences = sentence_calculator(input);
	string sentences = string_correction(input, no_of_sentences);

	string sentence, W;
	int word_count;
	for (int i = no_of_sentences; i > 0; i--) {
		cout << "Sentence (" << i << "/" << no_of_sentences << "):" << endl;
		sentence = sentence_extractor(sentences);
		word_count = word_counter(sentence);
		
		for (int i = 0; i < word_count; i++) {
			W = word_extractor(sentence);
			if (i == word_count-1) {
				if (isPalindrome(W)) {
					cout << W;
				}
				else {
					cout << "notpalindrome";
				}
				cout << endl;
			}
			else {
				if (isPalindrome(W)) {
					cout << W << " ";
				}
				else {
					cout << "notpalindrome ";
				}
			}
		}
	}
	return 0;
}