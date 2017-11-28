//
//  nameSpaceTest.cpp
//  LabC++
//
//  Created by Arnab Sen on 28/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
namespace TryNameSpace{
    class string{ //Imitatating the string class in C++ STL
        char* a;
    public:
        void operator=(char* b){
            a = b;
        }
        operator char*(){ return a;}
    };
}
int main(){
    cout<<"----Demonstration of Namespace----\n";
    
    //Using keyword 'using' to resolve naming colliions
    using TryNameSpace::string;
    string b;
    b = (char *)"Using 'using' keyword to define scope\n";
    cout<<b;
    
    //Resolution operator to solve conflicts
    //One way of accessing NameSpace variables and Classes
    TryNameSpace::string a;
    char* c = (char *)"Using resolution operator :: \n";
    a = c;
    cout<<a;
    
}

