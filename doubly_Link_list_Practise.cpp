#include<bits/stdc++.h>
using namespace std;

class doublyNode
{
public:
    int value;
    doublyNode *next;
    doublyNode *prev;

    doublyNode(int val)
    {
        value=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(doublyNode* &head,int value)
{
    doublyNode *newNode=new doublyNode(value);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}
void insertAtTail(doublyNode* &head,int value)
{
    doublyNode *newNode=new doublyNode(value);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    doublyNode *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void display(doublyNode *head)
{
    while(head!=NULL)
    {
        cout<<head->value;
        if(head->next!=NULL)    cout<<"->";
        head=head->next;
    }
}

int countLength(doublyNode* &head){
    doublyNode *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void displayReverse(doublyNode* &head){
    //doublyNode *temp=head;

    while(head->next!=NULL){
        head=head->next;
    }
    while(head!=NULL){
        cout<<head->value;
        if(head->prev!=NULL)    cout<<"->>";
        head=head->prev;
    }
}

void insertAtSpecificPosition(doublyNode* &head,int position,int value){
    doublyNode *newNode=new doublyNode(value);
    doublyNode *temp=head;
    int i=1;
    while(i<position-1){
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    newNode->prev=temp;

}

int main()
{
    doublyNode *head=NULL;

    int value,position;
    int choice;

    cout<<"Choice 1:Insert at head "<<endl
        <<"Choice 2:Insert at Tail "<<endl
        <<"choice 3:Display Reverse "<<endl
        <<"Choice 4:Insert at specific position"<<endl
        <<"Choice 0:Exit"<<endl;

    cout<<"Enter your choice :";
    cin>>choice;
    while(choice!=0)
    {
        switch(choice)
        {
        case 1:
            cout<<"Enter value : ";
            cin>>value;
            insertAtHead(head,value);
            break;

        case 2:
            cout<<"Enter Value :";
            cin>>value;
            insertAtTail(head,value);
            break;

        case 3:
            cout<<" Reverse doubly list is :";
            displayReverse(head);
            cout<<endl;
            break;

        case 4:
            cout<<"Enter position to insert :";
            cin>>position;
            cout<<"Enter value to insert :";
            cin>>value;
            insertAtSpecificPosition(head,position,value);
            break;

        default:

            break;
        }

        cout<<"Next choice : ";
        cin>>choice;
    }
    cout<<endl;

    cout<<"Doubly link list : ";
    display(head);
    cout<<endl<<endl;

    cout<<"Length of doubly link list is :"<<countLength(head)<<endl;

    return 0;
}
