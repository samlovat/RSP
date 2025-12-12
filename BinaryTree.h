#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"
#include <iostream>

class BinaryTree{
    public:
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
                curr->Right = new Node(insertee, curr);
                return;
            }else if(insertee < curr->data && curr->Left != nullptr){
                ins(insertee, curr->Left);
            }else{
                curr->Left = new Node(insertee, curr);
                return;
            }
        }
        Node* findSmallestSuccessor(Node* curr){    //For deletion when deletee has 2 children
            Node* minNode = curr;                       //call this function on right subtree of deletee
            if(curr->Left == nullptr){
                return minNode;
            }
            return findSmallestSuccessor(curr->Left);
        }
        void del(int deletee, Node* curr){
            int isRoot = 0;
            int smallerThanPar = 0;
            Node* parentNewChild = nullptr;
            //If Tree is empty or deletee doesn't exist
            if(curr == nullptr){
                return;
            }
            //If the deletee is the tree's root
            if(curr->data == deletee){
                if(curr->Parent == nullptr){     //This is root node
                    isRoot = 1;
                }
                if(isRoot == 0){                        //Only need to query parent if deletee is not root
                    if(deletee < curr->Parent->data){   //Checking relationship of deletee with Parent
                        smallerThanPar = 1;
                    }
                }
                if(curr->Left == nullptr && curr->Right == nullptr){              //If deletee has no children
                    if(isRoot == 0){                        //Only need to query parent if deletee is not root
                        if(smallerThanPar == 1){
                            curr->Parent->Left = nullptr;
                        }else{
                            curr->Parent->Right = nullptr;
                        }
                    }else{
                        this->root = nullptr;
                    }
                    delete curr;
                    return;
                }else if(curr->Left == nullptr ^ curr->Right == nullptr){         //If deletee has 1 child
                    if(curr->Left != nullptr){          //Check which child deletee has and saving that for deletee's parent
                        if(isRoot == 1){
                            this->root = curr->Left;
                            delete curr;
                            return;
                        }else{
                            parentNewChild = curr->Left;
                        }
                    }else{
                        if(isRoot == 1){
                            this->root = curr->Right;
                            delete curr;
                            return;
                        }else{
                            parentNewChild = curr->Right;
                        }
                    }
                    parentNewChild->Parent = curr->Parent;  //Setting child's parent pointer to deletee's parent
                    if(smallerThanPar == 1){                //Setting deletee's parent's left or right pointer to deletee's child
                        curr->Parent->Left = parentNewChild;
                    }else{
                        curr->Parent->Right = parentNewChild;
                    }
                    delete curr;
                    return;
                }else{                                                            //If deletee has 2 children
                    Node* smallestSuccessor = findSmallestSuccessor(curr->Right); //Find smallest node in deletee's right subtree
                    curr->data = smallestSuccessor->data;
                    if(smallestSuccessor->Parent != curr){                        //Can call delete on smallestSuccessor if it isn't an 
                        del(smallestSuccessor->data, smallestSuccessor->Parent);    //immediate child of current node (they have equal data 
                        return;                                                         //which would cause issues when comparing parent data)
                    }
                    curr->Right = smallestSuccessor->Right;
                    delete smallestSuccessor;
                    return;
                }

            }else if(deletee < curr->data){
                del(deletee, curr->Left);
            }else{
                del(deletee, curr->Right);
            }
        }
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
        void inorder(Node* curr){
            if(curr == nullptr){
                return;
            }
            inorder(curr->Left);
            std::cout << " | " << curr->data;
            inorder(curr->Right);
        }

};

#endif