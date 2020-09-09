#ifndef _STACK_H_
#define _STACK_H_
#include "List.h" 

namespace Collection{
    template <typename T>
    class Stack : protected List<T>{
        public:
        using List<T>::Size;
        using List<T>::IsEmpty;
        using List<T>::GetType;
        using List<T>::GetID;
        Stack(void){
            this->type = "Stack";
        }
        bool Push(const T& _obj){
            return this->AddHead(_obj);
        }
        T Peek(void){
            T data = this->PeekHead();
            return data;
        }
        bool Pop(void){
            return this->RemoveHead();
        }
    };
};

#endif
