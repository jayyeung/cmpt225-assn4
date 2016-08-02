/*
 * filename: Word.cpp
 *
 * Class Description:
 *
 * Creation date: July 7, 2016
 * Author: Jason Yeung, Bob Tian
 */

#include "Word.h"
#include <string>

Word::Word() {
	english = ""; // results in \0
	klingon = "";
}

Word::Word(string inpenglish, string inpklingon) {
	english = inpenglish;
  klingon = inpklingon;
}

string Word::getEnglish() const {
	return english;
}

string Word::getKlingon() const {
	return klingon;
}
