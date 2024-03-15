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

void levelOrderTraversal(treeNode *root, string &chk){
    if(root==NULL){
        return;
    }

    queue<treeNode*> q; //,,stl er queue ,,,,, treeNode typer pointer.
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        treeNode* chkNode=q.front();
        q.pop();    //front k pop korte hobe.
        if(chkNode != NULL){
           // cout<<chkNode->data<<" ";     //function er modheei print korle.
            chk += to_string(chkNode->data);    // main function a print korle.
            chk += ' ';     // space soho main function a print korle.
            if(chkNode->leftChild != NULL){
                q.push(chkNode->leftChild);
            }
            if(chkNode->rightChild != NULL){
                q.push(chkNode->rightChild);
            }
        }
        else{   // chkNode==NULL
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }

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

    string levelOrder="";

    levelOrderTraversal(allNodes[0],levelOrder);

    cout<<levelOrder<<endl;

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

