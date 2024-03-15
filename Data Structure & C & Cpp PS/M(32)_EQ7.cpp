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

int findSum(Node* root,int &sum){
    if(root==NULL)  return 0;

    int left=findSum(root->leftChild,sum);
    int right=findSum(root->rightChild,sum);
    sum += abs(left-right);

    return left+right+root->data;
}

int findTilt(Node* root){
    if(root==NULL) return 0;
    int totalSum=0;
    findSum(root,totalSum);

    return totalSum;
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

    int abc=findTilt(allNodes[0]);
    cout<<abc<<endl;

    return 0;
}

/*

3
1 1 2
2 -1 -1
3 -1 -1

6
4 1 2
2 3 4
9 -1 5
3 -1 -1
5 -1 -1
7 -1 -1

*/

