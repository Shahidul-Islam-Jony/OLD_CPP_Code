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

void leftSubTree(Node* root,string &leftValue){
    if(root==NULL)  return;
    leftSubTree(root->leftChild,leftValue);
    leftValue += to_string(root->data);
    leftSubTree(root->rightChild,leftValue);
}

void rightSubTree(Node* root,string &rightValue){
    if(root==NULL)  return;
    rightSubTree(root->rightChild,rightValue);
    rightValue += to_string(root->data);
    rightSubTree(root->leftChild,rightValue);
}

bool isSymmetric(Node* root){
    if(root==NULL)  return false;

    string leftValue=to_string(root->data);
    string rightValue=to_string(root->data);

    leftSubTree(root->leftChild,leftValue);
    rightSubTree(root->rightChild,rightValue);

    return  (leftValue==rightValue);
}


int main(){
    int n;
    cin>>n;

    Node *allNodes[n];  //creating pointer type array.

    for(int i=0;i<n;i++){   //initially  set all data to -1.
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

    if(isSymmetric(allNodes[0])){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }


    return 0;
}

/*

7
1 1 2
2 3 4
2 5 6
3 -1 -1
4 -1 -1
4 -1 -1
3 -1 -1


5
1 1 2
2 -1 3
2 -1 4
3 -1 -1
3 -1 -1

*/



