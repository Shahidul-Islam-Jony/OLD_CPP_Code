#include<bits/stdc++.h>
using namespace std;
class treeNode
{
public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;

    treeNode(int value)
    {
        data = value;
        leftChild=NULL;
        rightChild=NULL;
    }
};


int maxDepth(treeNode* root)
{
    if(root==NULL)  return 0;
    int x=maxDepth(root->leftChild);
    int y=maxDepth(root->rightChild);

    return max(x,y)+1;
}

int main()
{
    int n;
    cin>>n;
    treeNode *allNodes[n];
    for(int i=0; i<n; i++)
    {
        allNodes[i]=new treeNode(-1);
    }
    for(int i=0; i<n; i++)
    {
        int value,left,right;
        cin>>value>>left>>right;

        allNodes[i]->data=value;
        if(left>n-1 || right>n-1)
        {
            cout<<"Invalid input "<<endl;
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

    int x=maxDepth(allNodes[0]);
    cout<<x<<endl;

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
