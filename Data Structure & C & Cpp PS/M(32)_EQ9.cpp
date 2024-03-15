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

bool is_unival(Node* root)
{
    if(root==NULL)  return true;
    queue<Node*> q;
    q.push(root);

    int rootVal = root->data;
    while (!q.empty()) {
        Node* chkNode = q.front();

        if (chkNode->data != rootVal) {
            return false;
        }
        if (chkNode->leftChild != NULL) {
            q.push(chkNode->leftChild);
        }
        if (chkNode->rightChild != NULL) {
            q.push(chkNode->rightChild);
        }

        q.pop();
    }
    return true;
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

    if(is_unival(allNodes[0])){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}



