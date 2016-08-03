/*
 * filename: BSTADT.h
 *
 * Class Description: A data collection ADT class to satisfy Assn 3's requiremetns.
 * Class Invariant:
 *
 * Creation date: July 7, 2016
 * Author: Jason Yeung, Bob Tian
 */
#include "HashNode.h"
#include "Word.h"

// a chained hash table ADT
class HASHADT {

private:
      int table_size;
      HashNode **table;

public:
      // constructor
      HASHADT();

      // gets/inserts a word object into the hash table
      Word* getElement(int key);
      bool insertElement(int key, Word* value);
};
