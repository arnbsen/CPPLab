//
//  DLL.cpp
//  LabC++
//
//  Created by Arnab Sen on 28/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class Node{
    Node* next;
    Node* prev;
    int item;
    friend class DLL;
    Node(){
        prev = nullptr;
        next = nullptr;
    }
    Node(Node* p,int i){
        item = i;
        prev = p;
        next = nullptr;
    }
};
class DLL{
    Node* head,*tail;
public:
    DLL(){
        head = new Node();
        tail = head;
    }
    void operator+(int x){
        tail->next = new Node(tail,x);
        tail = tail->next;
    }
    void operator--(){
        head = head->next;
        head->prev = nullptr;
    }
    void dispBack(){
        Node* temp = tail;
        while(temp!=head){
            cout<<temp->item<<"  ";
            temp = temp->prev;
        }
        cout<<endl;
    }
    void dispFront(){
        Node* temp = head->next;
        while(temp!=nullptr){
            cout<<temp->item<<"  ";
            temp = temp->next;
        }
        cout<<endl;

    }
};
int main(){
    DLL dll;
    dll+2;
    dll+3;
    dll+4;
    dll+5;
    dll+6;
    dll.dispBack();
    dll.dispFront();
    --dll;
    --dll;
    dll.dispBack();
    dll.dispFront();
    
}
