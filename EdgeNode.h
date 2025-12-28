#ifndef EDGENODE_H
#define EDGENODE_H

class edgeNode{
    public:
        int y;  //Other vertex in edge
        int weight;     //Weight of edge if relevant
        edgeNode* next;     //Next edge adjacent to starting vertex (x)
        edgeNode(int y_, int weight_, edgeNode* next_){
            this->y = y_;
            this->weight = weight_;
            this->next = next_;
        };
};
#endif