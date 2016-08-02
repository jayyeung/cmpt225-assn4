/*
 * filename: BSTADT.h
 *
 * Class Description: A data collection ADT class to satisfy Assn 3's requiremetns.
 * Class Invariant:
 *
 * Creation date: July 7, 2016
 * Author: Jason Yeung, Bob Tian
 */
#include "Node.h"
#include "Word.h"

class BSTADT {

private:
  Node* rootPtr;
  int numberofelements;

  // Recursive function to insert nodes into BST
  Node* insert(Node* newNode, Node* currentNode);

  // Recursive function to find nodes in BST
  Node* seek(string target, Node* currentNode);

  // Recursive function to print
  void print_all(Node* currentNode);


public:
  //------------------------------------------------------------
  // Constructor and Destructor Section.
  //------------------------------------------------------------
  BSTADT();

  // adds/inserts the word into the BST
  // returns the inserted node with the value
  // if element is already in, return NULL
  Node* add(const Word& newEntry);

  // Returns a the translated word to the node containing the given value,
  // or "NOT FOUND" if not found
  string retrieve(string engWrd);

  // Prints all values in the translator
  void print();

  // Gets number of elements
  int getnumberofelements() const ;
};
