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

void level_order(Node* root){
    if(root==NULL)  return;
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* chkNode = q.front();
        q.pop();
        if(chkNode != NULL){
            cout<<chkNode->data<<" ";
            if(chkNode->leftChild != NULL){
                q.push(chkNode->leftChild);
            }
            if(chkNode->rightChild != NULL){
                q.push(chkNode->rightChild);
            }
        }
        else{
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}

int main(){
//
//    Node* root1=new Node(1);
//    Node* a1=new Node(2);
//    root1->leftChild=a1;
//
//    Node* root2=new Node(1);
//    Node* a2=new Node(2);
//    root2->rightChild=a2;

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


    level_order(Node1[0]);


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


Root: 0
Left:
    root: 1
    left: 3
    right: 4
Right:
    root: 2
    left:
        root: 5
        left: 7
        right: 8
    right: 6

*/


