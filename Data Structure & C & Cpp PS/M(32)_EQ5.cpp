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



void zigzag_order(Node* root){
    if(root==NULL)  return;

    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    bool leftToRight=true;

    currLevel.push(root);
    while(!currLevel.empty()){
        Node * temp=currLevel.top();
        currLevel.pop();

        if(temp!=NULL){
            cout<<temp->data<<" ";
            if(leftToRight==true){
                if(temp->leftChild != NULL){
                    nextLevel.push(temp->leftChild);
                }
                if(temp->rightChild != NULL){
                    nextLevel.push(temp->rightChild);
                }
            }
            else{
                if(temp->rightChild != NULL){
                    nextLevel.push(temp->rightChild);
                }
                if(temp->leftChild != NULL){
                    nextLevel.push(temp->leftChild);
                }
            }
        }
        if(currLevel.empty()){
            leftToRight=!leftToRight;
            swap(currLevel,nextLevel);
        }
    }
}


int main(){
    int n;
    cin>>n;
    Node* allNodes[n];
    for(int i=0;i<n;i++){
        allNodes[i]=new Node(-1);
    }
    for(int i=0;i<n;i++){
        int val,left,right;
        cin>>val>>left>>right;

        allNodes[i]->data=val;
        if(left!=-1){
            allNodes[i]->leftChild=allNodes[left];
        }
        if(right!=-1){
            allNodes[i]->rightChild=allNodes[right];
        }
    }

    zigzag_order(allNodes[0]);

    return 0;
}

/*

9
1 1 2
2 3 4
3 5 6
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1
9 -1 -1

*/

