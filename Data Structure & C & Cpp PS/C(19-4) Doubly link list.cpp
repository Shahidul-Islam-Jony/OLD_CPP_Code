#include<bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int val;
    doublyNode* prev;
    doublyNode *next;

    doublyNode(int val)
    {
        this->val=val;
        prev=NULL;
        next=NULL;
    }
};

void insertAtTail(doublyNode* &head, int val);
void insertAtHead(doublyNode* &head, int val);
void display(doublyNode *n);
int countLength(doublyNode* &head);
void displayReverse(doublyNode* &head);

void insertAtTail(doublyNode* &head,int val)
{
    doublyNode *newNode=new doublyNode(val);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    doublyNode* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void insertAtHead(doublyNode* &head,int val)
{
    // s1: new node creation..
    doublyNode *newNode=new doublyNode(val);
    //corner case..
    if(head==NULL){
        head=newNode;
        return;
    }
    // s2: update head prev ...
    head->prev=newNode;
    // s3: update newNode next..
    newNode->next=head;
    // s4: update head...
    head=newNode;
}

void display(doublyNode* n)
{
    while(n!=NULL)
    {
        cout<<n->val;
        if(n->next!=NULL)   cout<<"-->";
        n=n->next;
    }
    cout<<endl;
}

int countLength(doublyNode* &head)
{
    doublyNode *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void displayReverse(doublyNode* &head){
    doublyNode *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    while(temp!=NULL){
        cout<<temp->val;
        if(temp->prev!=NULL)    cout<<"-->";
        temp=temp->prev;
    }
    cout<<endl;
}

int main()
{
    doublyNode *head= NULL;

    int n,position;
    cout<<"Choice 1: Insertion at head "<<endl
        <<"Choice 2: Insertion at tail"<<endl
        <<"Choice 3: Display Reverse :"<<endl
        <<"Choice 0: Exit"<<endl;
    int choice;
    cout<<"Enter Choice : ";
    cin>>choice;
    while(choice!=0)
    {

        switch(choice)
        {
        case 1:
            cout<<"Enter the value : ";
            cin>>n;
            insertAtHead(head,n);
            break;
        case 2:
            cout<<"Enter the value : ";
            cin>>n;
            insertAtTail(head,n);
            break;

        case 3:
            displayReverse(head);
            break;

        default:
            break;
        }
        cout<<"Next choice : ";
        cin>>choice;
    }

    cout<<endl<<endl;
    cout<<"Doubly Link List : ";
    display(head);

    cout<<endl<<endl;
    cout<<"Length of the doubly link list : "<<countLength(head)<<endl;
    return 0;
}

