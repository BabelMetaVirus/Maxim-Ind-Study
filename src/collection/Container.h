#ifndef _CONTAINER_H_
#define _CONTAINER_H_
#include <string>

namespace Collection{
    template<typename T>
    class Node{
        public:
        T data;
        Node(const T& _obj){
            this->data = _obj;
        }
    };

    class Container{
        private:
        static int currentID; // Store the identity of each container.
        int size; // Size of the container (objects stored).
        int capacity; // Capacity for the container (objects total available).
        int id; // Identifier for the container.
        protected:
        std::string type; // Holds the type of the container we are using.
        void Add(void);
        void Remove(void);
        virtual void Resize(int _cap);
        virtual void Shrink(int _cap);
        public:
        static const int CapacityInvalid;
        Container(void);
        virtual ~Container(void){};
        const int Size(void) const;
        const bool IsEmpty(void) const;
        const bool Full(void) const;
        const int Capacity(void) const;
        const int GetID(void) const;
        const std::string GetType(void) const;
    };
};
#endif