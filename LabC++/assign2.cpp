//
//  assign2.cpp
//  LabC++
//
//  Created by Arnab Sen on 02/10/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;
class account{
    int acc_no;
    string name;
public:
    float amt;
    account(int, string,float);
    void display();
};
account::account(int a, string n, float am){
    acc_no = a;
    name = n;
    amt = am;
}
void account::display(){
    cout<<"\nAccount No: "<<acc_no<<"\nName: "<<name<<"\nAmount: "<<amt<<endl;
}
class loan:public account{
    float intr,intrest;
    int time;
public:
    loan(int, string,float,float, int);
    void calc();
    void display1();
};
loan::loan(int a, string n, float am,float i, int t):account(a,n,am){
    intr = i;
    time = t;
}
void loan::calc(){
    intrest =  (amt*(float)time*intr)/100.0;
};
void loan::display1(){
    cout<<"The Intrest Amount: "<<intrest<<endl;
    amt = amt + intrest;
    cout<<"Amount Payable:  "<<amt<<endl;
}
int main(){
    int acc_no,time;
    string name;
    float amt,intr;
    cout<<"Enter the Acc. No, Name and the Initial amount"<<endl;
    cin>>acc_no>>name>>amt;
    account a1(acc_no,name,amt);
    a1.display();
    cout<<"Enter the Intrest rate (in %) and time (in years)"<<endl;
    cin>>intr>>time;
    loan l1(acc_no,name,amt,intr,time);
    l1.display1();
    l1.calc();
    l1.display1();
}
