#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node* left;
    Node* right;

    Node(int val){
        value=val;
        left=NULL;
        right=NULL;
    }
};

void print(Node* root){
    if(root==NULL)  return;
    print(root->left);
    cout<<root->value<<" ";
    print(root->right);
}


int main(){
    int a;
    cin>>a;
    Node* root=new Node(a);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* presentRoot=q.front();
        q.pop();
        int x,y;
        cin>>x>>y;
        Node* n1=NULL;
        Node* n2=NULL;

        if(x!=-1)   n1=new Node(x);
        if(y!=-1)   n2=new Node(y);
        presentRoot->left=n1;
        presentRoot->right=n2;

        if(n1!=NULL)    q.push(n1);
        if(n2!=NULL)    q.push(n2);
    }

    cout<<endl;
    print(root);
    cout<<endl;

    return 0;
}

