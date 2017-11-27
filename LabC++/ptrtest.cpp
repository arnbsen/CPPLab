//
//  ptrtest.cpp
//  LabC++
//
//  Created by Arnab Sen on 27/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of vertices\n";
    cin>>n;
    int **adj = nullptr;
    adj = new int*[n];

    for (int i=0; i<n; i++) {
        adj[i] = new int[n];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>adj[i][j];
        }
        
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    
}
