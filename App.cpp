#include "App.h"
App* App::instance = nullptr;

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
    std::cout << message << std::endl;
    return flag;
}
// Run the program.
// True if the program is going to continue. False if it's ready to end.
bool App::Run(void){
    bool flag = true;
    static int cycle = 0;
    cycle++;
    message = "Run Cycle: " + std::to_string(cycle);
    flag = cycle <= 25;
    return flag;
}
// Close out the program.
// True if the program is closed out successfully. False otherwise.
bool App::Finalize(void){
    bool flag = true;
    std::cout << "Finalized." << std::endl;
    return flag;
}