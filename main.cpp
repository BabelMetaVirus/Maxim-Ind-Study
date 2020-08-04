// RFG: Random Fantasy Game.
#include "App.h"

int main() {
    App* theApp = App::GetInstance();

    theApp->Initialize();
    do{
        std::cout << theApp->GetMessage() << std::endl;
    }while(theApp->Run());
    theApp->Finalize();
    return 0;    
}