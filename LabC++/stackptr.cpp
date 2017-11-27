//
//  stackptr.cpp
//  LabC++
//
//  Created by Arnab Sen on 27/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class Node{

    int item;
    Node* next;
    friend class Stack;
public:
    Node(int i){
        item = i;
        next = nullptr;
    }
};
class Stack{
    Node* head;
    public:
    Stack(){
        head = nullptr;
    }
    void operator+(int x){
        if(head==nullptr){
            head = new Node(x);
        }else{
            Node* node = new Node(x);
            node->next = head;
            head = node;
        }
    }
    int operator--(){
        if(head==nullptr){
            cout<<"Stack is empty\n";
            return -1;
        }else{
            int temp = head->item;
            head = head->next;
            return temp;
        }
    }
    void disp(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->item<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Stack st;
    st+2;
    st+3;
    st+4;
    st.disp();
    int n = --st;
    --st;
    --st;
    n = --st;
    cout<<"Popped value: "<<n<<endl;
    st.disp();
    
    
    
}
