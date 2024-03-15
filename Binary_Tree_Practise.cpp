#include<bits/stdc++.h>
using namespace std;
class treeNode{
public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;

    treeNode(int value){
        data = value;
        leftChild=NULL;
        rightChild=NULL;
    }
};

void spacePrint(int level){
    for(int i=0;i<level;i++){
        cout<<"   ";
    }
}

void printTree(treeNode* root,int level){
    if(root==NULL){
        return;
    }
    if(root->leftChild==NULL && root->rightChild==NULL){
        cout<<root->data;
        return;
    }
    else{
        cout<<endl;
        spacePrint(level);
        cout<<"Root : "<<root->data;

    }
    if(root->leftChild!=NULL){
        cout<<endl;
        spacePrint(level);
        cout<<"Left : ";
        printTree(root->leftChild,level+1);
    }
    if(root->rightChild!=NULL){
        cout<<endl;
        spacePrint(level);
        cout<<"Right : ";
        printTree(root->rightChild,level+1);
    }

}

void inOrderTraversal(treeNode* root,string &chk){
    if(root==NULL)  return;

    inOrderTraversal(root->leftChild,chk);
    chk += to_string(root->data);
    inOrderTraversal(root->rightChild,chk);

}

void preOrderTraversal(treeNode* root,string &chk){
    if(root==NULL)  return;

    chk += to_string(root->data);
    preOrderTraversal(root->leftChild,chk);
    preOrderTraversal(root->rightChild,chk);

}

void postOrderTraversal(treeNode* root,string &chk){
    if(root==NULL)  return;

    postOrderTraversal(root->leftChild,chk);
    postOrderTraversal(root->rightChild,chk);
    chk += to_string(root->data);

}


int levelOrderTraversal(treeNode* root,string &chk,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    int level=0;

    queue<treeNode*> q;
    q.push(root);
    q.push(NULL);
    int sum=0;
    while(!q.empty())
    {
        treeNode* chkNode=q.front();
        q.pop();
        if(chkNode!=NULL)
        {
            chk+=to_string(chkNode->data);
            chk +=" ";
            if(level==k){
                sum+=chkNode->data;
            }

            if(chkNode->leftChild!=NULL)
            {
                q.push(chkNode->leftChild);
            }
            if(chkNode->rightChild!=NULL)
            {
                q.push(chkNode->rightChild);
            }
        }
        else{
            if(!q.empty()){
                q.push(NULL);
                level++;
            }
        }
    }
    return sum;
}

int main(){
    int n,k;
    cin>>n>>k;
    treeNode *allNodes[n];
    for(int i=0;i<n;i++){
        allNodes[i]=new treeNode(-1);
    }
    for(int i=0;i<n;i++){
        int value,left,right;
        cin>>value>>left>>right;

        allNodes[i]->data=value;
        if(left>n-1 || right>n-1){
            cout<<"Invalid input "<<endl;
            break;
        }
        if(left!=-1){
            allNodes[i]->leftChild=allNodes[left];
        }
        if(right!=-1){
            allNodes[i]->rightChild=allNodes[right];
        }
    }

    printTree(allNodes[0],0);
    cout<<endl<<endl;

    string inOrder="";
    string preOrder="";
    string postOrder="";
    string levelOrder="";

    inOrderTraversal(allNodes[0],inOrder);
    preOrderTraversal(allNodes[0],preOrder);
    postOrderTraversal(allNodes[0],postOrder);
    int Sum=levelOrderTraversal(allNodes[0],levelOrder,k);

    cout<<"INORDER : "<<inOrder<<endl;
    cout<<"PREORDER : "<<preOrder<<endl;
    cout<<"POSTORDER : "<<postOrder<<endl;
    cout<<"Level Order Traversal : "<<levelOrder<<endl<<endl;
   // cout<<"Max = "<<Max<<endl;
    cout<<"SUM = "<<Sum<<endl<<endl;
    return 0;
}

/*
9 2
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

