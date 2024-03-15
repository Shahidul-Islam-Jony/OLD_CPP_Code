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

void preOrderTraversal(binaryTree* root,string &chk){
    if(root==NULL)  return;
    chk+=to_string(root->val);
    preOrderTraversal(root->left,chk);
    preOrderTraversal(root->right,chk);
}

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int array[],int size,int current){
    int largest=current;
    int leftChild=2*current+1;
    int righttChild=2*current+2;
    if(leftChild<size && array[leftChild]>array[largest]){
        largest=leftChild;
    }
    if(righttChild<size && array[righttChild]>array[largest]){
        largest=righttChild;
    }
    if(largest != current){
        swap(array[current],array[largest]);
        heapify(array,size,largest);
    }
}

void heapSort(int array[],int size){
    for(int i=size-1;i>=0;i--){
        swap(array[0],array[i]);
        heapify(array,i,0);
    }
}

int main()
{
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

    string preOrder="";
    preOrderTraversal(root,preOrder);

    int size=preOrder.size();

    int array[size];
    for(int i=0;i<size;i++){
        array[i]=(int)preOrder[i]-'0';
    }
    int nonLeafStart=(size/2)-1;

    for(int i=nonLeafStart;i>=0;i--){
        heapify(array,size,i);
    }
    heapSort(array,size);

    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++){
        int a;
        cin>>a;
        if(a==1){
            int b;
            cin>>b;
            int sz=sizeof(array)/sizeof(array[0]);
            array[sz+1]=b;
            //heapSort(array,sz+1);
            for(int i=0;i<sz+1;i++){
                cout<<array[i]<<endl;
            }
        }
        if(a==2){

        }
    }

    return 0;
}

