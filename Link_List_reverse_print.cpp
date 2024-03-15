#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int value;
    Node* Next;
};

void  reversedListPrint(Node* n){
   if(n==NULL)
    return;
    reversedListPrint(n->Next);
   cout<<n->value<<" ";
}

int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->value=1;
    second->value=5;
    third->value=8;
    fourth->value=9;

    head->Next=second;
    second->Next=third;
    third->Next=fourth;
    fourth->Next=NULL;

    reversedListPrint(head);

    return 0;
}

