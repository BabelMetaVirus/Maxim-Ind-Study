#include "App.h"
App* App::instance = nullptr;
const int App::max_default = 100;
const int App::min_default = 1;

App::App(void){
    // TODO: Basic value setup here.
    message = "Created";
}
App* App::GetInstance(){
    // If the instance doesn't exist yet.
    if(instance == nullptr){
        // Allocate it.
        instance = new App();
    }
    // Return the pointer to the instance.
    return instance;
}
// Start up the program.
// True if initialization happens. False if an error occurs.
bool App::Initialize(void){
    bool flag = true;
    min = min_default;
    max = max_default;
    current = min;
    std::cout << message << std::endl;
    message = "Initialized";
    std::cout << message << std::endl;
    return flag;
}
// Run the program.
// True if the program is going to continue. False if it's ready to end.
bool App::Run(void){
    bool flag = true;
    bool div3 = current % 3 == 0;
    bool div8 = current % 8 == 0;
    
    if(div3){
        std::cout << "Fizz";
    }

    if(div8){
        std::cout << "Slag";
    }

    if(!div3 && !div8){
        std::cout << current;
    }
    std::cout << std::endl;
    current++;
    flag = current <= max;
    return flag;
}
// Close out the program.
// True if the program is closed out successfully. False otherwise.
bool App::Finalize(void){
    bool flag = true;
    std::cout << "Finalized." << std::endl;
    return flag;
}