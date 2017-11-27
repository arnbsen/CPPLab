//
//  test.cpp
//  LabC++
//
//  Created by Arnab Sen on 07/09/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//
#include <iostream>
#include <stdio.h>
using namespace std;
class test{
public:
    int a1,b1;
    test();
    test(int a, int b);
    void add(test ob);
    
};
test::test(){
}
test::test(int a, int b){
    a1 = a;
    b1 = b;
}
void funct(const test& ob){
    cout<<ob.a1<<ob.b1;
}
int main(){
    test t1;
    test t2(4,5);
    test(1,2);
    funct(test(1,2));
    funct(t2);

}
