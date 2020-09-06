#ifndef _APP_H_
#define _APP_H_
#include <iostream>
#include <string>

class App{
    private:
    static App* instance;
    std::string message;
    static int references;
    App(void);
    public:
    static App* GetInstance(void);
    // Start up the program.
    // True if initialization happens. False if an error occurs.
    bool Initialize(void);
    // Run the program.
    // True if the program is going to continue. False if it's ready to end.
    bool Run(void);
    // Get the message in our app.
    inline std::string GetMessage(void){return message;}
    // Close out the program.
    // True if the program is closed out successfully. False otherwise.
    bool Finalize(void);
    // ReferenceCount: Return the number of references outstanding.
    static const int ReferenceCount(void);
    // Release: Release a reference to the instance.
    void Release(void);
    // Exists: Tell us if an application instance exists.
    static const bool Exists(void);
};

#endif 