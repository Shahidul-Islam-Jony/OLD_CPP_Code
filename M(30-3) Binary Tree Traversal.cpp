#include<bits/stdc++.h>
using namespace std;
class treeNode{
public:
    int data;
    treeNode *leftChild;
    treeNode *rightChild;

    treeNode(int value){
        data=value;
        leftChild=NULL;
        rightChild=NULL;
    }
};

void printTree(treeNode* root,int level);
void spacePrint(int level);
void inOrder(treeNode* root,string &chk);

void printTree(treeNode* root,int level){
    if(root==NULL){ //When tree is empty.
        return;
    }

    if(root->leftChild==NULL && root->rightChild==NULL){    //Case 1: if root is leaf node.
        cout<<root->data<<endl;
        return;
    }
    else{           //Case 2: when leftChild is root.
        cout<<endl;
        spacePrint(level);
        cout<<"Root: "<<root->data<<endl;
    }

    if(root->leftChild!=NULL)
    {
        spacePrint(level);
        cout<<"Left: ";
        printTree(root->leftChild,level+1);
    }

    if(root->rightChild!=NULL)
    {
        spacePrint(level);
        cout<<"Right: ";
        printTree(root->rightChild,level+1);
    }

}

void spacePrint(int level){
    for(int i=0;i<level;i++){
        cout<<"   ";
    }
}

void inOrder(treeNode* root,string &chk){   //Left Root Right

    if(root==NULL){
        return;
    }

    inOrder(root->leftChild,chk);
    chk+= to_string(root->data);    //protibar leftChild call howar por data add hobe.

    inOrder(root->rightChild,chk);
}

void preOrder(treeNode* root,string &chk){  //Root Left Right

    if(root==NULL){
        return;
    }

    chk+= to_string(root->data);

    preOrder(root->leftChild,chk);

    preOrder(root->rightChild,chk);
}

void postOrder(treeNode* root,string &chk){ //Left Right Root

    if(root==NULL){
        return;
    }

    postOrder(root->leftChild,chk);

    postOrder(root->rightChild,chk);

    chk+= to_string(root->data);
}


int main(){
    int n;
    cin>>n;

    treeNode *allNodes[n];  //creating pointer type array.

    for(int i=0;i<n;i++){   //initially  set all data to -1.
        allNodes[i]= new treeNode(-1);
    }

    for(int i=0;i<n;i++){
        int value, left, right;
        cin>>value>>left>>right;
        allNodes[i]->data=value;

        if(left>n-1 || right>n-1){
            cout<<"Invalid index"<<endl;
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
    cout<<endl;

    string inOrderTraversal=""; //chk string.
    string preOrderTraversal="";
    string postOrderTraversal="";

    inOrder(allNodes[0],inOrderTraversal);  // root and blank string ta k pathate hobe.
    preOrder(allNodes[0],preOrderTraversal);
    postOrder(allNodes[0],postOrderTraversal);

    cout<<"Inorder Traversal : "<<inOrderTraversal<<endl;
    cout<<"preOrder Traversal : "<<preOrderTraversal<<endl;
    cout<<"postOrder Traversal : "<<postOrderTraversal<<endl;

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


