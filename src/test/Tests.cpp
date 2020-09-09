#include "Tests.h"
bool TestApp(void){
    App* theApp = App::GetInstance();
    std::cout << "Instance Count: " << App::ReferenceCount() << std::endl;
    
    App* theApp1 = App::GetInstance();
    App* theApp2 = App::GetInstance();
    App* theApp3 = App::GetInstance();
    std::cout << "Instance Count: " << App::ReferenceCount() << std::endl;
    if(theApp == theApp3){
        std::cout << "Hey, the singleton works!" << std::endl;
    }
    theApp1->Release();
    theApp2->Release();
    std::cout << "Instance Count: " << App::ReferenceCount() << std::endl;

    theApp->Initialize();
    std::cout << theApp->GetMessage() << std::endl;
    do{
        std::cout << theApp->GetMessage() << std::endl;
    }while(theApp->Run());
    theApp->Finalize();
    std::cout << theApp->GetMessage() << std::endl;
    

    while(App::ReferenceCount() != 0){
        std::cout << "Instance Count: " << App::ReferenceCount() << std::endl;
        theApp->Release();
    }
    return true;
}
bool TestIntList(void){
    Collection::List<int> number_list;
    std::cout << "Type of number_list: " << number_list.GetType() << std::endl;
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
        return false;
    }
    std::cout << "Testing tail insertion...\n";
    for(int i = 12; i < 21 ; i++){
        std::cout << "Inserting number " << i << " at tail.\n";      
        number_list.AddTail(i);  
    }
    std::cout << "Testing size count...\n";
    if(number_list.Size() == 20){
        std::cout << "Size count is correct.\n";
    }
    else{
        std::cout << "Size count is incorrect.\n";
        return false;
    }
    int sum = 0;
    std::cout << "Iterating list for summation...\n";
    for(Collection::List<int>::Iterator it = number_list.Begin(); it != number_list.End(); it++){
        sum += *it;
    }
    if(sum == 210){
        std::cout << "Sum is correct.\n";
    }
    else{
        std::cout << "Sum is incorrect.\n";
        return false;
    }
    std::cout << "Outputting list contents...\n";
    for(Collection::List<int>::Iterator it = number_list.Begin(); it != number_list.End(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Testing removing from head...\n";
    for(int i = 0; i < 6; i++){
        int val = number_list.PeekHead();
        std::cout << "Current Head is: " << val << std::endl;
        number_list.RemoveHead();
        val = number_list.PeekTail();
        std::cout << "Current Tail is: " << val << std::endl;
        number_list.RemoveTail();
    }
    if(number_list.Size() == 8){
        std::cout << "Successfully removed 12 objects.\n";
    }
    else{
        std::cout << "Count mismatch error.\n";
        return false;
    }
    int count = 0;
    while(!number_list.IsEmpty()){
        count++;
        std::cout << "Removing element " << count << std::endl;
        number_list.RemoveHead();
    }
    if(number_list.Size() == 0){
        std::cout << "List is empty.\n";
    }
    else{
        std::cout << "List is not empty.\n";
        return false;
    }
    return true;
}
bool TestIntStack(void){
    Collection::Stack<int> number_list;
    std::cout << "Type of number_list: " << number_list.GetType() << std::endl;
    std::cout << "Testing insertion..." << std::endl;
    for(int i = 1; i < 21; i++){
        std::cout << "Inserting number " << i << "." << std::endl; 
        number_list.Push(i);
    }
    std::cout << "Testing size count..." << std::endl;
    if(number_list.Size() == 20){
        std::cout << "Size count is correct.\n";
    }
    else{
        std::cout << "Size count is incorrect.\n";
        return false;
    }
    int count = 0;
    while(!number_list.IsEmpty()){
        std::cout << "Top stack element is " << number_list.Peek() << std::endl;
        std::cout << "Popping top stack element.\n";
        number_list.Pop();
        count++;
    }
    if(count != 20){
        std::cout << "Failed to remove all assigned elements.\n";
        return false;
    }
    else{
        std::cout << "Stack successfully emptied.\n";
    }
    return true;
}
bool TestIntQueue(void){
    Collection::Queue<int> number_list;
    std::cout << "Type of number_list: " << number_list.GetType() << std::endl;
    std::cout << "Testing insertion..." << std::endl;
    for(int i = 1; i < 21; i++){
        std::cout << "Inserting number " << i << "." << std::endl; 
        number_list.Push(i);
    }
    std::cout << "Testing size count..." << std::endl;
    if(number_list.Size() == 20){
        std::cout << "Size count is correct.\n";
    }
    else{
        std::cout << "Size count is incorrect.\n";
        return false;
    }
    int count = 0;
    while(!number_list.IsEmpty()){
        std::cout << "Top queue element is " << number_list.Peek() << std::endl;
        std::cout << "Popping top queue element.\n";
        number_list.Pop();
        count++;
    }
    if(count != 20){
        std::cout << "Failed to remove all assigned elements.\n";
        return false;
    }
    else{
        std::cout << "Stack successfully emptied.\n";
    }
    return true;
}