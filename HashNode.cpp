/*
 * filename: HashNode.cpp
 *
 * Class Description:
 *
 * Creation date: Aug 2, 2016
 * Author: Jason Yeung, Bob Tian
 */

#include <string>
#include <iostream>
#include "HashNode.h"
#include "Word.h"

HashNode::HashNode(int key, Word* value) {
      this->key = key;
      this->value = value;
      this->next = NULL;
}


int HashNode::getKey() {
      return key;
}



Word* HashNode::getValue() {
      return value;
}



void HashNode::setValue(Word* value) {
      this->value = value;
}



HashNode* HashNode::getNext() {
      return next;
}



void HashNode::setNext(HashNode *next) {
      this->next = next;
}
