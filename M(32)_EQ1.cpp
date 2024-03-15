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

void inOrderTraversal(Node* root,string &chk){
    if(root==NULL){
        return;
    }

    inOrderTraversal(root->leftChild,chk);
    chk+= to_string(root->data);
    inOrderTraversal(root->rightChild,chk);
}

bool isSame(Node* root1,Node* root2){
    string root1_traversal="";
    string root2_traversal="";
    inOrderTraversal(root1,root1_traversal);
    inOrderTraversal(root2,root2_traversal);

    return (root1_traversal==root2_traversal);
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
    Node *Node2[n];

    for(int i=0;i<n;i++){   //initially  set all data to -1.
        Node1[i]= new Node(-1);
        Node2[i]= new Node(-1);
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


     for(int i=0;i<n;i++){
        int value, left, right;
        cin>>value>>left>>right;
        Node2[i]->data=value;

//        if(left>n-1 || right>n-1){
//            cout<<"Invalid index"<<endl;
//            break;
//        }

        if(left!=-1){
            Node2[i]->leftChild=Node2[left];
        }

        if(right!=-1){
            Node2[i]->rightChild=Node2[right];
        }
    }

    if(isSame(Node1[0],Node2[0])){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

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



