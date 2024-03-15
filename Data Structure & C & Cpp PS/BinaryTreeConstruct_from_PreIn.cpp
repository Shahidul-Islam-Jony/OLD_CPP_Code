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

void spacePrint(int level){
    for(int i=0;i<level;i++){
        cout<<"   ";
    }
}

void printTree(treeNode* root,int level){
    if(root==NULL){
        return;
    }
    if(root->leftChild==NULL && root->rightChild==NULL){
        cout<<root->data;
        return;
    }
    else{
        cout<<endl;
        spacePrint(level);
        cout<<"Root : "<<root->data;

    }
    if(root->leftChild!=NULL){
        cout<<endl;
        spacePrint(level);
        cout<<"Left : ";
        printTree(root->leftChild,level+1);
    }
    if(root->rightChild!=NULL){
        cout<<endl;
        spacePrint(level);
        cout<<"Right : ";
        printTree(root->rightChild,level+1);
    }

}


int searchPosFromInOrder(int inOrder[],int current, int start,int end){
    for(int i=start;i<=end;i++){
        if(current==inOrder[i]){
            return i;
        }
    }
    return -1;
}


treeNode* buildBinaryTreePreIn(int preOrder[],int inOrder[],int start,int end){
    static int id=0;
    int current=preOrder[id];
    id++;
    treeNode *newNode=new treeNode(current);
    if(start==end){
        return newNode;
    }
    int pos=searchPosFromInOrder(inOrder,current,start,end);

    newNode->leftChild= buildBinaryTreePreIn(preOrder,inOrder,start,pos-1);
    newNode->rightChild= buildBinaryTreePreIn(preOrder,inOrder,pos+1,end);

    return newNode;
}

int main(){
    int n;
    cin>>n;
    int preOrder[n],inOrder[n];
    for(int i=0;i<n;i++){
        cin>>preOrder[i];
    }
    for(int i=0;i<n;i++){
        cin>>inOrder[i];
    }

    treeNode *root=buildBinaryTreePreIn(preOrder,inOrder,0,n-1);

    printTree(root,0);
    cout<<endl;

    return 0;
}

/*
9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6

*/

