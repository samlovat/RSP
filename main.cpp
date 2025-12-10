#include "Node.h"
#include "LinkedList.h"

int main(){
    LinkedList* myList = new LinkedList(3);
    myList->del(3);
    myList->print(myList->Head);
//     Node* looking = myList->search(7, myList->Head);
//     if(looking != nullptr){
//         printf("\n");
//         std::cout << looking->data << std::endl;
//     }
}