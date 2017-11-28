//
//  tryCatchTest.cpp
//  LabC++
//
//  Created by Arnab Sen on 28/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class DataNotFoundException{
    string msg;
    int errcode;
public:
    DataNotFoundException(string a,int e){
        msg = a;
        errcode = e;
    }
    void dispCause(){
        cout<<"DataNotFoundException: "<<msg<<" with Error Code: "<<errcode<<endl;
    }
};


int main(){
    int a[100];
    cout<<"Enter the number of elements\n";
    int n,ser,i;
    cin>>n;
    cout<<"Enter the array\n";
    for(int i=0;i<n; i++) {
        cin>>a[i];
    }
    cout<<"Enter the number to search\n";
    cin>>ser;
    try{
        for (i=0; i<n; i++) {
            if(a[i]==ser){
                cout<<"Item Found at: "<<i<<endl;
                break;
            }
        }
        if(i==n){
            throw DataNotFoundException("Item Was not found",1);
        }
    }catch(DataNotFoundException e){
        
        e.dispCause();
    }
}
