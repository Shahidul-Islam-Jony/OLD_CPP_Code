#include<bits/stdc++.h>
using namespace std;

class treeNode{
public:
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void inOrderTraversal(treeNode* root, string &chk){
    if(root==NULL)  return;
    inOrderTraversal(root->left,chk);
    chk+=(to_string(root->data)+" ");
    inOrderTraversal(root->right,chk);
}

treeNode* insertionBST(treeNode* root,int val){
    treeNode* newNode=new treeNode(val);
    if(root==NULL){
        root=newNode;
        return root;
    }
    else if(val<root->data){
        root->left=insertionBST(root->left,val);
    }
    else if(val>root->data){
        root->right=insertionBST(root->right,val);
    }
    return root;
}

treeNode* searchBST(treeNode*root,int val){
  if(root==NULL)    return root;
  if(val==root->data){
    cout<<root->data<<" ";
  }
  else if(val<root->data){
    cout<<root->data<<" ";
    searchBST(root->left,val);
  }
  else{
    cout<<root->data<<" ";
    searchBST(root->right,val);
  }
}

treeNode* deletionBST(treeNode* root,int val){
    if(root==NULL)  return root;
    if(val<root->data){
        root->left=deletionBST(root->left,val);
    }
    else if(val>root->data){
        root->right=deletionBST(root->right,val);
    }
    else{
        if(root->left==NULL){
            treeNode* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            treeNode* temp=root->left;
            free(root);
            return temp;
        }
        else{
            treeNode* temp=inOrderSucc(root->right);
            root->data=temp->data;

        }
    }
}


int main(){
    int n;
    cin>>n;
    treeNode* root=NULL;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        root=insertionBST(root,val);
    }
    string inOrder="";
    inOrderTraversal(root,inOrder);
    cout<<inOrder<<endl;

    int key;
    cin>>key;
//    if(searchBST(root,key)==NULL){
//        cout<<"Value does not exits"<<endl;
//    }
//    else{
//        cout<<"Value Exists "<<endl;
//    }

    deletionBST(root,key);

    return 0;
}
