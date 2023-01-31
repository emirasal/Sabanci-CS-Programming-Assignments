#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string codes[4097];

	//Initializing the ascii values
	for (int i=1; i < 256; i++){
		codes[i] = char(i);
	}

	//Initializing remaining values to empty
	for (int i=256; i < 4096; i++){
		codes[i] = "";
	}

	
	ifstream input;
	input.open("compout.txt");

	ofstream output;
	output.open("decompout.txt");

	int code;

	// We directly output the first input
	input >> code;
	output << codes[code];

	int previousCode = code; // This will be used in the future when we need to take a look at the previous code value

	// We will insert codes starting from 256
	int nextCode = 256;

	string outputString; // This string will be used when the code does not exist in our dictionary

	while(input >> code){
		// 2 different cases if the code is inside the dictionary
		if(codes[code] != "") {
			output << codes[code];

			// We are inserting the value
			codes[nextCode] = codes[previousCode] + codes[code][0];
			if (nextCode < 4096) nextCode++;
		}
		else {

			outputString = codes[previousCode] + codes[previousCode][0];

			output << outputString;

			// Then it is entered into the dictionary
			codes[nextCode] = outputString;
			nextCode++;
		}
		// At the end we need to save the code so that it may be used in the next code
		previousCode = code;
	}

	return 0;
}