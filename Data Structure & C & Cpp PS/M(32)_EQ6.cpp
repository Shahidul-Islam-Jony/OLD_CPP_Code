#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *leftChild;
    Node *rightChild;

    Node(int value){
        data=value;
        leftChild=NULL;
        rightChild=NULL;
    }
};

void space(int level){
    for(int i=0;i<level;i++){
        cout<<"   ";
    }
}

void printTree(Node* root,int level){
    if(root==NULL)  return;
    if(root->leftChild==NULL && root->rightChild==NULL){
        cout<<root->data;
        return;
    }
    else{
        cout<<endl;
        space(level);
        cout<<"Root : "<<root->data;
    }
    if(root->leftChild!=NULL){
        cout<<endl;
        space(level);
        cout<<"Left : ";
        printTree(root->leftChild,level+1);

    }
    if(root->rightChild!=NULL){
        cout<<endl;
        space(level);
        cout<<"Right : ";
        printTree(root->rightChild,level+1);
    }
}


Node* invert_tree(Node* root)
{
    if(root==NULL)  return 0;

    invert_tree(root->leftChild);
    invert_tree(root->rightChild);

    Node* temp;
    temp=root->leftChild;
    root->leftChild=root->rightChild;
    root->rightChild=temp;

    return root;
}

int main(){
    int n;
    cin>>n;

    Node *allNodes[n];

    for(int i=0;i<n;i++){
        allNodes[i]= new Node(-1);
    }

    for(int i=0;i<n;i++){
        int value, left, right;
        cin>>value>>left>>right;
        allNodes[i]->data=value;


        if(left!=-1){
            allNodes[i]->leftChild=allNodes[left];
        }

        if(right!=-1){
            allNodes[i]->rightChild=allNodes[right];
        }
    }

    Node* root = invert_tree(allNodes[0]);

    printTree(root,0);

    return 0;
}

/*

7
4 1 2
2 3 4
7 5 6
1 -1 -1
3 -1 -1
6 -1 -1
9 -1 -1

*/




