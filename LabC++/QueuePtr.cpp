//
//  QueuePtr.cpp
//  LabC++
//
//  Created by Arnab Sen on 28/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class Node{
    int item;
    Node* next;
    friend class Queue;
    public:
    Node(int i){
        item = i;
        next = nullptr;
    }
};
class Queue{
    Node* front,*rear;
public:
    void operator+(int x){
        if(front==nullptr){
            front = new Node(x);
            rear = front;
        }else{
            rear->next = new Node(x);
            rear = rear->next;
        }
    }
    int operator--(){
        if(front==nullptr){
            cout<<"Queue is empty"<<endl;
            return -1;
        }else{
            int temp = front->item;
            front = front->next;
            return temp;
        }
    }
    void disp(){
        Node* temp = front;
        while(temp!=nullptr){
            cout<<temp->item<<"  ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Queue queue;
    queue+2;
    queue+3;
    queue+4;
    queue+9;
    queue.disp();
    int n = --queue;
    cout<<"Dequeued Value: "<<n<<endl;
    --queue;
    --queue;
    queue.disp();
    --queue;
    --queue;
}
