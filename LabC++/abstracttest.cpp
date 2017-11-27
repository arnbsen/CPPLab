//
//  abstracttest.cpp
//  LabC++
//
//  Created by Arnab Sen on 13/10/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class employee{
public:
    string a;
    string ssn;
    virtual void print()=0;
    
};
class hourly: public employee{
public:
    int wages;
    void print(){
        cout<<"Name:  "<<a<<endl<<"Social Security No: "<<ssn<<endl<<"Wage: "<<wages<<endl;
    }
};
class salaried: public employee{
public:
    int salary;
    void print(){
        cout<<"Name:  "<<a<<endl<<"Social Security No: "<<ssn<<endl<<"Salary: "<<salary<<endl;
    }
};
class rooster: virtual public hourly, virtual public salaried{
public:
    int counth,counts,rec;
    rooster(){
        counth = 0;
        counts = 0;
    }
    void get_data(int i,string name,string ssn1){
        
        if(i==1){
            salaried::a = name;
            salaried::ssn = ssn1;
            cout<<"Enter the Salary"<<endl;
            cin>>salary;
            counth = counth + 1;
            rec = 1;
        }else{
            salaried::a = name;
            salaried::ssn = ssn1;
            hourly::a = salaried::a;
            hourly::ssn = salaried::ssn;
            cout<<"Enter the Wages"<<endl;
            cin>>wages;
            counts = counts + 1;
            rec = 2;
        }
        
        
    }
    void print(){
        if(rec==1){
            salaried::print();
        }else{
            hourly::print();
        }
        
    }
    bool check(string a1, string ssn1){
        if(salaried::a==a1&&salaried::ssn==ssn1){
            return true;
        }
        return false;
    }
};
int main(){
    rooster r1[100];
    int cnt = 0,i,ind;
    string name,ssn;
    int ch,ch1;
    bool flag = true;
    do{
        cout<<"Enter your choice 1. Enter employee 2. Delete employee 3. Display information 4. Display number 0. Terminate"<<endl;
        cin>>ch;
        switch (ch) {
            case 1:
                flag = false;
                cout<<"Enter choice 1. Salaried Employee 2. Hourly Paid Employee "<<endl;
                cin>>ch1;
                cout<<"Enter the Name and social Security Number"<<endl;
                cin>>name>>ssn;
                for (i=0; i<cnt; i++) {
                    if(r1[i].check(name, ssn)){
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    cout<<"Employee already exists"<<endl;
                }else{
                r1[cnt].get_data(ch1,name,ssn);
                cnt = cnt + 1;
                }
                break;
            case 2:
                flag = true;
                cout<<"Enter the Name and social Security Number"<<endl;
                cin>>name>>ssn;
                ind = cnt + 1;
                for (i=0; i<cnt; i++) {
                    if(r1[i].check(name, ssn)){
                        ind = i;
                        for (int j=ind; j<cnt-1; j++) {
                            r1[j] = r1[j+1];
                        }
                        cout<<"Employee successfully deleted"<<endl;
                        cnt = cnt - 1;
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    cout<<"Employee not found"<<endl;
                }
                break;
            case 3:
                for (i=0; i<cnt; i++) {
                    r1[i].print();
                }
            case 4: cout<<"No. of employess = "<<cnt<<endl;
                break;
        }
        
        
    }while (ch>0);
}
