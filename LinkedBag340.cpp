//	LinkedBag340.cpp
//	Created by: CSC340

/*
===>					<===
===>  PLEASE ADD CODE	<===
===>					<===
*/
#include "Include.h"
#include <cstdlib>
#include <ctime>


template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
    if (itemCount < 2) {
        return false; // Not enough nodes to remove the second one
    }
    Node<ItemType>* nodeToDelete = headPtr->getNext();
    headPtr->setNext(nodeToDelete->getNext());
    delete nodeToDelete;
    itemCount--;
    return true;
}

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry) {
    Node<ItemType>* newNode = new Node<ItemType>(newEntry);
    Node<ItemType>* lastNode = headPtr;
    while (lastNode->getNext() != nullptr) {
        lastNode = lastNode->getNext();
    }
    lastNode->setNext(newNode);
    itemCount++;
    return true;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    int count = 0;
    Node<ItemType>* currentNode = headPtr;
    while (currentNode != nullptr) {
        count++;
        currentNode = currentNode->getNext();
    }
    return count;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    return getCurrentSize340RecursiveHelper(headPtr);
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>* nextNode) const {
    if (nextNode == nullptr) {
        return 0;
    }
    else {
        return 1 + getCurrentSize340RecursiveHelper(nextNode->getNext());
    }
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    if (headPtr == nullptr) {
        return 0;
    }
    else {
        LinkedBag<ItemType> smallerBag;
        smallerBag.headPtr = headPtr->getNext();
        return 1 + smallerBag.getCurrentSize340RecursiveNoHelper();
    }
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& anEntry) const {
    return getFrequencyOf340RecursiveHelper(headPtr, anEntry);
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* nextNode, const ItemType& anEntry) const {
    if (nextNode == nullptr) {
        return 0;
    }
    else if (nextNode->getItem() == anEntry) {
        return 1 + getFrequencyOf340RecursiveHelper(nextNode->getNext(), anEntry);
    }
    else {
        return getFrequencyOf340RecursiveHelper(nextNode->getNext(), anEntry);
    }
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& anEntry) const {
    if (headPtr == nullptr) {
        return 0;
    }
    else {
        LinkedBag<ItemType> smallerBag;
        smallerBag.headPtr = headPtr->getNext();
        return (headPtr->getItem() == anEntry ? 1 : 0) + smallerBag.getFrequencyOf340RecursiveNoHelper(anEntry);
    }
}

template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
    srand(time(0)); // Seed the random number generator
    int indexToRemove = rand() % itemCount; // Generate a random index
    Node<ItemType>* nodeBefore = getNodeBefore(indexToRemove); // Get the node before the one to remove
    Node<ItemType>* nodeToRemove;
    if (nodeBefore == nullptr) {
        nodeToRemove = headPtr;
        headPtr = headPtr->getNext();
    }
    else {
        nodeToRemove = nodeBefore->getNext();
        nodeBefore->setNext(nodeToRemove->getNext());
    }
    ItemType item = nodeToRemove->getItem();
    delete nodeToRemove;
    itemCount--;
    return item;
}

template<typename ItemType>
Node<ItemType>* LinkedBag<ItemType>::getNodeBefore(int index) const {
    if (index <= 0) {
        return nullptr;
    }
    Node<ItemType>* currentNode = headPtr;
    for (int i = 0; i < index - 1; i++) {
        currentNode = currentNode->getNext();
    }
    return currentNode;
}
