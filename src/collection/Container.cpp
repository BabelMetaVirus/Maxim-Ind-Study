#include "Container.h"
namespace Collection{
    int Container::currentID = 0;
    const int Container::CapacityInvalid = -1;
    void Container::Add(void){
        if(size < capacity || capacity == Container::CapacityInvalid){this->size += 1;}
    }
    void Container::Remove(void){
        if(size > 0){this->size -= 1;}
    }
    void Container::Resize(int _cap){
        if(_cap > 0 || _cap == -1){this->capacity = _cap;}
    }
    void Container::Shrink(int _cap){
        if(_cap > 0){this->capacity = _cap;}
        if(this->size > this->capacity){this->size = _cap;}
    }
    Container::Container(void){
        this->size = 0;
        this->capacity = 0;
        this->type = "Error";
        this->id = Container::currentID++;
    }
    const int Container::Size(void) const{
        return this->size;
    }
    const bool Container::IsEmpty(void) const{
        return this->size == 0;
    }
    const bool Container::Full(void) const{
        return this->size == this->capacity;
    }
    const int Container::Capacity(void) const{
        return this->capacity;
    }
    const int Container::GetID(void) const{
        return this->id;
    }
    const std::string Container::GetType(void) const{
        return this->type;
    }
};