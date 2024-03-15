#include<bits/stdc++.h>
using namespace std;
class treeNode{
public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;

    treeNode(int value){
        data = value;
        leftChild=NULL;
        rightChild=NULL;
    }
};

void printLeftNonLeaves(treeNode* root){
    if(root==NULL)  return;
    if(root->leftChild!=NULL){
        cout<<root->data<<" ";
        printLeftNonLeaves(root->leftChild);
    }
    else if(root->rightChild!=NULL){
        cout<<root->data<<" ";
        printLeftNonLeaves(root->rightChild);
    }
}

void printLeaves(treeNode* root){
    if(root==NULL)  return;
    if(root->leftChild==NULL && root->rightChild==NULL){
        cout<<root->data<<" ";
        return;
    }
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}

void printRightNonLeaves(treeNode* root){
    if(root==NULL)  return;
    if(root->rightChild!=NULL){
        cout<<root->data<<" ";
        printRightNonLeaves(root->rightChild);
    }
    else if(root->leftChild!=NULL){
        cout<<root->data<<" ";
        printRightNonLeaves(root->leftChild);
    }
}

void boundaryTraversal(treeNode* root){
    if(root==NULL)  return;
    cout<<root->data<<" ";
    //LB Non-Leaves
    printLeftNonLeaves(root->leftChild);
    //LB Leaves
    printLeaves(root->leftChild);
    //RB Leaves
    printLeaves(root->rightChild);
    //RB Non-Leaves
    printRightNonLeaves(root->rightChild);
}

int main(){
    int n;
    cin>>n;
    treeNode *allNodes[n];
    for(int i=0;i<n;i++){
        allNodes[i]=new treeNode(-1);
    }
    for(int i=0;i<n;i++){
        int value,left,right;
        cin>>value>>left>>right;

        allNodes[i]->data=value;
        if(left>n-1 || right>n-1){
            cout<<"Invalid input "<<endl;
            break;
        }
        if(left!=-1){
            allNodes[i]->leftChild=allNodes[left];
        }
        if(right!=-1){
            allNodes[i]->rightChild=allNodes[right];
        }
    }

    boundaryTraversal(allNodes[0]);

    return 0;
}

/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

 */


