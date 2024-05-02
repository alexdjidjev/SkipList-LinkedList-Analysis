#ifndef SKIP_LIST_H
#define SKIP_LIST_H

template <typename T>
class SkipListNode {
    public:
        T data;
        int numLevels;
        SkipListNode<T>** next;
};

template <typename T>
class SkipList {
    public:
        // Constructor
        SkipList(const int& maxLevels);

        // Destructor
        ~SkipList();

        // Assignment Operator Overload
        SkipList<T>& operator=(const SkipList<T>& rhs);

        // Copy Constructor
        SkipList(const SkipList<T>& rhs);

    // ------- Accessor Functions ------- //

        // Desc: Returns a SkipListNode<T> pointer to node storing 'value'.
        // Prints out 'Value in SkipList NOT FOUND!' if no node stored 'value'.
        SkipListNode<T>* find(const T& value) const;

        // Desc: Returns the value of the element being stored 
        // in the node pointed to by 'pos'.
        T getElem(const SkipListNode<T>* pos) const;

        // Desc: Prints all elements on the 'level' of the SkipList.
        void printOnLevel(const int level = 1) const;

        // Desc: Returns the number of elements on the 'level' of the SkipList. 
        int numElemsOnLevel(const int level) const;

    // ------- Mutator Functions ------- //

        // Desc: Creates a new node that stores 'value' and inserts it in
        // correct spot to maintain ascending order of SkipList.
        void insert(const T& value);

        // Desc: Removes the node pointed to by 'pos'.
        void erase(const SkipListNode<T>* pos);

        // Desc: Removes all elements from the SkipList.
        void clear();

    private:
        SkipListNode<T>* head = nullptr;
        int numElements;
        int maxLevels;
        float coinProbability = 0.5;
};

#endif