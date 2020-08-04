// RFG: Random Fantasy Game.
#include "App.h"

int main() {
    App* theApp = App::GetInstance();

    theApp->Initialize();
    while(theApp->Run()){}
    theApp->Finalize();
    return 0;    
}