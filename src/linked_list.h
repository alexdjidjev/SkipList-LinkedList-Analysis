#ifndef LINKED_LIST_H
#define LINKED_LIST_H


template <typename T>
class LinkedListNode {
    public:
        T data;
        LinkedListNode<T>* next;
};

template <typename T>
class LinkedListIterator {
    public:
        // Constructors
		LinkedListIterator() {};
        LinkedListIterator(LinkedListNode<T>* p);

        // De-reference Operator Overload
        LinkedListNode<T>& operator*();

        // Arrow Operator Overload
        LinkedListNode<T>* operator->();

        // Addtion Operator Overload
        LinkedListNode<T>* operator+(const int increment);

        // Desc: Returns true if ptr equals nullptr. 
        bool isNull();

    private:
        LinkedListNode<T>* ptr;

};

template <typename T>
class LinkedList {
    public:
        
        // Constructor
        LinkedList();

        // Destructor
        ~LinkedList();

        // Assignment Operator Overload
        LinkedList<T>& operator=(const LinkedList<T>& rhs);

        // Copy Constructor
        LinkedList(const LinkedList<T>& rhs);

    // ------- Accessor Functions ------- //

        // Desc: Returns current size of list.
        int getSize() const;

        // Desc: Returns pointer to head node.
        LinkedListIterator<T> getHead() const;

        // Desc: Returns the data stored at node pointed to be 'pos'.
        T getElem(LinkedListIterator<T> pos);

        // Desc: Returns iterator to first node containing 'value'.
        // Returns nullptr if 'value' isn't in the list.
        LinkedListIterator<T> find(const T &value);

    // ------- Mutator Functions ------- //

        // Desc: Sets head of list to ptr.
        void setHead(LinkedListNode<T> *ptr);

        // Desc: Deletes every LinkedListNode, sets size to 0.
        void clear();

        // Desc: Removes element at position pointed to by 'iter'.
        void erase(LinkedListIterator<T> iter);

        // Desc: Inserts 'value' to the tail of the list.
        void pushBack(const T& value);

        // Desc: Erases value at the head of the list if size > 0.
        void popBack();

        // Desc: Inserts 'value' to the position pointed to by 'iter'
        // Post: Inserted value will come before element pointed to by 'iter'.
        void insert(LinkedListIterator<T> iter, const T& value);

        // Desc: Set element pointed to by 'iter' to 'value'.
        void set(LinkedListIterator<T> iter, const T& value);

        // Desc: Removes all elements in list that are equal to 'value'.
        // Post: If list is size 0, then no change.
        void remove(const T& value);

        // Desc: Returns a new list with all elements at and after the splicePoint in calling list object.
        LinkedList<T> spliceAfter(LinkedListIterator<T> splicePoint);
        
    private:
        LinkedListNode<T>* head = nullptr;
        int numElements;

};




//#include "linked_list.hpp"
#endif