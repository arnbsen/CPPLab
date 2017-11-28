//
//  primsAdjList.cpp
//  LabC++
//
//  Created by Arnab Sen on 28/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//  I know I overshot the time complexity :(

#include <stdio.h>
#include <iostream>
using namespace std;
class Node{ //Maintining the adjacent nodes
    int v;
    int w;
    int p;
    Node* next;
    friend class adjNode;
    friend class AdjList;
public:
    Node(int,int);
};
Node::Node(int v1,int w1){
    v = v1;
    w = w1;
    p = -1;
    next = nullptr;
}
class adjNode{ //Maitains vertices and the adjacent vertices
    int u;
    int d;
    Node* adj;
    bool visited;
    adjNode* next;
    friend class AdjList;
public:
    adjNode(int);
};
adjNode::adjNode(int v){
    u = v;
    visited = false;
    next = nullptr;
    adj = nullptr;
}
class AdjList{ //Class for controlling Adjacency List and all functions are needed for Prims Algorithm
    Node* dist; //Distance vector
    adjNode* head; //Contains Adjacent List
public:
    AdjList();
    void operator+(int); //Adding vertices to Graph
    void addAdjNode(int,int,int); //Adding adjacent vertices with weight
    bool isVisited(int); //Returns true if the vertex is visit
    void visit(int); //Visit a particular vertex
    bool visitedAll(); //Returns True if all vertices are visited
    int findMinDist(); //Returns the index of minimum distance of all Vertices
    void setDist(int u); //Updates the distance
    void setInit(int v); //Set the source
};
AdjList::AdjList(){
    dist = nullptr;
    head = nullptr;
}
void AdjList::operator+(int v){
    if(head==nullptr){
        head = new adjNode(v);
        dist = new Node(v,999999);
    }else{
        adjNode* temp = head;
        Node* temp1 = dist;
        while(temp->next!=nullptr){
            temp1 = temp1->next;
            temp = temp->next;
        }
        temp->next = new adjNode(v);
        temp1->next = new Node(v,999999);
    }
}
void AdjList::addAdjNode(int u, int v, int w){
    adjNode* temp = head;
    while(temp->u!=u&&temp->next!=nullptr){
        temp = temp->next;
    }
    if(temp->u==u){
        Node* temp1 = temp->adj;
        if(temp->adj==nullptr){
            temp->adj = new Node(v,w);
        }else{
            while(temp1->next!=nullptr){
                if(temp1->v==v){
                    return;
                }
                temp1 = temp1->next;
            }
            temp1->next = new Node(v,w);
        }
    }else{
        cout<<"Invalid vertex Entry\n";
    }
}
void AdjList::visit(int v){
    adjNode* temp = head;
    while(temp->next!=nullptr&&temp->u!=v){
        temp = temp->next;
    }
    if(temp->u==v){
        temp->visited = true;
    }else{
        cout<<"Invalid Selection\n";
    }
}
bool AdjList::isVisited(int v){
    adjNode* temp = head;
    while(temp!=nullptr&&temp->u!=v){
        temp = temp->next;
    }
    return temp->visited;
}

bool AdjList::visitedAll(){ //Check if all vertices are visited or not.
    adjNode* temp = head;
    bool retval = true;
    while(temp!=nullptr){
        retval = retval&&temp->visited;
        temp = temp->next;
    }
    return retval;
}
int AdjList::findMinDist(){ //Find the minimum distance vertex.
    int min = 999999;
    int id = -1;
    int p = -1;
    Node* temp = dist;
    while(temp!=nullptr){
        //cout<<temp->v<<"  ";
        if(temp->w < min&&!isVisited(temp->v)){
            min = temp->w;
            id = temp->v;
            p = temp->p;
        }
        temp = temp->next;
        
    }
    cout<<p<<" to "<<id<<" with weight "<<min<<endl;
    return id;
}
void AdjList::setDist(int u){ //Updating All distances.
    adjNode* temp1 = head;
    while(temp1!=nullptr&&temp1->u!=u){
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->adj;
    while(temp2!=nullptr){
        int c = temp2->v;
        Node* temp = dist;
        while (temp!=nullptr&&temp->v!=c) {
            temp = temp->next;
        }
        if (!isVisited(c)) {
            temp->w = temp->w<temp2->w?temp->w:temp2->w;
            temp->p = temp->w<temp2->w?temp->p:u;
        }
        temp2 = temp2->next;
    }
}
void AdjList::setInit(int v){ //Set Source vertex.
    Node* temp = dist;
    while (temp!=nullptr&&temp->v!=v) {
        temp = temp->next;
    }
    temp->w = 0;
}
int main(){
    AdjList Prims;
    
    //Adding Initial Nodes
    Prims+1;
    Prims+2;
    Prims+3;
    Prims+4;
    Prims+5;
    Prims+6;
    Prims+7;
    Prims+8;
    Prims+9;
    
    //Adding adjcacent Nodes
    Prims.addAdjNode(1, 2, 4);
    Prims.addAdjNode(2, 1, 4);
    Prims.addAdjNode(1, 8, 8);
    Prims.addAdjNode(8, 1, 8);
    Prims.addAdjNode(2, 3, 8);
    Prims.addAdjNode(3, 2, 8);
    Prims.addAdjNode(3, 9, 2);
    Prims.addAdjNode(9, 3, 2);
    Prims.addAdjNode(3, 4, 7);
    Prims.addAdjNode(4, 3, 7);
    Prims.addAdjNode(3, 6, 4);
    Prims.addAdjNode(6, 3, 4);
    Prims.addAdjNode(4, 5, 9);
    Prims.addAdjNode(5, 4, 9);
    Prims.addAdjNode(5, 6, 10);
    Prims.addAdjNode(6, 5, 10);
    Prims.addAdjNode(6, 7, 2);
    Prims.addAdjNode(7, 6, 2);
    Prims.addAdjNode(7, 8, 1);
    Prims.addAdjNode(8, 7, 1);
    Prims.addAdjNode(8, 9, 7);
    Prims.addAdjNode(9, 8, 7);
    
    //Starting Prims Algorithm
    
    Prims.setInit(1); //Setting Souce vertex
    cout<<"The selction of vertices (-1) denotes start vertex"<<endl;
    while (!Prims.visitedAll()) {
        int m = Prims.findMinDist();
        Prims.visit(m);
        Prims.setDist(m);
        
    }
    
    
    
    
}
