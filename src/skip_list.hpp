#include "skip_list.h"
#include <iostream>
#include <cstdlib>


// -------------- SkipList Functions -------------- //


// Constructor
template <typename T>
SkipList<T>::SkipList(const int& numMaxLevels) {
    numElements = 0;
    maxLevels = numMaxLevels;
    SkipListNode<T>* headNode = new SkipListNode<T>;
    headNode->numLevels = maxLevels;
    SkipListNode<T>* sentinelNode = new SkipListNode<T>;
    sentinelNode->numLevels = maxLevels;

    // Allocating 'maxLevels' pointers to be stored in headNode's 'next' array of pointers.
    headNode->next = new SkipListNode<T>*[maxLevels];
    sentinelNode->next = new SkipListNode<T>*[maxLevels];
    head = headNode;
    
    // Each pointer in 'next' points to sentinelNode.
    for (int i = 0; i < maxLevels; i++) {
        head->next[i] = sentinelNode;
        sentinelNode->next[i] = nullptr;
    }

    headNode = nullptr;
    sentinelNode = nullptr;
    
}

// Destructor
template <typename T>
SkipList<T>::~SkipList() {
    clear();
    delete head->next[0]; // Deletes Sentinel Node
    head->next[0] = nullptr;
    delete head; // Deletes Head Node
}

// Assignment Operator Overload
template <typename T>
SkipList<T>& SkipList<T>::operator=(const SkipList<T>& rhs) {
    // Not currently implemented due to chosen 
    // analysis not requiring assignment of SkipLists.
    // Instantiation through constructor is used. 
    // Future work will implement this.
}

// Copy Constructor
template <typename T>
SkipList<T>::SkipList(const SkipList<T>& rhs) {
    // Not currently implemented due to chosen 
    // analysis not requiring copying of SkipLists.
    // Future work will implement this.
}

// ------- Accessor Functions ------- //

template <typename T>
SkipListNode<T>* SkipList<T>::find(const T& value) const {
    SkipListNode<T>* currentNode = head;
    int i = maxLevels - 1;

    // Finding closest predecessor node of the "desired node" with 'data' equal to 'value'
    while (i >= 0) {
        while (currentNode->next[i]->data < value && currentNode->next[i]->next[i] != nullptr) {
            currentNode = currentNode->next[i];
        }
        i--;
    }
    i = 0;
    // currentNode now points to closest predecessor of "desired node"
    
    // If the next node after curentNode equals 'value', then  
    // 'value' is in the list and a pointer to it is returned.
    if (currentNode->next[i]->data == value && currentNode->next[i] != nullptr) {
        std::cout << "Value in SkipList FOUND!" << std::endl;
        return currentNode->next[i];
    }
    else {
        std::cout << "Value in SkipList NOT FOUND!" << std::endl;
        return nullptr;
    }

    currentNode = nullptr;

}

template <typename T>
T SkipList<T>::getElem(const SkipListNode<T>* pos) const {
    return pos->data;
}

template <typename T>
void SkipList<T>::printOnLevel(const int level) const {
    std::cout << "Skip List LEVEL " << level << ":\n------------------" << std::endl;
    int i = level-1;
    SkipListNode<T>* currentNode = head->next[i];
    while (currentNode->next[i] != nullptr) {
        std::cout << currentNode->data << std::endl;
        currentNode = currentNode->next[i];
    }
}

template <typename T>
int SkipList<T>::numElemsOnLevel(const int level) const {
    int numElemsOnLevel = 0;
    int i = level-1;
    SkipListNode<T>* currentNode = head->next[i];
    while (currentNode->next[i] != nullptr) {
        numElemsOnLevel++;
        currentNode = currentNode->next[i];
    }
    return numElemsOnLevel;
}

// ------- Mutator Functions ------- //

template <typename T>
void SkipList<T>::insert(const T& value) {
    numElements++;
    SkipListNode<T>* currentNode = head;
    int i = maxLevels - 1;

    // Finding all predecessors to the spot where 'value' should go.
    SkipListNode<T>** predecessorNodes = new SkipListNode<T>*[maxLevels];
    while (i >= 0) {
        while (currentNode->next[i]->data < value && currentNode->next[i]->next[i] != nullptr) {
            currentNode = currentNode->next[i];
        }
        predecessorNodes[i] = currentNode; // Adds the predecessor of 'value' on the ith level.
        i--;
    }

    // Creating new node with 'data' equal to 'value'.
    SkipListNode<T>* newNode = new SkipListNode<T>;
    newNode->data = value;

    // Flip a coin until we get tails. Number of 'heads' 
    // is the newNode's height ("number of levels", or 
    // size of newNode's 'next' array of pointers.).
    int heads = 1;
    while (rand() % 100 < 100*coinProbability && heads < maxLevels)
        heads++;
    newNode->numLevels = heads;
    newNode->next = new SkipListNode<T>*[heads];

    // Redirecting newNode's predecessor's 'next' pointers
    // to point to newNode while newNode's 'next' pointers
    // point to what each predecessor pointed to on level 'i'.
    for (int i = 0; i < heads; i++) {
        SkipListNode<T>* temp = predecessorNodes[i]->next[i];
        predecessorNodes[i]->next[i] = newNode;
        newNode->next[i] = temp;
    }

    // Setting pointers back to nullptr.
    currentNode = nullptr;
    for (int i = 0; i < maxLevels; i++) {
        predecessorNodes[i] = nullptr;
    }
    predecessorNodes = nullptr;
    newNode = nullptr;

}

template <typename T>
void SkipList<T>::erase(const SkipListNode<T>* pos) {
    // Not currently implemented due to chosen 
    // analysis not requiring erasure of elements.
    // Future work will implement this.
}

template <typename T>
void SkipList<T>::clear() {
    int i = maxLevels - 1;
    SkipListNode<T>* tmp1;
    tmp1 = head->next[i];
    while (i >= 0) {
        while (tmp1 != nullptr) {
            head->next[i] = nullptr;
            head = tmp1;
            tmp1 = head->next[i];
        }
        i--;
    }
    SkipListNode<T>* tmp2;
    tmp2 = head->next[0];
    while (tmp2 != nullptr) {
        delete head->next[0];
        head->next[0] = tmp2;
        tmp2 = head->next[0];
    }
    tmp2 = nullptr;    
    tmp1 = nullptr;  
    numElements = 0;  
}