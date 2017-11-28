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
                }
                temp1 = temp1->next;
            }
            temp1->next = new Node(v,w);
        }
    }
};
int main(){
    AdjList adj;
    adj.addNewNode(1);
    adj.addNewNode(2);
    adj.addNewNode(3);
    adj.addNewNode(4);
    adj.addNewAdj(1, 2, 10);
    adj.addNewAdj(1, 3, 12);
    adj.addNewAdj(1, 4, 13);
    adj.addNewAdj(2, 3, 11);
    adj.addNewAdj(2, 1, 19);
    adj.addNewAdj(1, 3, 12);


}
