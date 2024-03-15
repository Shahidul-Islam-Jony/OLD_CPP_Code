#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *Next;
    Node(int val)
    {
        this->val=val;
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

int findMid(Node* &head)
{
    if(head==NULL)
    {
        return -1;
    }
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->Next!=NULL)
    {
        slow=slow->Next;
        fast=fast->Next->Next;
    }
    return slow->val;
}

int main()
{
    Node *head=NULL;
    int choice,val;
    cout<<"Choice 2:Insert at tail:"<<endl
        <<"Choice 3:Find mid :"<<endl
        <<"Choice 0:Exit "<<endl;
    cout<<"Enter choice :";
    cin>>choice;
    while(choice!=0)
    {
        switch(choice)
        {
        case 2:
            cout<<"Enter value:";
            cin>>val;
            insertAtTail(head,val);
            break;
        case 3:
            int mid=findMid(head);
            if(mid==-1)
            {
                cout<<"Link list is empty"<<endl;
            }
            else
            {
                cout<<"Mid value of the list is ="<<mid<<endl;
            }
            break;
        }
        cout<<"Next choice :";
        cin>>choice;
    }

    return 0;
}
