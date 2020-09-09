#ifndef _TESTS_H_
#define _TESTS_H_
#include <iostream>
#include "../collection/List.h"

bool TestIntList(void){
    Collection::List<int> number_list;
    std::cout << "Testing head insertion..." << std::endl;
    for(int i = 1; i < 12; i++){
        std::cout << "Inserting number " << i << " at head." << std::endl; 
        number_list.AddHead(i);
    }
    std::cout << "Testing size count..." << std::endl;
    if(number_list.Size() == 11){
        std::cout << "Size count is correct.\n";
    }
    else{
        std::cout << "Size count is incorrect.\n";
    }
    std::cout << "Testing tail insertion...\n";
    for(int i = 12; i < 21 ; i++){
        std::cout << "Inserting number " << i << " at tail.\n";      
        number_list.AddTail(i);  
    }
    std::cout << "Testing size count...\n";
    if(number_list.size() == 20){
        std::cout << "Size count is correct.\n";
    }
    else{
        std::cout << "Size count is incorrect.\n";
    }
    int sum = 0;
    std::cout << "Iterating list for summation...\n";
}
#endif