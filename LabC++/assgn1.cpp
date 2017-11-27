//
//  assgn1.cpp
//  LabC++
//
//  Created by Arnab Sen on 02/10/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class student{
    string name,dept;
    int roll_no;
public:
    void set_data(){
        cout<<"Enter the name"<<endl;
        cin>>name;
        cout<<"Enter the roll no"<<endl;
        cin>>roll_no;
        cout<<"Enter the dept"<<endl;
        cin>>dept;
    }
    void display(){
        cout<<"\nName: "<<name<<"\nRoll No: "<<roll_no<<"\nDept: "<<dept;
    }
};
class modified_student: public student{
int marks, yop;
float cgpa;
public:
    void set_data1(){
        cout<<"Enter the marks"<<endl;
        cin>>marks;
        cout<<"Enter cgpa"<<endl;
        cin>>cgpa;
        cout<<"Enter year of passing"<<endl;
        cin>>yop;
    }
    void display1(){
        cout<<"\nMarks: "<<marks<<"\nCGPA: "<<cgpa<<"\nYear of Passing: "<<yop;
    }
};
int main(){
    student s1;
    s1.set_data();
    s1.display();
    modified_student m1;
    m1.set_data();
    m1.set_data1();
    m1.display();
    m1.display1();
}
