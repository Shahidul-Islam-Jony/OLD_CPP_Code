#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *next;

    Node(int val)
    {
        value=val;
        next=NULL;
    }
};

void insertAtTail(Node* &head,int val)
{
    Node *newNode= new Node(val);
    if(head==NULL)
    {
        head=newNode;
        return ;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

void display(Node* head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->value;
        if(temp->next!=NULL)    cout<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

Node* removeZero(Node* head,int n)
{
    Node* zero=new Node(0);
    zero->next=head;
    Node *m[1000];
    m[0]=zero;
    int sum=0;
    while(head)
    {
        sum+=head->value;
        m[sum]=head;
        head=head->next;
    }
    head=zero;
    sum=0;
    while(head)
    {
        sum+=head->value;
        Node* temp=m[sum];

        if(temp!=head)
        {
            head->next=temp->next;
        }
        head=head->next;
    }
    return zero->next;
}


int main()
{
    Node *head=NULL;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int val;
        cin>>val;
        insertAtTail(head,val);
    }
    head=removeZero(head,n);

    cout<<endl;

    display(head);

    return 0;
}
