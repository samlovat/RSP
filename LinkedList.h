#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
// Linked List Class
class LinkedList {
    public:
        Node* Head;
        LinkedList(Node* Head_){
            this->Head = Head_;
        }
        LinkedList(int headValue){
            this->Head = new Node(headValue, nullptr);
        };
        LinkedList(){
            this->Head = nullptr;
        };
        Node* searchForPredecessor(int searchee, Node* curr){
            //Base Case
            if(curr->nextNode == nullptr){
                return nullptr;
            }
            if(curr->nextNode->data == searchee){
                return curr;
            }
            return this->searchForPredecessor(searchee, curr->nextNode);
        };
        void del(int deletee){
            if(this->Head != nullptr){
                if(this->Head->data == deletee){
                    Node* temp = this->Head;
                    if(this->Head->nextNode != nullptr){
                        this->Head = temp->nextNode;
                    }
                    delete temp;
                    return;
                }
            }else{
                return;
            }
            Node* pred = searchForPredecessor(deletee, this->Head);
            
            if(pred == nullptr){
                std::cerr << "Node doesn't exist" << std::endl;
                return;
            }
            std::cout << "pred: " << pred->data << std::endl;
            Node* temp = pred->nextNode;
            if(temp->nextNode != nullptr){
                pred->nextNode = temp->nextNode;
            }
            delete temp;
            return;
        };
        void ins(int insertee){
            Node* newNode = new Node(insertee, this->Head);
            this->Head = newNode;
        };
        Node* search(int searchee, Node* curr){
            //Base Case
            if(curr->data == searchee){
                return curr;
            }
            if(curr->nextNode == nullptr){
                return nullptr;
            }
            return this->search(searchee, curr->nextNode);
        };
        void print(Node* curr){
            std::cout << curr->data << " | ";
            if(curr->nextNode == nullptr){
                return;
            }
            print(curr->nextNode);
            return;
        }
};
#endif