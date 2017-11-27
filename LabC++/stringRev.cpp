//
//  stringRev.cpp
//  LabC++
//
//  Created by Arnab Sen on 11/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
class Rev{
    string s;
    char c[2000];
public:
    Rev(string s){
        this->s = s;
    }
    void reverse(){
        int m = (int)s.size();
        for(int i = m-1,k=0; i>=0;i--,k++){
            c[k] = s.back();
            s.pop_back();
        }
        c[m] = '\0';
        cout<<"The reversed string:    "<<c<<endl;
    }
};
int main(){
    string s;
    cout<<"Enter a string to reverse\n";
    cin>>s;
    Rev s1(s);
    s1.reverse();
    
}
