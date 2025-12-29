#include "Graph.h"
#include <iostream>

int main(){
    Graph* myGraph = new Graph(0);      //Only handling undirected for now
    int nedges, nvertices;
    myGraph->CollectValues(nedges, nvertices);
    myGraph->printGraph();
    int DFSRoot;
    printf("\nWhere to perform DFS from? ");
    scanf("%d", &DFSRoot);
    myGraph->DFS(DFSRoot-1);
    int BFSRoot;
    printf("\nWhere to perform BFS from? ");
    scanf("%d", &BFSRoot);
    myGraph->BFS(BFSRoot-1);
    return 0;
}