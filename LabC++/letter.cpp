//
//  letter.cpp
//  LabC++
//
//  Created by Arnab Sen on 28/10/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <iostream>
using namespace std;
class letter{
public:
    virtual void display(char) = 0;
};
class upperCase: public letter{
public:
    void display(char);
};
void upperCase::display(char c){
    cout<<"To LowerCase = "<<tolower(c);
}
class lowerCase: public letter{
public:
    void display(char);
};
void lowerCase::display(char c){
    cout<<"To UpperCase = "<<toupper(c)<<endl;
}
class error: public letter{
public:
    void display(char);
};
void error::display(char c){
    cout<<"Invalid character"<<endl;
}
class getChar{
    letter *l;
public:
    void getLetter();
};
void getChar::getLetter(){
    char c;
    cout<<"Enter a character"<<endl;
    cin>>c;
    if(c>='a'&&c<='z'){
        upperCase u;
        l = &u;
        l->display(c);
    }else if (c>='A'&&c<='Z'){
        lowerCase l1;
        l = &l1;
        l->display(c);
    }
}
