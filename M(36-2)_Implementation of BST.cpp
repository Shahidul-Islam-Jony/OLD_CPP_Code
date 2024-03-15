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

treeNode* insertionBST(treeNode* root,int value){
    treeNode* newNode=new treeNode(value);
    if(root==NULL){
        root=newNode;
        return root;
    }
    // value < root->data
    if(value<root->data){
        root->leftChild = insertionBST(root->leftChild,value);
    }
    // value > root->data
    else if(value > root->data){
       root->rightChild = insertionBST(root->rightChild,value);
    }

    return root;
}

treeNode* searchBST(treeNode* root,int value){
    if(root==NULL){
        return NULL;
    }
    if(root->data==value){
        cout<<root->data<<endl;
        return root;
    }
    else if(value<root->data){
        cout<<root->data<<"->";     //protibar root change hobe
        searchBST(root->leftChild,value);
    }
    else{
        cout<<root->data<<"->";
        searchBST(root->rightChild,value);
    }
}

treeNode* inordersucc(treeNode* root){
    treeNode* current=root;
    while(current->leftChild!=NULL){
        current=current->leftChild;
    }
    return current;
}

treeNode* deletionBST(treeNode* root, int value){
    if(value<root->data){
        root->leftChild=deletionBST(root->leftChild,value);
    }
    else if(value>root->data){
        root->rightChild=deletionBST(root->rightChild,value);
    }
    else{
        //Implementation of three case : ---->
        if(root->leftChild == NULL){
            treeNode* temp=root->rightChild;
            free(root);
            return temp;
        }
        else if(root->rightChild == NULL){
            treeNode* temp=root->leftChild;
            free(root);
            return temp;
        }
        else{
                //case 3
            treeNode* temp= inordersucc(root->rightChild);  //inOrder successor sobsomoy right a thake.
            root->data=temp->data;  // replace node which you want to delete by successor
            root->rightChild=deletionBST(root->rightChild,temp->data); //jodi temp data er por a ro node thake.
        }

        return root;
    }
}

int main(){
    int n;
    cin>>n;
    treeNode* root=NULL;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        root=insertionBST(root,value);
    }

    string Traversal="";
    inOrderTraversal(root,Traversal);
    cout<<Traversal<<endl;

    int key;
    cin>>key;
    if(searchBST(root,key) == NULL){
        cout<<"Value does Not exits in BST";
    }
    else{
        cout<<"Value Exits in BST";
    }

//    root=deletionBST(root,key);
//    string after="";
//    inOrderTraversal(root,after);
//    cout<<after<<endl;

    cout<<endl<<endl;

    return 0;
}

/*
9
11 5 9 43 34 1 2 7 21

*/

