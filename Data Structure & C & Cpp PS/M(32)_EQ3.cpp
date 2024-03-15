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

void level_order_reverse(Node* root)
{
    if(root==NULL)  return;
    stack<Node*> st;
    queue<Node*> q;

    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        st.push(temp);

        if(temp->rightChild != NULL)
        {
            q.push(temp->rightChild);
        }
        if(temp->leftChild != NULL)
        {
            q.push(temp->leftChild);
        }
    }

    while(!st.empty())
    {
        root=st.top();
        st.pop();
        cout<<root->data<<" ";
    }
}


int main(){
    int n;
    cin>>n;

    Node *Node1[n];  //creating pointer type array.

    for(int i=0;i<n;i++){   //initially  set all data to -1.
        Node1[i]= new Node(-1);
    }

    for(int i=0;i<n;i++){
        int value, left, right;
        cin>>value>>left>>right;
        Node1[i]->data=value;


        if(left!=-1){
            Node1[i]->leftChild=Node1[left];
        }

        if(right!=-1){
            Node1[i]->rightChild=Node1[right];
        }
    }

    level_order_reverse(Node1[0]);


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


