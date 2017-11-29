//
//  constDest.cpp
//  LabC++
//
//  Created by Arnab Sen on 28/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class Fraction{
    int p;
    int q;
     //~Fraction();
public:
    Fraction();
    Fraction(int,int);
    Fraction operator++();
    Fraction operator++(int);
    Fraction operator--();
    Fraction operator--(int);
    Fraction operator+(const Fraction);
    Fraction operator-(const Fraction);
    bool operator==(const Fraction);
    bool operator<(const Fraction);
    Fraction operator<<(int);
    void disp();
};
Fraction::Fraction(){
    p = 1;
    q = 1;
}
Fraction::Fraction(int p1, int q1){
    p = p1;
    q = q1;
}
//Fraction::~Fraction(){
//    cout<<"Destroying Fraction:  "<<p<<"/"<<q<<endl;
//}
Fraction Fraction::operator+(const Fraction f){
    Fraction ret;
    ret.p = this->p*f.q + this->q*f.p;
    ret.q = this->q*f.q;
    return ret;
}
Fraction Fraction::operator-(const Fraction f){
    Fraction ret;
    ret.p = this->p*f.q - this->q*f.p;
    ret.q = this->q*f.q;
    return ret;
}
Fraction Fraction::operator++(){
    *this = *this+(Fraction());
    return *this;
}
Fraction Fraction::operator--(){
    *this = *this-(Fraction());
    return *this;
}
Fraction Fraction::operator++(int i){
    Fraction* f = this;
    *this = *this+Fraction();
    return *f;
}
Fraction Fraction::operator--(int i){
    Fraction* f = this;
    *this = *this-Fraction();
    return *f;
}
bool Fraction::operator<(const Fraction f){
    return (f.p/f.q) > (this->p/this->q);
}
bool Fraction::operator==(const Fraction f){
    return (f.p/f.q) == (this->p/this->q);
}
void Fraction::disp(){
    cout<<p<<"/"<<q;
}
Fraction Fraction::operator<<(int a){
    this->p = this->p + a;
    return *this;
}
int main(){
    Fraction f1(2,3),f2(4,5),f3(7,6),f4,f5(4,5);
    f1.disp();
    cout<<endl;
    f2.disp();
    cout<<endl;
    f4 = f1+f2;
    f4.disp();
    cout<<endl;
    f4 = f3-f2;
    f4.disp();
    cout<<endl;
    if(f1<f3){
        f1.disp(); cout<<" is smaller"<<endl;
    }
    if(f2==f5){
        f2.disp(); cout<<" is equal "<<endl;
    }
    f1<<2;
    f1.disp();
    cout<<endl;
    f1++;
    f1.disp();
    cout<<endl;
    ++f1;
    f1.disp();
    cout<<endl;
    f1--;
    f1.disp();
    cout<<endl;
    --f1;
    f1.disp();
    cout<<endl;
}
