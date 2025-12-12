#include <iostream>
#include "Node.h"
#include "BinaryTree.h"
int main(){
    BinaryTree* myTree = new BinaryTree(7);
    myTree->ins(4, myTree->root);
    myTree->ins(5, myTree->root);
    myTree->ins(1, myTree->root);
    myTree->ins(9, myTree->root);
    myTree->ins(3, myTree->root);
    myTree->ins(12, myTree->root);
    myTree->ins(8, myTree->root);
    myTree->ins(2, myTree->root);
    myTree->del(9, myTree->root);
    myTree->del(7, myTree->root);
    myTree->inorder(myTree->root);
    return 0;
}