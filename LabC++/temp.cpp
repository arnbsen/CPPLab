//
//  temp.cpp
//  LabC++
//
//  Created by Arnab Sen on 14/10/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <iostream>
using namespace std;
template <class X>class array1 {
public:
    X item;
    array1<X>* next;
    array1<X>(){
        next = NULL;
    }
    void add(X ob){
        array1<X>* temp = this;
        while (temp->next!=NULL) {
            temp= temp->next;
        }
        temp->next = new array1<X>;
        temp->next->item = ob;
    }
    void del(X ob){
        array1<X>* temp = this;
        array1<X>* temp1 = this->next;
        while (temp1->item!=ob&&temp1->next!=NULL) {
            temp = temp->next;
            temp1 = temp1->next;
        }if (temp1->item==ob) {
            temp->next = temp1->next;
        }
        
    }
    void display(){
        array1<X>* temp = this->next;
        while (temp!=NULL) {
            cout<<temp->item<<" ";
            temp = temp->next;
        }
    }
};

int main(){
    array1<int> *head = new array1<int>;
    int ch,i = 1,d=4;
    do {
        cout<<"Enter choice 1. Insert 2. Delete 3.Display 0. Terminate"<<endl;
        cin>>ch;
        switch (ch) {
            case 1:
                cout<<"Enter item to insert"<<endl;
                cin>>i;
                head->add(i);
                break;
            case 2:
                cout<<"Enter item to delete"<<endl;
                cin>>d;
                head->del(d);
                break;
            case  3:head->display();
            default:
                break;
        }
    } while (ch>0);
}
