#ifndef NODE_H
#define NODE_H

class Node{
    public:
        int data;
        Node* Left;
        Node* Right;
        Node* Parent;
        Node(int data_){
            this->data = data_;
            this->Left = nullptr;
            this->Right = nullptr;
            this->Parent = nullptr;
        }
        Node(int data_, Node* parent_){
            this->data = data_;
            this->Left = nullptr;
            this->Right = nullptr;
            this->Parent = parent_;
        }
};

#endif