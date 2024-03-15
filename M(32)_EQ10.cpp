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

void inorderTraversal(Node* root, vector<int> &v)
{
        if(root==NULL)  return;

        inorderTraversal(root->leftChild,v);
        v.push_back(root->data);
        inorderTraversal(root->rightChild,v);
}

int second_minimum(Node* root)
{
    vector<int> v;
    inorderTraversal(root,v);

    sort(v.begin(),v.end());

    for (int i = 0; i <v.size()-1; i++){
        if(v[i]!=v[i+1]){
            return v[i+1];  //second minimum
        }
    }

    return -1;
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

    int a=second_minimum(allNodes[0]);
    cout<<a<<endl;

    return 0;
}

/*
5
2 1 2
2 -1 -1
5 3 4
5 -1 -1
7 -1 -1


3
2 1 2
2 -1 -1
2 -1 -1

*/

