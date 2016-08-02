/*
 * filename: Node.cpp
 *
 * Class Description:
 *
 * Creation date: July 7, 2016
 * Author: Jason Yeung, Bob Tian
 */

#include <string>
#include "Node.h"
#include "Word.h"
#include <iostream>

using namespace std;

Node::Node() {
}

Node::Node(const Word& anItem) {
    data = anItem;
    leftChildPtr = rightChildPtr = NULL;
}

void Node::setItem(const Word& anItem) {
  data = anItem;
}

Word* Node::getItem() {
  return &data;
}

Node* Node::getLeft() const {
  return leftChildPtr;
}

Node* Node::getRight() const {
  return rightChildPtr;
}

void Node::setLeft(Node* leftPtr) {
  leftChildPtr = leftPtr;
}

void Node::setRight(Node* rightPtr) {
  rightChildPtr = rightPtr;
}
