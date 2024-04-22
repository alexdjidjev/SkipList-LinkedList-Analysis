#include "linked_list.h"


// -------------- LinkedListIterator Functions -------------- //


// Constructor
template <typename T>
LinkedListIterator<T>::LinkedListIterator(LinkedListNode<T>* p) {
    ptr = p;
}

// De-reference Operator Overload
template <typename T>
LinkedListNode<T>& LinkedListIterator<T>::operator*() {
    return *ptr;
}

// Arrow Operator Overload
template <typename T>
LinkedListNode<T>* LinkedListIterator<T>::operator->() {
    return ptr;
}

// Addition Operator Overload
template <typename T>
LinkedListNode<T>* LinkedListIterator<T>::operator+(const int increment) {
    int hops = 0;
    while (hops < increment && ptr != nullptr) {
        ptr = ptr->next; 
        hops++;
    }
    return ptr;
}

template <typename T>
bool LinkedListIterator<T>::isNull() {
    return ptr == nullptr;
}


// -------------- LinkedList Functions -------------- //


// Constructor
template <typename T>
LinkedList<T>::LinkedList() {
    numElements = 0;
    head = new LinkedListNode<T>;
    head->next = nullptr;
}

// Destructor
template <typename T> 
LinkedList<T>::~LinkedList() {
    clear();
    delete head;
}

// Assignment Operator Overload
template <typename T> 
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
    clear();
    LinkedListNode<T> *pos_ptr = head;
    LinkedListNode<T> *data_ptr = rhs.head;
    while (data_ptr->next != nullptr) {
        insert(pos_ptr, data_ptr->data);
        pos_ptr = pos_ptr->next;
        data_ptr = data_ptr->next;
    }

    return *this;
}

// Copy Constructor
template <typename T> 
LinkedList<T>::LinkedList(const LinkedList<T>& rhs) {
  head = new LinkedListNode<T>;
  head->next = nullptr; // Creating sentinel node

  *this = rhs;
}

// ------- Accessor Functions ------- //

template <typename T>
int LinkedList<T>::getSize() const {
    return numElements;
}

template <typename T>
LinkedListIterator<T> LinkedList<T>::getHead() const {
    //LinkedListIterator<T> headIter = head;
    return head;
}

template <typename T>
T LinkedList<T>::getElem(LinkedListIterator<T> pos) {
    return pos->data;
}

template <typename T>
LinkedListIterator<T> LinkedList<T>::find(const T& value) {
    LinkedListIterator<T> iter = head;
    while (iter->next != nullptr) {
        if (value == iter->data) {
            return iter;
        }
        iter = iter->next;
    }

    return nullptr;
}

// ------- Mutator Functions ------- //

template <typename T>
void LinkedList<T>::setHead(LinkedListNode<T>* ptr) {
    head = ptr;
}

template <typename T>
void LinkedList<T>::clear() {
    LinkedListNode<T>* tmp;
    tmp = head->next;
    while (tmp != nullptr) {
        delete head;
        head = tmp;
        tmp = head->next;
    }
    numElements = 0;
    tmp = nullptr;
}

template <typename T>
void LinkedList<T>::erase(LinkedListIterator<T> iter) {
    // If node isn't sentinel.
    if (iter->next != nullptr) {
        LinkedListNode<T>* tmp = iter->next;
        iter->data = tmp->data;
        iter->next = tmp->next;
        delete tmp;
        tmp = nullptr;
        numElements--;
    }
}

template <typename T>
void LinkedList<T>::pushBack(const T& value) {
    LinkedListIterator<T> iter = head;
    while (iter->next != nullptr) {
        iter = iter->next;
    }
    insert(iter, value);
    iter = nullptr;
}

template <typename T>
void LinkedList<T>::popBack() {
    if (numElements > 0) {
        erase(head);
    }
}

template <typename T>
void LinkedList<T>::insert(LinkedListIterator<T> iter, const T& value) {
    LinkedListNode<T>* tmp = new LinkedListNode<T>;
    tmp->data = iter->data;
    tmp->next = iter->next;
    iter->data = value;
    iter->next = tmp;
    numElements++;
    tmp = nullptr;
}

template <typename T>
void LinkedList<T>::set(LinkedListIterator<T> iter, const T& value) {
    iter->data = value;
}

template <typename T>
void LinkedList<T>::remove(const T& value) {
    LinkedListIterator<T> iter = head;
    LinkedListNode<T>* temp = nullptr;

    while (iter->next != nullptr) {
        if (iter->data == value) {
            temp = iter;
            iter = iter->next;
            erase(temp);
            temp = nullptr;
        } else {
            iter = iter->next;
        }
    }

    iter = nullptr;
    temp = nullptr;
}

template <typename T>
LinkedList<T> LinkedList<T>::spliceAfter(LinkedListIterator<T> splicePoint) {
    LinkedList<T> newList = new LinkedList<T>;
    LinkedListIterator<T> iter = splicePoint;
    while (iter->next != nullptr) {
        newList.pushBack(iter->data);
    }
    iter = nullptr;
    return newList;
}