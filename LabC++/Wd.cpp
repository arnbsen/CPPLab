//
//  Wd.cpp
//  LabC++
//
//  Created by Arnab Sen on 22/08/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
using namespace std;
class Node{
    public:
    long long int a[10000000001];
    long int p[10000001];
    long int index[10000001];
    long int root;
    void get_data(int n){
        for (int i=1; i<=n; i++) {
            scanf("%lld",&a[i]);
        }
        for (int i=1; i<=n; i++) {
            scanf("%ld",&p[i]);
        }
    }
    long long int find_max(long int i,long int seed){
        if (i==root){
            return seed>a[root]?seed:a[root];
        }else{
            seed = seed>a[i]?seed:a[i];
            return find_max(p[i], seed);
        }
    
    }
};


