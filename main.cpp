#include "Node.h"
#include "LinkedList.h"

int main(){
    Node* theHead = new Node(3, nullptr);
    LinkedList* myList = new LinkedList(theHead);
    myList->ins(2);
    myList->ins(4);
    myList->ins(5);
    myList->ins(6);
    myList->ins(7);
    myList->print(myList->Head);
}