#include<bits/stdc++.h>
using namespace std;
class binaryTree
{
public:
    int val;
    binaryTree* left;
    binaryTree* right;
    binaryTree(int val)
    {
        this->val=val;
        left=NULL;
        right=NULL;
    }
};

void rootToLeaf(binaryTree* root,vector<int> path,vector<vector<int>> &allPaths){
    if(root==NULL)  return;
    path.push_back(root->val);
    if(root->left==NULL && root->right==NULL){
        allPaths.push_back(path);
    }
    rootToLeaf(root->left,path,allPaths);
    rootToLeaf(root->right,path,allPaths);
}

int main()
{
    string s;
    cin>>s;

    int val;
    cin>>val;
    binaryTree* root=new binaryTree(val);

    queue<binaryTree*> q;
    q.push(root);
    while(!q.empty())
    {
        binaryTree* presentRoot=q.front();
        q.pop();
        int x,y;
        cin>>x>>y;

        binaryTree* n1=NULL;
        binaryTree* n2=NULL;

        if(x!=-1)
        {
            n1=new binaryTree(x);
        }
        if(y!=-1)
        {
            n2=new binaryTree(y);
        }
        presentRoot->left=n1;
        presentRoot->right=n2;

        if(n1!=NULL)    q.push(n1);
        if(n2!=NULL)    q.push(n2);
    }

    vector<int>path;
    vector<vector<int>>allPaths;

    rootToLeaf(root,path,allPaths);

    int count=0;
    for(auto path: allPaths){
        string chk="";
        for(auto val:path){
            chk+=s[val];
        }
        //cout<<chk<<endl;
        int i=0;
        int j=chk.length()-1;
        int flag=0;
        while(i<j){
            if(chk[i] != chk[j]){
                flag=1;
                break;
            }
            i++;
            j--;
        }
        if(flag==0){
        count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
