
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

Node *retainM_deleteN(Node* &head,int M,int N)
{
    Node* temp=head;
    Node* saveTemp=NULL;
    while(temp!=NULL)
    {
        for(int i=0; i<M; i++)
        {
            saveTemp=temp;
            if(temp->Next!=NULL)
            {
                temp=temp->Next;
            }
        }
        temp=saveTemp;
        for(int i=0; i<N; i++)
        {
            if(temp->Next!=NULL)
            {
                Node *delNode=temp->Next;
                temp->Next=delNode->Next;
                delete delNode;
            }
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
    int K,M,N;
    cin>>K>>M>>N;

    for(int i=0; i<K; i++)
    {
        int value;
        cin>>value;
        insertAtTail(head,value);
    }
    head=retainM_deleteN(head,M,N);

    display(head);

    return 0;
}
