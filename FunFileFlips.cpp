///============================================================================
// Name        : FunFileFlips.cpp
// Author      : Grant Brosovich
// Version     : 1
// Copyright   : Some kind of Copyright
// Description : Driving class for file manipulation
//============================================================================
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class FileHandler {
	//class for appending to pre-existing file
public:
	void appendToFile(const string& filename) {
		//ios::app performs the appending action
		ofstream outfile(filename, ios::app);
		if (!outfile) {
			cerr << "Error opening file: " << filename << endl;
			return;
		}
		//console displays to track process and receive input to append

		string userInput;
		cout << "Enter text to append to " << filename << ": ";
		getline(cin, userInput);
		outfile << userInput << endl;

		cout << "Text successfully appended to " << filename << endl;
		outfile.close();
	}
};


class FileReverser {
	//reversing class. takes in, closes access, calls reversing recursive function, opens/closes reverse file
public:
    void reverseFile(const string& inputFile, const string& outputFile) {
        ifstream infile(inputFile);
        if (!infile) {
            cerr << "Error opening file: " << inputFile << endl;
            return;
        }

        string content((istreambuf_iterator<char>(infile)), istreambuf_iterator<char>());
        infile.close();

        string reversed = reverseRec(content);

        ofstream outfile(outputFile);
        if (!outfile) {
            cerr << "Error opening file: " << outputFile << endl;
            return;
        }

        outfile << reversed;
        outfile.close();

        cout << "Reversed content written to " << outputFile << endl;
    }

private:
    //reversing heavy lifter
    string reverseRec(const string& str) {
        if (str.empty()) {
            return "";
        }
        //returns a shrinking original string and places the "missing" character at the end.
        //Does this continually until the substring is empty.
        return reverseRec(str.substr(1)) + str[0];
    }
};

int main() {
	const string inputFilename = "CSC450_CT5_mod5.txt";
	const string reversedFilename = "CSC-mod5-reverse.txt";

	FileHandler fileHandler;
	FileReverser fileReverser;

	fileHandler.appendToFile(inputFilename);
	fileReverser.reverseFile(inputFilename, reversedFilename);

	return 0;
}
