/*
 * filename: Node.h
 *
 * Class Description:
 *
 * Creation date: July 7, 2016
 * Author: Jason Yeung, Bob Tian
 */
#include "Word.h"
#pragma once

class Node
{

private:
  Word data;
  Node *leftChildPtr;
  Node *rightChildPtr;

public:
  // Constructors
  Node();
  Node(const Word& anItem);

  // Set data to the node
  void setItem(const Word& anItem);

  // Retrieve the data from the node
  Word* getItem();

  // Retrieve Left/Right pointers
  Node* getLeft() const ;
  Node* getRight() const ;

  // Set Left/Right pointers
  void setLeft(Node* leftPtr);
  void setRight(Node* rightPtr);

};
