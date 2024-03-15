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
int searchByValueUnique(Node* &head,int key);
void searchByValueDuplicate(Node* &head,int key);



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

int searchByValueUnique(Node* &head,int key){
    Node *temp=head;
    int count=1;

    if(temp==NULL){   //case 2: if list is empty and we want to find key.
            return -1;
        }

    while(temp->value != key ){
        if(temp->Next==NULL){ // case 1 : if key not in list.
            return -1;
        }
        temp=temp->Next;
        count++;
    }
    return count;
}

void searchByValueDuplicate(Node* &head,int key){
    Node *temp=head;
    int size = countLength(head);
    int position[size+1], k=1;

    int count=1;
    int flag=0;
    while(temp!=NULL){
        if(temp->value==key){
            //cout<<count<<" ";
            position[k]=count;
            k++;
            flag=1;
        }
        temp=temp->Next;
        count++;
    }
    cout<<endl;
    if(flag==0) cout<<"The search value is not yet in the list"<<endl;
    else{
        position[0]=k;
        cout<<"The value found at Position : ";
        for(int i=1;i<position[0];i++){
            cout<<position[i];
            if(i<position[0]-1) cout<<",";
        }
        cout<<endl;
    }
}

int main(){
    Node *head= NULL;

    int n,position;
    cout<<"Choice 1: Insertion at head "<<endl
    <<"Choice 2: Insertion at tail"<<endl
    <<"Choice 3: Insert at specific Position"<<endl
    <<"Choice 4: Search a value (Unique List)"<<endl
    <<"Choice 5: Search a value (duplication enabled list)"<<endl
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
        case 4:
            cout<<"Enter the value : ";
            cin>>n;
            position=searchByValueUnique(head,n);
            if(position !=-1){
                cout<<"The number is at position "<<position<<endl;
            }
            else{
                cout<<" The number is not yet in the list "<<endl;
            }
            break;
        case 5:
            cout<<"Enter the value : ";
            cin>>n;
            searchByValueDuplicate(head,n);

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

