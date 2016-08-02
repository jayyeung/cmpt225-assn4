/*
 * filename: BSTADT.cpp
 *
 * Class Description: A data collection ADT class to satisfy Assn 3's requiremetns.
 * Class Invariant:
 *
 * Creation date: July 7, 2016
 * Author: Jason Yeung, Bob Tian
 */
#include "Node.h"
#include <iostream>
#include "BSTADT.h"

using namespace std;

BSTADT::BSTADT() {
  rootPtr = NULL;
  numberofelements = 0;
}

Node* BSTADT::insert(Node* newNode, Node* currentNode) {
    if (rootPtr == NULL) {
      rootPtr = newNode;
      numberofelements++;
      return newNode;
    }
    else {
      string newWrd, curWrd;
      newWrd = newNode->getItem()->getEnglish();
      curWrd = currentNode->getItem()->getEnglish();

      // element already inside
      if (curWrd == newWrd) {
        cout << "~> ERROR: ELEMENT ALREADY EXISTS -- IGNORING" << endl;
      }
      // move right
      else if (newWrd > curWrd) {
          if (currentNode->getRight() != NULL) { insert(newNode, currentNode->getRight()); } //cout << "moving right" << endl;
          else {
              //cout << "set right" << endl;
              currentNode->setRight(newNode);
              numberofelements++;
              return newNode;
          }
      }
      // move left
      else if (newWrd < curWrd) {
          if (currentNode->getLeft() != NULL) { insert(newNode, currentNode->getLeft()); } //cout << "moving left" << endl;
          else {
            // cout << "set left" << endl;
            currentNode->setLeft(newNode);
            numberofelements++;
            return newNode;
          }
      }
    }

    return NULL;
}

Node* BSTADT::seek(string target, Node* currentNode) {

    if (getnumberofelements() != 0 && currentNode != NULL) {
      string curWrd = currentNode->getItem()->getEnglish();

      if (curWrd == target) {
        return currentNode;
      }
      else if (target > curWrd) {
        return seek(target, currentNode->getRight());
      }
      else if (target < curWrd) {
        return seek(target, currentNode->getLeft());
      }
    }

    return NULL;
}

void BSTADT::print_all(Node* currentNode) {
    if (currentNode != NULL) {
      print_all(currentNode->getLeft());

      cout << currentNode->getItem()->getEnglish() << ":" << currentNode->getItem()->getKlingon() << endl;

      print_all(currentNode->getRight());
    }
};

Node* BSTADT::add(const Word& newEntry) {
  // create a new node to be inserted
  Node* newNode = new Node(newEntry);
  numberofelements++;

  // insert it recursively
  insert(newNode, rootPtr);
}

string BSTADT::retrieve(string engWrd) {
    Node* translated = seek(engWrd, rootPtr);
    if (translated) {
      return translated->getItem()->getKlingon();
    }
    else {
      return "NOT FOUND";
    }
}

void BSTADT::print() {
  print_all(rootPtr);
};

int BSTADT::getnumberofelements() const {
  return numberofelements;
}
