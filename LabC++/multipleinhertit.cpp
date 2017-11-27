//
//  multipleinhertit.cpp
//  LabC++
//
//  Created by Arnab Sen on 02/10/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class person{
private:
    
public:
    string name;
    int age;
    person();
    person(string,int);

};
person::person(){
    
}
person::person(string n, int a){
    name = n;
    age = a;
}
class faculty:public person{
public:
    faculty();
    faculty(string,int);
    void get_data();
};
faculty::faculty(string n, int a):person(n,a){
    
}
void faculty::get_data(){
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
}
class student:public person{
public:
   
    
};
class TA:public faculty,student{
public:
    TA(string,int);
    
};
TA::TA(string n, int a):faculty(n,a){
    
}
int main(){
    string n;
    int a;
    cout<<"Enter the name"<<endl;
    cin>>n;
    cout<<"Enter the age"<<endl;
    cin>>a;
    TA t1(n,a);
    t1.get_data();
}


