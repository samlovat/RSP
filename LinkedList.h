// Linked List Class
#include "Node.h"
#include <iostream>

class LinkedList {
    public:
        Node* Head;
        LinkedList(Node* Head_){
            this->Head = Head_;
        }
        LinkedList(){
            this->Head = nullptr;
        };
        void del(int deletee){};
        void ins(int insertee){
            Node* newNode = new Node(insertee, this->Head);
            this->Head = newNode;
        };
        Node* search(int searchee, Node* curr){
            //Base Case
            if(curr->nextNode == nullptr){
                return nullptr;
            }
            if(curr->data == searchee){
                return curr;
            }
            return this->search(searchee, curr->nextNode);
        };
        void print(Node* curr){
            if(curr->nextNode == nullptr){
                return;
            }
            std::cout << curr->data << " | " << std::endl;
            print(curr->nextNode);
            return;
        }
};