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

        SkipListNode<T>* find(const T& value) const;

        T getElem(const SkipListNode<T>* pos) const;

        void printOnLevel(const int level = 1) const;

    // ------- Mutator Functions ------- //

        void insert(const T& value);

        void erase(const SkipListNode<T>* pos);

    private:
        SkipListNode<T>* head = nullptr;
        int numElements;
        int maxLevels;
};

#endif