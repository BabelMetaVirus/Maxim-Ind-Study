#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "List.h"
namespace Collection{
    template <typename T>
    class Queue : protected List<T>{
        public:
        using List<T>::Size;
        using List<T>::IsEmpty;
        using List<T>::GetType;
        using List<T>::GetID;
        Queue(void){
            this->type = "Queue";
        }
        bool Push(const T& _obj){
            return this->AddTail(_obj);
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