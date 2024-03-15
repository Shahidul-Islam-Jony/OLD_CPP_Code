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

void average_level(Node* root){
    if(root==NULL)  return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    float sum=0;
    int count=0;

    while(!q.empty()){
        Node* chkNode=q.front();
        q.pop();
        if(chkNode!=NULL){
            //cout<<chkNode->data<<" ";
            sum+=chkNode->data;
            count++;
            if(chkNode->leftChild!=NULL){
                q.push(chkNode->leftChild);
            }
            if(chkNode->rightChild!=NULL){
                q.push(chkNode->rightChild);
            }
        }
        else{
            cout<<sum/count<<" ";
            if(!q.empty()){
                q.push(NULL);
                count=0;
                sum=0;
            }
        }
    }
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

    average_level(allNodes[0]);

    return 0;
}


