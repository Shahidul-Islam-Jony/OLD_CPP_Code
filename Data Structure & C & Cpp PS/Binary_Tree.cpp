#include<bits/stdc++.h>
using namespace std;
class treeNode{
public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;

    treeNode(int val){
        data=val;
        leftChild=NULL;
        rightChild=NULL;
    }
};

void space(int level){
    for(int i=0;i<level;i++){
        cout<<"   ";
    }
}

void printTree(treeNode* root,int level){
    if(root==NULL)  return;
    if(root->leftChild==NULL && root->rightChild==NULL){
        cout<<root->data;
        return;
    }
    else{
        cout<<endl;
        space(level);
        cout<<"Root : "<<root->data;
    }
    if(root->leftChild!=NULL){
        cout<<endl;
        space(level);
        cout<<"Left : ";
        printTree(root->leftChild,level+1);

    }
    if(root->rightChild!=NULL){
        cout<<endl;
        space(level);
        cout<<"Right : ";
        printTree(root->rightChild,level+1);
    }
}

void inOrderTraversal(treeNode* root,string &chk){
    if(root==NULL)  return;
    inOrderTraversal(root->leftChild,chk);
    chk += (to_string(root->data)+" ");
    inOrderTraversal(root->rightChild,chk);
}

void preOrderTraversal(treeNode* root,string &chk){
    if(root==NULL)  return;
    chk += (to_string(root->data)+" ");
    preOrderTraversal(root->leftChild,chk);
    preOrderTraversal(root->rightChild,chk);
}

void postOrderTraversal(treeNode* root,string &chk){
    if(root==NULL)  return;
    postOrderTraversal(root->leftChild,chk);
    postOrderTraversal(root->rightChild,chk);
    chk += (to_string(root->data)+" ");
}

int levelOrderTraversal(treeNode* root,string &chk,int k){
    if(root==NULL)  return -1;
    int level=0;
    queue<treeNode*> q;
    q.push(root);
    q.push(NULL);
    int max=INT_MIN;
    while(!q.empty()){
        treeNode* chkNode = q.front();
        q.pop();
        if(chkNode!=NULL){
//            chk += to_string(chkNode->data);
//            chk += " ";
            if(level==k){
                if(max<chkNode->data){
                    max=chkNode->data;
                }
            }
            if(chkNode->leftChild!=NULL){
                q.push(chkNode->leftChild);
            }
            if(chkNode->rightChild!=NULL){
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
    return max;
}

//Boundary Traversal
void printLeaves(treeNode* root){
    if(root==NULL)  return;
    if(root->leftChild==NULL && root->rightChild==NULL){
        cout<<root->data<<" ";
        return;
    }
    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}

void printLeftNonLeaves(treeNode* root){
    if(root==NULL)  return;
    if(root->leftChild!=NULL){
        cout<<root->data<<" ";
        printLeftNonLeaves(root->leftChild);
    }
    else if(root->rightChild!=NULL){
        cout<<root->data<<" ";
        printLeftNonLeaves(root->rightChild);
    }
}

void printRightNonLeaves(treeNode* root){
    if(root==NULL)  return;
    if(root->rightChild!=NULL){
        cout<<root->data<<" ";
        printRightNonLeaves(root->rightChild);
    }
    else if(root->leftChild!=NULL){
        cout<<root->data<<" ";
        printRightNonLeaves(root->leftChild);
    }
}

void boundaryTraversal(treeNode* root){
    if(root==NULL)  return;
    cout<<root->data<<" ";
    //LB Non-Leaves
    printLeftNonLeaves(root->leftChild);
    //LB Leaves
    printLeaves(root->leftChild);
    //RB Leaves
    printLeaves(root->rightChild);
    //RB Non-Leaves
    printRightNonLeaves(root->rightChild);
}


int main(){
    int n; //,k;
    cin>>n; //>>k;
    treeNode* allNodes[n];
    for(int i=0;i<n;i++){
        allNodes[i]=new treeNode(-1);
    }
    for(int i=0;i<n;i++){
        int val,leftChild,rightChild;
        cin>>val>>leftChild>>rightChild;

        allNodes[i]->data=val;
        if(leftChild!=-1){
            allNodes[i]->leftChild=allNodes[leftChild];
        }
        if(rightChild!=-1){
            allNodes[i]->rightChild=allNodes[rightChild];
        }
    }

    printTree(allNodes[0],0);
    cout<<endl<<endl;

    string inOrder="";
    string preOrder="";
    string postOrder="";
   // string levelOrder="";

    inOrderTraversal(allNodes[0],inOrder);
    preOrderTraversal(allNodes[0],preOrder);
    postOrderTraversal(allNodes[0],postOrder);
    //levelOrderTraversal(allNodes[0],levelOrder);
    //int Max=levelOrderTraversal(allNodes[0],levelOrder,k);

    cout<<"InOrder Traversal : "<<inOrder<<endl;
    cout<<"preOrder Traversal : "<<preOrder<<endl;
    cout<<"postOrder Traversal : "<<postOrder<<endl;
   // cout<<"levelOrder Traversal : "<<levelOrder<<endl;
    //cout<<"Max = "<<Max<<endl<<endl;


    boundaryTraversal(allNodes[0]);
    cout<<endl;

    return 0;
}

/*

9 3
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1


11
15 1 2
11 3 4
26 5 6
8 7 8
12 -1 9
20 -1 -1
30 -1 10
6 -1 -1
9 -1 -1
14 -1 -1
35 -1 -1


*/
