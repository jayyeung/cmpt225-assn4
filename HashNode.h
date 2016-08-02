/*
 * filename: HashNode.h
 *
 * Class Description:
 *
 * Creation date:  Aug 2, 2016
 * Author: Jason Yeung, Bob Tian
 */
#include "Word.h"
#pragma once

class HashNode {

private:
      int key;
      Word *value;
      HashNode *next;

public:
      // constructor
      HashNode(int key, Word* value);

      // gets/sets the key, value
      int getKey();
      Word* getValue();
      void setValue(Word* value);

      // gets/sets the node to the next linked node
      HashNode* getNext();
      void setNext(HashNode *next);
};
