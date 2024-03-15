#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* leftChild;
    Node* rightChild;

    Node(int val)
    {
        data=val;
        leftChild=NULL;
        rightChild=NULL;
    }
};

void printPostK(Node *root,int k){
    if(root==NULL){
        return;
    }
    static int count=0;
    if(count<=k){
        printPostK(root->leftChild,k);
        printPostK(root->rightChild,k);
        count++;
        if(count==k){
            cout<<root->data<<endl;
            return;
        }
    }

}


int main()
{
    int n,k;
    cin>>n>>k;
    Node* allNodes[n];
    for(int i=1; i<=n; i++)
    {
        allNodes[i]=new Node(-1);
    }

    for(int i=1; i<=n; i++)
    {
        int val,left,right;
        cin>>val>>left>>right;

        allNodes[i]->data=val;
        if(left>n || right>n)
        {
            cout<<"Invalid index"<<endl;
            break;
        }
        if(left!=-1)
        {
            allNodes[i]->leftChild=allNodes[left];
        }
        if(right!=-1)
        {
            allNodes[i]->rightChild=allNodes[right];
        }

    }
    cout<<endl;

    printPostK(allNodes[1],k);
    cout<<endl;

    return 0;
}

