#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"
#include <iostream>

class BinaryTree{
    Node* root;
    BinaryTree(Node* root_){
        this->root = root_;
    }
    BinaryTree(int root_){
        this->root = new Node(root_);
    }
    BinaryTree(){
        this->root = nullptr;
    }
    void ins(int insertee, Node* curr){
        //If tree is empty
        if(curr == nullptr){
            this->root = new Node(insertee);
        }
        if(insertee >= curr->data && curr->Right != nullptr){
            ins(insertee, curr->Right);
        }else if(insertee >= curr->data && curr->Right == nullptr){
            curr->Right = new Node(insertee);
            return;
        }else if(insertee < curr->data && curr->Left != nullptr){
            ins(insertee, curr->Left);
        }else{
            curr->Left = new Node(insertee);
            return;
        }
    }
    void del(){}
    Node* search(int searchee, Node* curr){
        //Base Cases
        if(curr == nullptr){
            return nullptr;
        }
        if(curr->data == searchee){
            return curr;
        }
        if(searchee < curr->data){
            search(searchee, curr->Left);
        }else{
            search(searchee, curr->Right);
        }
    }
    void inorder(){}

};

#endif