#include<bits/stdc++.h>
using namespace std;
class doublyNode
{
public:
    int val;
    doublyNode* prev;
    doublyNode* next;

    doublyNode(int val)
    {
        this->val=val;
        prev=NULL;
        next=NULL;
    }
};

void insertAtHead(doublyNode* &head,int val)
{
    doublyNode *newNode=new doublyNode(val);
    if(head==NULL){
        head=newNode;
        return;
    }
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}

void insertAtTail(doublyNode* &head,int val){
    doublyNode *newNode=new doublyNode(val);
    if(head==NULL){
        head=newNode;
        return;
    }
    doublyNode *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void display(doublyNode* n)
{
    while(n!=NULL)
    {
        cout<<n->val;
        if(n->next!=NULL)   cout<<"-->>";
        n=n->next;
    }
    cout<<endl;
}

int main()
{
    doublyNode* head=NULL;
    int val;

    cout<<"Choice 1: Insert at head: "<<endl
        <<"Choice 2: Insert at tail: "<<endl
        <<"Choice 0: Exit"<<endl;

    int choice;
    cout<<"Enter Choice : ";
    cin>>choice;

    while(choice!=0)
    {
        switch(choice)
        {
        case 1:
            cout<<"Enter value : ";
            cin>>val;
            insertAtHead(head,val);
            break;

        case 2:
            cout<<"Enter value : ";
            cin>>val;
            insertAtTail(head,val);
            break;

        default:
            break;
        }
        cout<<"Next choice:";
        cin>>choice;
    }
    cout<<endl;
    cout<<"Doubly link list is : ";
    display(head);
    cout<<endl;

    return 0;
}
