#include "App.h"
App* App::instance = nullptr;
int App::references = 0;

App::App(void){
    // TODO: Basic value setup here.
    this->message = "Created";
}
App* App::GetInstance(){
    // If the instance doesn't exist yet.
    if(App::instance == nullptr){
        // Allocate it.
        App::instance = new App();
    }
    // Return the pointer to the instance.
    App::references++;
    return App::instance;
}
// Start up the program.
// True if initialization happens. False if an error occurs.
bool App::Initialize(void){
    bool flag = true;
    this->message = "Initialized.";
    return flag;
}
// Run the program.
// True if the program is going to continue. False if it's ready to end.
bool App::Run(void){
    bool flag = true;
    static int cycle = 0;
    cycle++;
    this->message = "Run Cycle: " + std::to_string(cycle);
    flag = cycle <= 25;
    return flag;
}
// Close out the program.
// True if the program is closed out successfully. False otherwise.
bool App::Finalize(void){
    bool flag = true;
    this->message = "Finalized.";
    return flag;
}
// ReferenceCount: Return the number of references outstanding.
const int App::ReferenceCount(void){
    return App::references;
}
// Release: Release a reference to the instance.
void App::Release(void){
    App::references--;
    if(App::references == 0){
        delete App::instance;
    }
}
// Exists: Tell us if an application instance exists.
const bool App::Exists(void){
    return App::instance != nullptr;
}