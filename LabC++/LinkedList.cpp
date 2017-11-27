//
//  LinkedList.cpp
//  LabC++
//
//  Created by Arnab Sen on 03/08/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
class LL{
private:
    int val;
    
public:
    LL *point;
    LL();
    ~LL();
    LL insert(int val){
        LL temp;
        temp.val = val;
        temp.point = NULL;
        return temp;
    }
    void del(LL *point,int a) {
        LL *temp1 = point->point;
        LL *temp2 = point;
        while(temp1->point != NULL){
            if(temp1->val==a){
                temp2->point = temp1->point;
                temp1->~LL();
                break;
            }
            temp1 = temp1->point;
            temp2 = temp2->point;
        }
        
    }
    void traverse(LL *point){
        while (point->point != NULL) {
            std::cout<<point->val;
        }
    }
};
int main(int argc, const char * argv[]) {
    LL head;
       
    
}
