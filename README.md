## SkipList-LinkedList-Analysis
This program is an analysis of the **LinkedList** and **SkipList** data structure implementations and the performance of important operations of each list. The scenario of a daily event scheduler application is used, where every element in each list is an event object with a name and time attribute. 

The operations performed on the two lists will consist of 
* inserting event objects from a pre-existing dataset in ascending order based on their time of occurrence and
* searching for a specified event based, once again, on the time attribute.

The **insert** and **find** procedures are analyzed both analytically and empirically with consideration to the time-complexity of the operations. The implementation of the data structures will be in C++ and the empirical testing will use the Valgrind Callgrind profiler.

`benchmarks` contains the pre-existing datasets used to test the lists' operations and cpp source files used to generate them.

`src` contains LinkedList and SkipList class implementations along with `main` which executes the desired list operations.

For running the main program, in `src` directory compile needed files using `$ g++ main.cpp event.cpp linked_list.hpp skip_list.hpp -o main.out`. Then run `$ ./main.out`.
