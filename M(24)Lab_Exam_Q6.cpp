#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;

    Node(int val)
    {
        value=val;
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

Node *Replace(Node* &head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        if(temp->value%2==0)
        {
            temp->value=-1;
        }
        temp=temp->Next;
    }
    return head;
}

void display(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->value;
        if(temp->Next!=NULL)    cout<<" -> ";
        temp=temp->Next;
    }
    cout<<endl;
}

int main()
{
    Node *head=NULL;
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int value;
        cin>>value;
        insertAtTail(head,value);
    }
    Replace(head);
    display(head);
}
