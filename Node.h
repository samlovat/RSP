#ifndef NODE_H
#define NODE_H

class Node{
    public:
        int data;
        Node* Left;
        Node* Right;
        Node(int data_){
            this->data = data_;
            this->Left = nullptr;
            this->Right = nullptr;
        }
};

#endif