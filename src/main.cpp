#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "event.h"
#include "linked_list.hpp"
#include "skip_list.hpp"

int main() {
    srand(time(NULL));
    /*
    Event eventArr[100];
    for (int i = 0; i < 100; i++) {
        Event ev("event" + std::to_string(i), 5, 59);
        eventArr[i] = ev;
    }

    for (int i = 0; i < 100; i++) {
       std::cout << eventArr[i] << "\n" << std::endl;
    }


    LinkedList<Event> L1;
    for (int i = 0; i < 100; i++) {
        Event ev("event" + std::to_string(i), 20, 22);
        L1.pushBack(ev);
    }
    
    //std::cout << L1.getElem(L1.getHead()) << std::endl;
    // std::cout << L1.getElem(L1.getHead()+100) << std::endl;
    
    std::cout << "start of printing list" << std::endl;
    for (int i = 0; i < 100; i++) {  
        std::cout << L1.getElem(L1.getHead()+i) << "\n" << std::endl;
    }   
    
    std::cout << "hello world" << std::endl;
    */


    
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
                    benchmarkFile = std::ifstream("../benchmarks/large_inputs/_ascend.txt");
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
    
    
    // Creating a tester LinkedList.
    LinkedList<Event> testerLinkedList;

    // Creating a tester SkipList.
    int maxLevelsSkipList = 3;
    SkipList<Event> testerSkipList(maxLevelsSkipList);
    
    // Reading in all events from benchmark file and inserting in both lists.
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


    std::cout << "\n--------------- Finding Specific Element ---------------" << std::endl;

    // Details of event to be found in lists. (Is adjusted based on which benchmark file chosen)
    const std::string eventToBeFoundName = "EventToBeFound";
    int eventToBeFoundTimeStamp;

    std::cout << "\nEnter search Event's minute timestamp: ";
    std::cin >> eventToBeFoundTimeStamp;

    // Creating an object of the event to be found. 
    Event eventToBeFound(eventToBeFoundName, eventToBeFoundTimeStamp);

    // Searching both lists for eventToBeFound.
    LinkedListIterator<Event> eventToBeFoundPos_LinkedList = testerLinkedList.find(eventToBeFound);
    SkipListNode<Event>* eventToBeFoundPos_SkipList = testerSkipList.find(eventToBeFound);

    std::cout << "\nLinked List Element Display:" << std::endl;
    testerLinkedList.getElem(eventToBeFoundPos_LinkedList).printDetails();

    std::cout << "\nSkip List Element Display:" << std::endl;
    testerSkipList.getElem(eventToBeFoundPos_SkipList).printDetails();
    




    return 0;
}