/*
 * filename: BSTADT.cpp
 *
 * Class Description: A data collection ADT class to satisfy Assn 3's requiremetns.
 * Class Invariant:
 *
 * Creation date: July 7, 2016
 * Author: Jason Yeung, Bob Tian
 */
#include <iostream>
#include "HASHADT.h"
#include "HashNode.h"

using namespace std;

HASHADT::HASHADT() {
  table_size = 32;
  table = new HashNode*[table_size];
  // set all hash key values to NULL
  for (int i = 0; i < table_size; i++) {
    table[i] = NULL;
  }
}

string HASHADT::getElement(string key) {
  int hash_encoding = (int(key[0]) % table_size);

  // if at index hash_encoding is valid
  if (table[hash_encoding] != NULL) {
    // we found the Node.
    // now we have to check the linked nodes if it is our object
    HashNode* cur_node = table[hash_encoding];

    // while we go thru each node and key value is not the same
    while (cur_node != NULL) {
      if (cur_node->getValue()->getEnglish() == key) {
        return cur_node->getValue()->getKlingon();
      }

      cur_node = cur_node->getNext();
    }
    // if we are at last node
  }

  return "NOT FOUND";
}

bool HASHADT::insertElement(int key, Word* value) {
  int hash_encoding = (key % table_size);

  if (table[hash_encoding] == NULL) {
    table[hash_encoding] = new HashNode(key, value);
    cout << "inserted " << endl;
    return true;
  }
  else {
    HashNode* cur_node = table[hash_encoding];

    while (cur_node->getNext() != NULL) {
      cur_node = cur_node->getNext();

      if (cur_node->getValue()->getEnglish() == value->getEnglish()) {
            cout << value->getEnglish() << " already inserted -- IGNORE" << endl;
            return false;
      }
    }
    cur_node->setNext(new HashNode(key, value));

    cout << "inserted " << endl;
    return true;
  }
  return false;
}

void HASHADT::printAll() {
  // for loop is O(1)
  for (int i = 0; i < table_size; i++) {
    HashNode* cur_node = table[i];

    while(cur_node != NULL) {
      cout << cur_node->getValue()->getEnglish() << ": " << cur_node->getValue()->getKlingon() << endl;
      cur_node = cur_node->getNext();
    }
  }
}
