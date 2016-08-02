/*
 * filename: Word.h
 *
 * Class Description:
 *
 * Creation date: July 7, 2016
 * Author: Jason Yeung, Bob Tian
 */
#include <string>
#pragma once

using namespace std;

class Word {

private:
	string english;
 	string klingon;

public:
	// default constructor
	Word();

	// constructor w/ input
	Word(string inpenglish, string inpklingon);

	// get the translation
	string getEnglish() const;
	string getKlingon() const;
};
