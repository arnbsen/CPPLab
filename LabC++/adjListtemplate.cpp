//
//  adjListtemplate.cpp
//  LabC++
//
//  Created by Arnab Sen on 28/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
template<class X>class Node{
public:
    Node<X>* next;
    X v;
    Node(X);
};
template<class X> Node<X>::Node(X u){
    v = u;
    next = nullptr;
}
template<class X>class AdjNode{
public:
    X u;
    AdjNode<X>* next;
    Node<X>* adj;
    AdjNode(X);
};
template<class X>AdjNode<X>::AdjNode(X v){
    u = v;
    next = nullptr;
    adj = nullptr;
}
template<class X>class AdjList{
    AdjNode<X>* head;
public:
    AdjList();
    void addNode(X u);
    void addAdjNode(X u, X v);
    //void adjNode(X u);
};
template<class X>AdjList<X>::AdjList(){
    head = nullptr;
}
template<class X>void AdjList<X>::addNode(X u){
    if(head==nullptr){
        head = new AdjNode<X>(u);
    }else{
        AdjNode<X>*temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = new AdjNode<X>(u);
    }
}
template<class X>void AdjList<X>::addAdjNode(X u, X v){
    AdjNode<X>* temp = head;
    while(temp->u!=u&temp->next!=nullptr){
        temp = temp->next;
    }
    if(temp->adj==nullptr){
        temp->adj = new Node<X>(v);
    }else{
        Node<X>* temp1 = temp->adj;
        while(temp1->v!=v&&temp1->next!=nullptr){
            temp1 = temp1->next;
        }
        temp1->next = new Node<X>(v);
    }
}
int main(){
    AdjList<int> adj;
    adj.addNode(1);
    adj.addNode(2);
    adj.addNode(3);
    adj.addNode(4);

    adj.addAdjNode(1, 3);
    adj.addAdjNode(1, 4);
    adj.addAdjNode(1, 2);
    adj.addAdjNode(2, 3);
    adj.addAdjNode(2, 4);
    adj.addAdjNode(3, 4);
    adj.addAdjNode(4, 1);



}
