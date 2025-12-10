#ifndef NODE_H
#define NODE_H
//Node class that represents a single node in a linked list
class Node {
    public:
        int data;
        Node* nextNode;
        Node(int data_, Node* nextNode_){
            data = data_;
            nextNode = nextNode_;
        };  
};
#endif