#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* Next;

    Node(int val){
        this->val=val;
        Next=NULL;
    }
};

void insertAtTail(Node* &head,int val){
     Node *newNode=new Node(val);
     if(head==NULL){
        head=newNode;
        return;
     }
     Node *temp=head;
     while(temp->Next!=NULL){
        temp=temp->Next;
     }
     temp->Next=newNode;
}

void display(Node *n){
    while(n!=NULL){
        if(n->val%2==0){
            n->val=-1;
        }
        cout<<n->val;
        if(n->Next!=NULL)   cout<<"-> ";
        n=n->Next;
    }
    cout<<endl;
}
int main(){
    Node *head=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        insertAtTail(head,val);
    }

    display(head);

    return 0;
}
