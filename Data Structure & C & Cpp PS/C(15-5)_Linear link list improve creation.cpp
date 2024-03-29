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
    char choice='Y';
    while(toupper(choice)=='Y'){
        cout<<"Enter the value : ";
        cin>>n;
        insertAtTail(head, n);
        cout<<"Do you want to continue : (Y/N)";
        cin>>choice;
    }

    /*insertAtTail(head, 1);
    insertAtTail(head, 5);
    insertAtTail(head, 8);
    insertAtTail(head, 9);*/

    display(head);
    return 0;
}
