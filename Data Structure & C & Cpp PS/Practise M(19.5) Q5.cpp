#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node* Next;

    Node(int val)
    {
        this->val=val;
        Next=NULL;
    }
};

void insertAtTail(Node* &head,int val)
{
    Node *newNode=new Node(val);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    Node *temp=head;
    while(temp->Next!=NULL)
    {
        temp=temp->Next;
    }
    temp->Next=newNode;
}

void display(Node *n,int k,int len)
{
    int count=0;
    int x=len-k;
    while(n!=NULL)
    {
        if(count>=x){
            cout<<n->val;
        }

        if(n->Next!=NULL && count>=x)   cout<<"-> ";
        count++;
        n=n->Next;
    }
    cout<<endl;
}

Node* reverseRecursive(Node* &head)
{
    /* if(head==NULL){
         cout<<"List is empty"<<endl;
         return head;
     }*/
    int count=0;

    //base call..
    if(head->Next==NULL)
    {
        return head;
    }
        Node* newHead=reverseRecursive(head->Next);
        head->Next->Next=head;
        head->Next=NULL;
        return newHead;
}

int main()
{
    Node *head=NULL;
    int n,q;
    cin>>n>>q;
    for(int i=0; i<n; i++)
    {
        int val;
        cin>>val;
        insertAtTail(head,val);
    }
    head=reverseRecursive(head);
    for(int i=0; i<q; i++)
    {
        int k;
        cin>>k;
        display(head,k,n);
    }

    return 0;
}

