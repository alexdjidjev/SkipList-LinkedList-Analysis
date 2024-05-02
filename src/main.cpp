// FILE CONTAINS: LinkedList and SkipList objects
// where data from the benchmark files is inputted 
// and tested.


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "event.h"
#include "linked_list.hpp"
#include "skip_list.hpp"


int main() {
    srand(time(NULL));

    // ------- INPUT BENCHMARK FILE TYPES ------- //

	/*
	// ------ 3 Size Options ------ //
		- small (71 elements) 	('S')
		- medium (143 elements) ('M')
		- large (719 elements) 	('L')

	// ------ 3 Sortedness Options ------ //
		- sorted ascending 	('A')
		- random 			('R')
		- sorted descending ('D')
	*/

    // NOTE: Each "event" or element that will be stored in the 
    // lists from the input files will be named in this format: 
    // 
    // TEST_<SIZE>_<SORTEDNESS>_<EVENT NUM>, <TIMESTAMP IN MINUTES>.
    // 
    // e.g. An element from the small random .txt file with an event
    // number of 39 and timestamp of 120 minutes will be named as follows: 
    // 
    // TEST_S_R_39, 120

    std::ifstream benchmarkFile;
    char benchmarkSize;
    char benchmarkSort;

    std::cout << "CHOOSE BENCHMARK SIZE\n"
    << "Small = 'S' | Medium = 'M' | Large = 'L'\n"
    << "Size: ";
    std::cin >> benchmarkSize;

    std::cout << "CHOOSE BENCHMARK SORTEDNESS\n"
    << "Ascending = 'A' | Random = 'R' | Descending = 'D'\n"
    << "Sortedness: ";
    std::cin >> benchmarkSort;

    // Assigning correct input file path to 'benchmarkFile'. 
    switch (benchmarkSize)
    {
        case 'S':
            switch (benchmarkSort)
            {
                case 'A':
                    benchmarkFile = std::ifstream("../benchmarks/small_inputs/s_ascend.txt");
                    break;
                
                case 'R':
                    benchmarkFile = std::ifstream("../benchmarks/small_inputs/s_random.txt");
                    break;

                case 'D':
                    benchmarkFile = std::ifstream("../benchmarks/small_inputs/s_descend.txt");
                    break;
                
                default:
                    std::cout << "Did not choose a valid sortedness!" << std::endl;
                    break;
                }
            break;

        case 'M':
            switch (benchmarkSort)
            {
                case 'A':
                    benchmarkFile = std::ifstream("../benchmarks/medium_inputs/m_ascend.txt");
                    break;

                case 'R':
                    benchmarkFile = std::ifstream("../benchmarks/medium_inputs/m_random.txt");
                    break;

                case 'D':
                    benchmarkFile = std::ifstream("../benchmarks/medium_inputs/m_descend.txt");
                    break;
                
                default:
                    std::cout << "Did not choose a valid sortedness!" << std::endl;
                    break;
                }        
            break;

        case 'L':
            switch (benchmarkSort)
            {
                case 'A':
                    benchmarkFile = std::ifstream("../benchmarks/large_inputs/l_ascend.txt");
                    break;
                
                case 'R':
                    benchmarkFile = std::ifstream("../benchmarks/large_inputs/l_random.txt");
                    break;

                case 'D':
                    benchmarkFile = std::ifstream("../benchmarks/large_inputs/l_descend.txt");
                    break;
                
                default:
                    std::cout << "Did not choose a valid sortedness!" << std::endl;
                    break;
                }        
            break;
        
        default:
            std::cout << "Did not choose a valid benchmark size!" << std::endl;
            break;
    }
    

// ----------------------- Start of List Creation and Testing ----------------------- //  
 

    // Creating a tester LinkedList.
    LinkedList<Event> testerLinkedList;

    // Creating a tester SkipList.
    int maxLevelsSkipList = 5;
    SkipList<Event> testerSkipList(maxLevelsSkipList);
    
    // Reading in all events from benchmark file and INSERTING in both lists.
    Event insertionEvent;
    while (benchmarkFile >> insertionEvent) {
        testerLinkedList.insertInAscndOrder(insertionEvent);
        testerSkipList.insert(insertionEvent);
    }
    
    // Displaying linked list elements.
    std::cout << "\n############################\n## DISPLAYING LINKED LIST ##\n############################" << std::endl;
    testerLinkedList.print();

    // Displaying skip list elements.
    std::cout << "\n##########################\n## DISPLAYING SKIP LIST ##\n##########################" << std::endl;
    for (int i = 0; i < maxLevelsSkipList; i++) {
        std::cout << std::endl;
        testerSkipList.printOnLevel(i+1);
    }

    // Displaying number of elements on each level in the SkipList.
    for (int i = 0; i < maxLevelsSkipList; i++) {
        std::cout << "\n#########################################" << std::endl;
        std::cout << "## Number of Elements on Level " << i+1 << " = " << testerSkipList.numElemsOnLevel(i+1) << " ##" << std::endl;
        std::cout << "#########################################" << std::endl;
    }

    std::cout << "\n--------------- Finding Specific Element ---------------" << std::endl;

    // Details of event to be found in lists. (Is adjusted based on which benchmark file chosen)
    const std::string eventToBeFoundName = "EventToBeFound";
    int eventToBeFoundTimeStamp;

    std::cout << "\nEnter search Event's minute timestamp: ";
    std::cin >> eventToBeFoundTimeStamp;

    // Creating an object of the event to be found. 
    Event eventToBeFound(eventToBeFoundName, eventToBeFoundTimeStamp);

    // SEARCHING BOTH LISTS for eventToBeFound.
    LinkedListIterator<Event> eventToBeFoundPos_LinkedList = testerLinkedList.find(eventToBeFound);
    SkipListNode<Event>* eventToBeFoundPos_SkipList = testerSkipList.find(eventToBeFound);

    std::cout << "\nLinked List Element Display:" << std::endl;
    testerLinkedList.getElem(eventToBeFoundPos_LinkedList).printDetails();

    std::cout << "\nSkip List Element Display:" << std::endl;
    testerSkipList.getElem(eventToBeFoundPos_SkipList).printDetails();
    

    return 0;
}