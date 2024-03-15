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

void printK(Node *root, int k)
{
    static int count=0;
    if(root==NULL)
    {
        return;
    }
    if(count<=k)
    {
        printK(root->leftChild,k);
        count++;
        cout<<"Count : "<<count<<endl;
        cout<<"Root->data : "<<root->data<<endl;
        if(count==k)
        {
            cout<<root->data;
            return;
        }
        printK(root->rightChild,k);

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

    printK(allNodes[1],k);

    return 0;
}

/*

5 3
0 1 2
1 -1 -1
2 3 4
3 -1 -1
4 -1 -1


*/

/*

9 5
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



