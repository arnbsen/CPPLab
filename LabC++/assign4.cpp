//
//  assign4.cpp
//  LabC++
//
//  Created by Arnab Sen on 02/10/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <iostream>
using namespace std;
class matrix{
    
public:
    int r,c;
    int mat[100][100];
    matrix();
    void set_values(int,int);
    matrix add(matrix& a);
    matrix sub(matrix& a);
    matrix mult(matrix& a);
    void print();
};
matrix::matrix(){
   
}
void matrix::set_values(int r1, int c1){
    r = r1;
    c = c1;
    for (int i = 0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin>>mat[i][j];
        }
    }
}
matrix matrix::add(matrix& a){
    matrix m3;
    if(!(r==a.r&&c==a.c)){
        cout<<"Dimensions do not agree"<<endl;
    }else{
        m3.r = r;m3.c= c;
        for (int i=0; i<r; i++) {
            for (int j =0 ; j<c; j++) {
                m3.mat[i][j] = mat[i][j] + a.mat[i][j];
            }
        }
    }
    return m3;
}
matrix matrix::sub(matrix& a){
    matrix m3;
    if(!(r==a.r&&c==a.c)){
        cout<<"Dimensions do not agree"<<endl;
    }else{
         m3.r = r;m3.c= c;
        for (int i=0; i<r; i++) {
            for (int j =0 ; j<c; j++) {
                m3.mat[i][j] = mat[i][j] - a.mat[i][j];
            }
        }
    }
    return m3;
}
matrix matrix::mult(matrix& a){
    matrix m3;
    if(!(c==a.r)){
        cout<<"Dimensions do not agree"<<endl;
    }else{
        m3.r = r;
        m3.c = a.c;
        for (int i=0; i<r; i++) {
            for (int j =0 ; j<a.c; j++) {
                m3.mat[i][j] = 0;
                for (int k=0; k<a.c; k++) {
                    m3.mat[i][j] = m3.mat[i][j] + mat[i][k]*a.mat[k][j];
                }
            }
        }
    }
    return m3;
}
void matrix::print(){
    for (int i = 0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
class vec: public matrix{
public:
    vec();
    vec mult1(vec& a);
    vec sc_add(int sc);
    vec sc_mult(int sc);
    
};
vec::vec(){
    
}
vec vec::mult1(vec &a){
    vec v1;
    if(!(a.r==r)){
        cout<<"Dimensions do not agree\n";
    }else{
        for (int i=0; i<r; i++) {
            v1.mat[i][0] = mat[i][0]*a.mat[i][0];
        }
    }
    return v1;
}
vec vec::sc_add(int sc){
    vec v1;
    
        for (int i=0; i<r; i++) {
            v1.mat[i][0] = mat[i][0] + sc;
        
    }
    return v1;
}
vec vec::sc_mult(int sc){
    vec v1;
    
        for (int i=0; i<r; i++) {
            v1.mat[i][0] = mat[i][0]*sc;
        
    }
    return v1;
}
int main(){
    matrix m1,m2,m3;
    vec v1,v2,v3;
    int ch,r,c,sc;
    cout<<"Matrix operation\n";
    do{
        cout<<"Enter your choice 1. Enter m1 2. Enter m2 3. Add 4. Substract 5. Multiply 6. Print 0. Terminate"<<endl;
        cin>>ch;
        switch (ch) {
            case 1:
                cout<<"Enter dimension (row,col)"<<endl;
                cin>>r>>c;
                m1.set_values(r, c);
                break;
            case 2:
                cout<<"Enter dimension (row,col)"<<endl;
                cin>>r>>c;
                m2.set_values(r, c);
                break;
            case 3:
                m3 = m1.add(m2);
                m3.print();
                break;
            case 4:
                m3.set_values(m1.r, m1.c);
                m3 = m1.sub(m2);
                m3.print();
                break;
            case 5:
                
                m3 = m1.mult(m2);
                m3.print();
                break;
            case 6:
                m1.print();
                m2.print();
                break;
            default:
                
                break;
        }
    }while (ch);
    cout<<"Vector Operation"<<endl;
    do{
        cout<<"Enter your choice 1. Enter v1 2. Enter v2 3. Add 4. Substract 5. Multiply 6. Print 7. Add Scalar 8. Multiply scalar 0. Terminate"<<endl;
        cin>>ch;
         m3.c = 1;
        switch (ch) {
            case 1:
                cout<<"Enter dimension"<<endl;
                cin>>r;
                v1.set_values(r, 1);
                break;
            case 2:
                cout<<"Enter dimension"<<endl;
                cin>>r;
                v2.set_values(r, 1);
                break;
            case 3:
                m3 = v1.add(v2);
                m3.print();
                break;
            case 4:
                m3 = v1.sub(v2);
                m3.print();
                break;
            case 5:
                v3 = v1.mult1(v2);
                v3.print();
                break;
            case 6:
                v1.print();
                v2.print();
                break;
            case 7: cout<<"Enter the scalar"<<endl;
                cin>>sc;
                v3 = v1.sc_add(sc);
                v3.print();
                break;
            case 8: cout<<"Enter the scalar"<<endl;
                cin>>sc;
                v3 = v1.sc_mult(sc);
                v3.print();
                break;
            default:
                break;
        }
    }while (ch);
    v3.print();
}
