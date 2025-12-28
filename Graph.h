#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <queue>
#include "EdgeNode.h"
#define MAXVERTICES 100   //Set maximum possible Vertices in graph
#define DIRECTED 1        //Values of directed var
#define UNDIRECTED 0        
#define UNDISCOVERED 0
#define DISCOVERED 1
#define PROCESSED 2

class Graph{
    public:
        edgeNode* edges[MAXVERTICES];   //Adjacency List of all edges for each vertex
        int nvertices;                  //Number of vertices
        int nedges;                     //Number of edges
        int directed;                   //Is the graph directed?
        int degree[MAXVERTICES];        //Degree of each vertex
        int state[MAXVERTICES];         //State of vertices for BFS and DFS

        Graph(int directed_){
            this->directed = directed_;
            this->nedges = 0;
            this->nvertices = 0;
            for(int i = 0; i < MAXVERTICES; i++){
                this->edges[i] = nullptr;
                this->degree[i] = 0;
            }
        };

        void insertEdge(int x, int y, int directed_){
            edgeNode* temp;                         //Temporary edgeNode pointer to assist insertion
            temp = this->edges[x-1];
            this->edges[x-1] = new edgeNode(y-1, 0, temp);
            this->degree[x-1]++;
            if(directed_ == UNDIRECTED){            //Create edge instance in edges[y] if undirected
                insertEdge(y, x, 1);                //Call recursively, but give directed == 1 so next call 
            }                                       //stack doesn't recursively call again
            return;
        }

        void init(int nedges_, int nvertices_){
            this->nedges = nedges_;
            this->nvertices = nvertices_;
            int x, y;       //Start and end of edges
            for(int i = 0; i < nedges_; i++){
                printf("\nEdge %d/%d: ", i+1, nedges_);
                scanf("%d %d", &x, &y);
                insertEdge(x, y, this->directed);
            }
            return;
        };

        void printGraph(){             //Iterate through vertices and print list 
            edgeNode* temp;             //of other vertices it connects to via an edge
            for(int i = 0; i < this->nvertices; i++){
                printf("\n%d has edges to:", i+1);
                temp = this->edges[i];
                while(temp != nullptr){
                    printf(" %d", temp->y+1);
                    temp = temp->next;
                }
            }
            return;
        };

        void del(){};

        void ZeroState(){           //Reset state array before any DFS or BFS traversal
            for(int i = 0; i < nvertices; i++){
                this->state[i] = UNDISCOVERED;
            }
        }

        void processVertex(int x){
            printf("\nProcessed %d", x+1);
            this->state[x] = PROCESSED;
            return;
        };

        void BFS(int rootVertex){
            edgeNode* temp;
            std::queue<int> ProcessNext;
            ProcessNext.push(rootVertex);
            while(!ProcessNext.empty()){
                int topOfQueue = ProcessNext.front();
                temp = this->edges[topOfQueue];    //temp takes edge on top of queue
                processVertex(topOfQueue);
                ProcessNext.pop();
                while(temp != nullptr){
                    if(state[temp->y] == UNDISCOVERED){
                        state[temp->y] = DISCOVERED;
                        // printf("\nEdge %d - %d in BFS tree", topOfQueue+1, temp->y+1);
                        ProcessNext.push(temp->y);
                    }
                    temp = temp->next;
                }
            }
            return;
        };

        void DFS(int rootVertex){       //Call with index of rootNode i.e. if you want to start at vertex 1 call DFS(0)
            edgeNode* temp = this->edges[rootVertex];
            this->state[rootVertex] = DISCOVERED;
            int degree = this->degree[rootVertex];
            for(int i = 0; i < degree; i++){
                if(state[temp->y] == UNDISCOVERED){
                    // printf("\nEdge %d - %d in DFS tree", rootVertex+1, temp->y+1);
                    DFS(temp->y); 
                }
                temp = temp->next;
            }
            processVertex(rootVertex);
            return;
        };
};

#endif