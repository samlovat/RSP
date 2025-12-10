#include "Node.h"
#include "LinkedList.h"

int main(){
    LinkedList* myList = new LinkedList(3);
    myList->ins(2);
    myList->ins(4);
    myList->ins(5);
    myList->ins(6);
    myList->ins(7);
    myList->print(myList->Head);
    myList->del(4);
    printf("\n");
    myList->print(myList->Head);
    Node* looking = myList->search(7, myList->Head);
    if(looking != nullptr){
        printf("\n");
        std::cout << looking->data << std::endl;
    }
}