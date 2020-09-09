#ifndef _LIST_H_
#define _LIST_H_
// NOTE: Show how to do assignment without destroying the list entirely.
namespace Collection{
    template<typename T>
    class DoubleNode : public Node<T>{
        public:
        DoubleNode* prev;
        DoubleNode* next;
        DoubleNode(const T& _obj) : Node<T>(_obj){
            this->prev = nullptr;
            this->next = nullptr;
        }
    };

    template<typename T>
    class List : public Container{
        private:
        typedef DoubleNode<T> ListNode;
        ListNode* head;
        ListNode* tail;
        protected:
        using Container::Capacity;
        using Container::Resize;
        using Container::Shrink;
        using Container::Full;
        public:
        class Iterator{
            private:
            ListNode* current;
            bool IsValid(void){return this->current != nullptr;}
            public:
            Iterator(void){
                this->current = nullptr;
            }
            Iterator& operator=(ListNode* _ptr){
                this->current = _ptr;
            }
            const bool operator==(ListNode* _ptr) const{
                return this->current == _ptr;
            }
            Iterator& operator++(int){
                Iterator copy = *this;
                if(this->IsValid()){
                    this->current = this->current->next;
                }
                return copy;
            }
            Iterator& operator++(void){
                if(this->IsValid()){
                    this->current = this->current->next;
                }
                return *this;
            }
            const T operator*(void) const{
                T ret;
                if(this->IsValid()){
                    ret = this->current->data;
                }
                return ret;
            }
        };
        // Collection::List::Iterator
        // NOTE: We're going to create a reverse iterator later.
        List(void){
            this->head = nullptr;
            this->tail = nullptr;
            this->Resize(Container::CapacityInvalid);
            this->type = "List";
        }

        ~List(void){
            while(this->head != nullptr){
                ListNode* tmp = this->head;
                this->head = tmp->next;
                delete tmp;
            }
        }

        List(const List& _src){
            this->head = nullptr;
            this->tail = nullptr;
            this->Resize(Container::CapacityInvalid);
            this->type = "List";
            ListNode* current = nullptr;
            for(it = _src.Begin(); it != _src.End(); it++){
                ListNode* newNode = new ListNode(*it);
                if(this->IsEmpty()){head = newNode;}
                else{current->next = newNode;}
                newNode->prev = current;
                current = newNode;
                this->Add();
            }
            tail = current;
        }

        List& operator=(const List& _src){
            if(&_src != this){
                while(this->head != nullptr){
                    ListNode* tmp = this->head;
                    this->head = tmp->next;
                    delete tmp;
                }
                this->head = nullptr;
                this->tail = nullptr;
                this->Resize(Container::CapacityInvalid);
                this->type = "List";
                ListNode* current = nullptr;
                for(it = _src.Begin(); it != _src.End(); it++){
                    ListNode* newNode = new ListNode(*it);
                    if(this->IsEmpty()){head = newNode;}
                    else{current->next = newNode;}
                    newNode->prev = current;
                    current = newNode;
                    this->Add();
                }
                tail = current;
            }
            return *this;
        }

        ListNode* Begin(void){return this->head;}

        ListNode* End(void){return nullptr;}
        const T PeekHead(void) const{
            T ret;
            if(!this->IsEmpty()){ret = this->head->data;}
            return ret;
        }
        const T PeekTail(void) const{
            T ret;
            if(!this->IsEmpty()){ret = this->tail->data;}
            return ret;
        }
        bool AddHead(const T& _obj){
            ListNode* newNode = new ListNode(_obj);
            
            if(newNode == nullptr){return false;}

            newNode->next = this->head;

            if(!this->IsEmpty()){
                this->head->prev = newNode;
            }
            else{
                this->tail = newNode;
            }

            this->head = newNode;
            this->Add();
            return true;
        }
        
        bool AddTail(const T& _obj){
            // Create New Node
            ListNode* last = new ListNode(_obj);
            // Make sure the memory is allocated. (FAIL)
            if (last == nullptr){
                return false;
            }// Attach the node to the tail.
            last->prev = tail;
            // If the list is empty.
            if (this->IsEmpty()){
                // Store the new node in the head.
                this->head = last;
            } 
            // Otherwise...
            else{
                // Attach the tail to the new node.
                this->tail->next = last;
            }
            // Store the new node as the tail.
            this->tail = last;
            // Add to the count.
            this->Add();
            // SUCCEED
            return true;
        }
        bool RemoveHead(void){
            // If the list is empty, FAIL
            if(this->IsEmpty()){return false;}
            // Temporary pointer to the head (current)
            ListNode* tmp = this->head;
            // Set the head to the next pointer of the current head.
            this->head = tmp->next;
            // If the head is now the null pointer, we set the tail equal to 
            // the null pointer.
            if(this->head){
                this->head->prev = nullptr;
            }
            else{
                this->tail = nullptr;
            }
            // Delete the temporary node.
            delete tmp;
            // Reduce the size by 1.
            this->Remove();
            // SUCCEED
            return true;
        }
        bool RemoveTail(void){
            // If the list is empty, FAIL
            if(this->IsEmpty()){return false;}
            // Otherwise, we'll remove the tail node.
            ListNode* tmp = this->tail;
            // Set the tail to the prev pointer of the current tail.
            this->tail = tmp->prev;
            //
            if(this->tail){
                this->tail->next = nullptr;
            }
            else{
                this->head = nullptr;
            }
            // Delete the temporary node.
            delete tmp;
            // Reduce size by 1.
            this->Remove();
            // SUCCEED
            return true;
        }
    }
};
#endif