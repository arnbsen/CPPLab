//
//  temp1.cpp
//  LabC++
//
//  Created by Arnab Sen on 27/10/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//


#include <iostream>
using namespace std;
class X{
private:
    int x,y;
public:
    X();
    X(int,int);
    friend ostream &operator<<(ostream &output,const X a){
        output<<"Item x= "<<a.x<<" Item y = "<<a.y;
        return output;
    }
    bool operator==(X&);
};
X::X(){
    
}
X::X(int a, int b){
    x = a;
    y = b;
}
bool X::operator==(X& a){
    if((a.x == x)&&(a.y==y)){
        return true;
    }else{
        return false;
    }
}
template<class Y>class array1{
private:
    array1<Y>* next;
    Y ob;
public:
    array1();
    void add(const Y&);
    void del();
    void display();
    
};
template<class Y> array1<Y>::array1(){
    next = NULL;
}
template<class Y> void array1<Y>::add(const Y& ob){
    array1<Y>* temp = this;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new array1<Y>;
    temp->next->ob = ob;
}
template<class Y>void array1<Y>::del(){
    array1<Y>* temp = this;
    array1<Y>* temp1 = this->next;
    temp->next = temp1->next;
}
template<class Y> void array1<Y>::display(){
    array1<Y>* temp = this->next;
    while(temp!=NULL){
        cout<<temp->ob<<" ";
        temp = temp->next;
    }
}
int main(){
    array1<X> *head = new array1<X>;
    int ch,i = 1,d=4;
    do {
        cout<<"Enter choice 1. Insert 2. Delete 3.Display 0. Terminate"<<endl;
        cin>>ch;
        switch (ch) {
            case 1:
                cout<<"Enter item to insert"<<endl;
                cin>>i;
                head->add(X(2,3));
                break;
            case 2:
                head->del();
                break;
            case  3:head->display();
            default:
                break;
        }
    } while (ch>0);
}
