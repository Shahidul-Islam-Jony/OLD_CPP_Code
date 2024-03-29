#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int value;
    Node *Next;

    //Constructor creation..
    Node(int val){
        value=val;
        Next=NULL;
    }
};
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
    //s1:newNode creation
    Node *newNode=new Node(val);
    //s2:Update of newNode->Next
    newNode->Next=head;
    //s3: Update of head
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
int main(){
    Node *head= NULL;

    int n;
    //Choice 1: Insertion at head
    //Choice 2: Insertion at tail
    cout<<"Choice 1: Insertion at head "<<endl<<"Choice 2: Insertion at tail"<<endl<<"Choice 3: Exit"<<endl;
    int choice=2;
    while(choice==1 || choice==2){
        cout<<"Enter the value : ";
        cin>>n;
        if(choice==1)   insertAtHead(head,n);
        else if(choice==2)  insertAtTail(head,n);

        cout<<"Next Choice : ";
        cin>>choice;

    }

    display(head);
    return 0;
}

