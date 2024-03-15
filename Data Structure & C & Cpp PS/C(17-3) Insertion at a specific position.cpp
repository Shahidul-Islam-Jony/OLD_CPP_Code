#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *Next;

    Node(int val){
        value=val;
        Next=NULL;
    }
};

void insertAtTail(Node* &head, int val);
void insertAtHead(Node* &head, int val);
void display(Node *n);
int countLength(Node* &head);
void insertionAtSpecificPosition(Node* &head, int pos,int val);


void insertAtTail(Node* &head, int val){
    Node *newNode= new Node(val);

    if(head==NULL){
        head=newNode;
        return;
    }

    Node* temp=head;
    while(temp->Next != NULL){
        temp=temp->Next;
    }
    temp->Next=newNode;

}

void insertAtHead(Node* &head, int val){
    Node *newNode=new Node(val);
    newNode->Next=head;
    head=newNode;

}

void display(Node *n){
    while(n!=NULL){
        cout<<n->value;
        if(n->Next!=NULL){
            cout<<" -> ";
        }
        n=n->Next;
    }
}

int countLength(Node* &head){
    int count=0;
    Node *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->Next;
    }
    return count;
}

void insertionAtSpecificPosition(Node* &head, int pos,int val){
        Node *newNode= new Node(val);

        int i=0;
        Node *temp=head;
        while(i<pos-2){
            temp=temp->Next;
            i++;
        }
        newNode->Next=temp->Next;
        temp->Next=newNode;
}

int main(){
    Node *head= NULL;

    int n,position;
    cout<<"Choice 1: Insertion at head "<<endl
    <<"Choice 2: Insertion at tail"<<endl
    <<"Choice 3: Insert at specific Position"<<endl
    <<"Choice 0: Exit"<<endl;
    int choice;
    cout<<"Enter Choice : ";
    cin>>choice;
    while(choice!=0){

        switch(choice){
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
            cout<<"Enter desired position:";
            cin>>position;
            cout<<"Enter the value : ";
            cin>>n;
            insertionAtSpecificPosition(head,position,n);
            break;
        default:
            break;
        }
        cout<<"Next choice : ";
        cin>>choice;
    }

    cout<<endl<<endl;
    cout<<"Link List "<<endl;
    display(head);

    cout<<endl<<endl;
    cout<<"Length of the list : "<<countLength(head)<<endl;
    return 0;
}

