//
//  adjList.cpp
//  LabC++
//
//  Created by Arnab Sen on 28/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
//Class for Nodes of a vetex in adjacent list (vertex,weight)
class Node{
    int v;
    int w;
    Node* next;
    friend class AdjNode;
    friend class AdjList;
    Node(int i,int w1){
        v = i;
        w = w1;
        next = nullptr;
    }
};
//Class for Adjacency list contains vertex and pointer to adjacent nodes
class AdjNode{
    int u;
    AdjNode* next;
    Node* adj;
    friend class AdjList;
    AdjNode(int i){
        u = i;
        next = nullptr;
        adj = nullptr;
    }
};
//Class to maintian the Adjacent List
class AdjList{
    AdjNode* head;
public:
    AdjList(){
        head = nullptr;
    }
    void addNewNode(int i){
        if(head==nullptr){
            head = new AdjNode(i);
        }else{
            AdjNode* temp = head;
            while (temp->next!=nullptr) {
                temp = temp->next;
            }
            temp->next = new AdjNode(i);
        }
    }
    void addNewAdj(int u,int v,int w){
        AdjNode* temp = head;
        while(temp->u!=u&&temp->next!=nullptr){
            temp = temp->next;
        }
        if(temp->adj==nullptr){
            temp->adj = new Node(v,w);
        }else{
            Node* temp1 = temp->adj;
            while(temp1->next!=nullptr){
                if(temp1->v==v){
                    break;
                    return;
                }
                temp1 = temp1->next;
            }
            temp1->next = new Node(v,w);
        }
    }
    int returnWeight(int u, int v){
        AdjNode* temp = head;
        int w = -1;
        while (temp->u!=u&&temp->next!=nullptr) {
            temp = temp->next;
        }
        if (temp->adj==nullptr) {
            w = -1;
        }else{
            Node* temp1 = temp->adj;
            while(temp1!=nullptr){
                if(temp1->v==v){
                    w = temp1->w;
                    break;
                }
                temp1 = temp1->next;
            }
            
        }
        return w;
    }
    
};
int main(){
    AdjList adj;
    
    
    //Add vertices of the Graph
    adj.addNewNode(1);
    adj.addNewNode(2);
    adj.addNewNode(3);
    adj.addNewNode(4);
    
    
    //Add the adjacent vertices and weight connecting them
    adj.addNewAdj(1, 2, 10);
    adj.addNewAdj(1, 3, 12);
    adj.addNewAdj(1, 4, 13);
    adj.addNewAdj(2, 3, 11);
    adj.addNewAdj(2, 1, 19);
    adj.addNewAdj(1, 3, 12);
    
    //Returning the weigth of the vertex
    cout<<adj.returnWeight(2, 3)<<endl;
    cout<<adj.returnWeight(1, 3)<<endl;

}
