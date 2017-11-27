//
//  binSearchTree.cpp
//  LabC++
//
//  Created by Arnab Sen on 03/11/17.
//  Copyright © 2017 Arnab Sen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class BinTree{
public:
    int item;
    BinTree* right;
    BinTree* left;
    BinTree(int i){
        item = i;
        right = NULL;
        left = NULL;
    }
    //Insertion (Operator Overloaded)
    void operator+(int i){
        BinTree* node = this;
        BinTree* node1 = NULL;
        while (node!=NULL) {
            node1 = node;
            if (node->item==i) {
                return;
            }
            if (i > node->item) {
                node = node->right;
            }else{
                node = node->left;
            }
        }
        if (i > node1->item ) {
            node1->right = new BinTree(i);
        }else{
            node1->left = new BinTree(i);
        }
    }
    //Inorder Traversal
    void inorder(BinTree* node){
        if(node!=NULL){
            inorder(node->left);
            cout<<node->item<<" ";
            inorder(node->right);
        }
    }
    //Preorder Traversal
    void preoder(BinTree* node){
        if(node!=NULL){
            cout<<node->item<<" ";
            preoder(node->left);
            preoder(node->right);
        }
    }
    //Postorder Traversal
    void postorder(BinTree* node){
        if(node!=NULL){
            postorder(node->left);
            postorder(node->right);
            cout<<node->item<<" ";
        }
    }
    //Extra Function for Finding Next Inorder Successor. Required for Delete
    BinTree* minValueNode(){
        BinTree* temp = this;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp;
    }
    //Node deletion (Operator Overloaded)
    BinTree* operator-(int z){
        BinTree* head = this;
        if(head==NULL){
            return head;
        }
        if (z < head->item) {
            head->left = *head->left-(z);
        }else if (z > head->item){
            head->right = *head->right-(z);
        }else{
            if (head->left==NULL) {
                BinTree* temp = head->right;
                head = NULL;
                return temp;
            }else if (head->right == NULL){
                BinTree* temp = head->left;
                head = NULL;
                return temp;
            }
            BinTree* temp = head->right->minValueNode();
            head->item = temp->item;
            head->right = *head->right-(temp->item);
            
            
        }
        return head;
        
    }
    //Find a value in the tree
    void search(int i){
        BinTree* temp = this;
        while (temp!=NULL&&temp->item!=i) {
            if(temp->item < i ){
                temp = temp->right;
            }else{
                temp = temp->left;
            }
        }
        if(temp!=NULL){
            cout<<"Match Found\n";
        }else{
            cout<<"Match Not Found\n";
        }
    }
};
int main(){
    BinTree* head = new BinTree(2); //Creating Root Node
    
    //Insertion
    *head+2;
    *head+10;
    *head+6;
    *head+4;
    *head+8;
    *head+12;
    
    //Traversals
    cout<<"Inorder Traversal"<<endl;
    head->inorder(head);
    cout<<endl;
    cout<<"Preorder Traversal"<<endl;
    head->preoder(head);
    cout<<endl;
    cout<<"Postorder Traversal"<<endl;
    head->postorder(head);
    cout<<endl;
    
    //Search
    head->search(2);
    
    //Delete
    *head-(10);
    
    //Check
    cout<<"After deletion (Inorder): ";
    head->inorder(head);
    cout<<"\n";
}
