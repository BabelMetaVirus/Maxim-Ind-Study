#ifndef _APP_H_
#define _APP_H_
#include <iostream>
#include <string>

class App{
    private:
    static App* instance;
    std::string message;
    int min;
    int max;
    int current;
    static const int min_default;
    static const int max_default;
    App(void);
    public:
    static App* GetInstance(void);
    // Start up the program.
    // True if initialization happens. False if an error occurs.
    bool Initialize(void);
    // Run the program.
    // True if the program is going to continue. False if it's ready to end.
    bool Run(void);
    // Close out the program.
    // True if the program is closed out successfully. False otherwise.
    bool Finalize(void);
};

#endif 