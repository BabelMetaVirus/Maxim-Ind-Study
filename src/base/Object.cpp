#include "Object.h"
int Object::currentID = 0;

Object::Object(void){
    this->id = Object::currentID++;
    this->objectType = "Object";
}
const int Object::ID(void) const{
    return this->id;
}
const std::string Object::Type(void) const{
    return this->objectType;
}
bool Object::Update(void){
    // Doesn't do anything.
    return true; 
}
void Object::Display(void) const{
    // This function is empty.
}