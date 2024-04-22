#include <iostream>
#include "event.h"
#include "linked_list.hpp"

int main() {

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


    return 0;
}