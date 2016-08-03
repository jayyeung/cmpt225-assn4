/*
 * filename: EKTapp.cpp
 *
 * Created on: July 7, 2016
 * Author: Jason Yeung, Bob Tian
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "HASHADT.h"
#include "HashNode.h"

using namespace std;

bool readDataFile(const char* filename, HASHADT* TranslatorLib) {
	ifstream myfile (filename);
	if (myfile.is_open())
	{
	cout << "READING: " << filename << endl;
	cout << "----------------------------------" << endl;
	string line;
	while ( getline (myfile,line) )
	{
			// prepare current line for insertion
			int i = 0;
			bool passedcolon = false;
			string EngWrd, KlngWrd;
			while (line[i] != '\0') {
				if (line[i] == ':') { passedcolon = true; }
				else {
					if (!passedcolon) { EngWrd += line[i]; }
					else { KlngWrd += line[i]; }
				}
				i++;
			}

			// add word into translator lib
			Word* newVocab = new Word(EngWrd, KlngWrd);
			TranslatorLib->insertElement(tolower(EngWrd[0]), newVocab);

			// print out line
			cout << line << "\n";
	}

	cout << "----------------------------------" << endl;
	cout << "DATAFILE END\n" << endl;
	myfile.close();
	return true;
	}
	else cout << "ERROR: Unable to open data file\n";
	return false;
}


int main() {
	HASHADT* TranslatorLib = new HASHADT();

  // if data file can be read and stored
	if ( readDataFile("dataFile.txt", TranslatorLib) ) {

	  cout << "Type an English word to preview the Klingon translation if found." << endl;
	  cout << "Type 'Display' to preview all words in the translator." << endl;
		cout << "Press 'CTRL-D' to quit the program." << endl;
		cout << "INPUT READY: " << endl;

		string aLine;
    while(getline(cin, aLine)) {   // while (there is data)
				if (aLine != "") {
					if (aLine == "display") {
						TranslatorLib->printAll();
					}

					else {
						stringstream ss(aLine);
						ss << aLine << ": " << TranslatorLib->getElement(aLine);
						cout << ss.str() << endl;
				}
			}
    }
	}
	cout << "PROG END" << endl;
}
