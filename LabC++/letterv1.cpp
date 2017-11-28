//
//  letterv1.cpp
//  LabC++
//
//  Created by Arnab Sen on 28/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class Letter{
public:
    virtual void display(char) = 0;
};
class UpperCase: public Letter{
public:
    void display(char c);
};
void UpperCase::display(char c){
    char d = (char) ((int) c + 32);
    cout<<"Lower Case: "<<d<<endl;
}
class LowerCase:public Letter{
public:
    void display(char c);
};
void LowerCase::display(char c){
    char d = (char) ((int) c - 32);
    cout<<"Lower Case: "<<d<<endl;
}
class Error: public Letter{
public:
    void display(char c);
};
void Error::display(char c){
    cout<<"This is an Invalid Character\n";
}
class GetCharacter{
    Letter* p;
public:
    void get(char c);
};
void GetCharacter::get(char c){
    if(c>='a'&&c<='z'){
        p = new LowerCase();
        p->display(c);
    }else if(c>='A'&&c<='Z'){
        p = new UpperCase();
        p->display(c);
    }else{
        p = new Error();
        p->display(c);
    }
}
int main(){
    char test;
    GetCharacter gch;
    do{
        
        cout<<"Enter a character\n";
        cin>>test;
        gch.get(test);
        
        //Press CTRL + C to stop executing the code
    }while(true);
}
