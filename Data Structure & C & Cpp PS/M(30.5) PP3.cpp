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

void printLevelWise(Node* root,int level)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<endl;
    level++;
    printLevelWise(root->leftChild,level);
    printLevelWise(root->rightChild,level);
}

int main()
{
    int n;
    cin>>n;
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

    printLevelWise(allNodes[1],1);
    cout<<endl;

    return 0;
}

