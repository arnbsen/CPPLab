//
//  templateLLsort.cpp
//  LabC++
//
//  Created by Arnab Sen on 29/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
template<class X>class LL{
public:
    X item;
    LL<X> *next;
    friend LL<X>* sort1(LL<X>* head);
    LL(X);
    LL<X>* operator+(X);
    //LL<X>* operator-(X);
    //LL<X>* operator+(LL<X>*);
    void display();
};
template<class X>LL<X>::LL(X item1){
    item = item1;
    next = nullptr;
}
template<class X>LL<X>* LL<X>::operator+(X item1){
    LL<X>* temp = this;
    if(temp==nullptr){
        temp = new LL<X>(item1);
    }else{
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = new LL<X>(item1);
    }
    return this;
}
template<class X>void LL<X>::display(){
    LL<X>* temp = this;
    while(temp->next!=nullptr){
        cout<<temp->item<<"  ";
        temp = temp->next;
    }
    cout<<"\n";
}
template<class X>LL<X>* sort1(LL<X>* head){
    LL<X>* temp = head;
    LL<X>* temp1 = head->next;
    LL<X>* temp3 = temp;
    while(temp!=nullptr){
        temp1 = head->next;
        temp3 = head;
        while(temp1!=nullptr){
            if(temp3->item > temp1->item){
                X t = temp3->item;
                temp3->item = temp1->item;
                temp1->item = t;
            }
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
        temp = temp->next;
    }
    return head;
}
int main(){
    LL<int>* head = new LL<int>(5);
    *head+6;
    *head+1;
    *head+7;
    *head+4;
    *head+3;
    head->display();
    head = sort1<int>(head);
    head->display();
}
