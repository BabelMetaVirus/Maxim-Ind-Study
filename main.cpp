// RFG: Random Fantasy Game.
#include "src/app/App.h"

int main() {
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
    return 0;    
}