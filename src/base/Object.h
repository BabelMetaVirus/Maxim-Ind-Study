#ifndef _OBJECT_H_
#define _OBJECT_H_
#include <string>

class Object{
    private:
    static int currentID;
    int id;
    protected:
    std::string objectType;
    public:
    Object(void);
    const int ID(void) const;
    const std::string Type(void) const;
    virtual bool Update(void);
    virtual void Display(void) const;
}
#endif