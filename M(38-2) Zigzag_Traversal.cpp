//M(38-2) Zigzag_Traversal
#include<bits/stdc++.h>
using namespace std;
class treeNode{
public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;

    treeNode(int val){
        data=val;
        leftChild=NULL;
        rightChild=NULL;
    }
};

void inOrderTraversal(treeNode* root,string &chk){
    if(root==NULL)  return;
    inOrderTraversal(root->leftChild,chk);
    chk += (to_string(root->data)+" ");
    inOrderTraversal(root->rightChild,chk);
}

treeNode* insertionBST(treeNode* root,int value){
    treeNode* newNode=new treeNode(value);
    if(root==NULL){
        root=newNode;
        return root;
    }
    // value < root->data
    if(value<root->data){
        root->leftChild = insertionBST(root->leftChild,value);
    }
    // value > root->data
    else if(value > root->data){
       root->rightChild = insertionBST(root->rightChild,value);
    }

    return root;
}


void zigzagTraversal(treeNode* root){
    stack<treeNode*> currentLevel;
    stack<treeNode*> nextLevel;

    bool leftToRight=true;
    currentLevel.push(root);
    while(!currentLevel.empty()){
        treeNode* x=currentLevel.top();
        currentLevel.pop();

        cout<<x->data<<" ";
        if(leftToRight==true){
            if(x->leftChild!=NULL){
                nextLevel.push(x->leftChild);
            }
            if(x->rightChild){
                nextLevel.push(x->rightChild);
            }
        }
        else{   //when leftToRight=false
            if(x->rightChild)   nextLevel.push(x->rightChild);
            if(x->leftChild)    nextLevel.push(x->leftChild);
        }


        if(currentLevel.empty()){
            leftToRight=!leftToRight;   //false korle hobe na.Karon left to right ekbar true r ekbar false hobe.
            swap(currentLevel,nextLevel);
        }
    }
}

int main(){
    int n;
    cin>>n;
    treeNode* root=NULL;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        root=insertionBST(root,value);
    }

    string Traversal="";
    inOrderTraversal(root,Traversal);
    cout<<Traversal<<endl;

    zigzagTraversal(root);
    return 0;
}

/*
9
11 5 9 43 34 1 2 7 21

*/

