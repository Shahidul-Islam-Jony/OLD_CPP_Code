
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int value;
    Node *Next;
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

struct Test
{
    int position[1000];
};


void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int val);
void display(Node *n);
int countLength(Node *&head);
void insertionAtSpecificPosition(Node* &head, int pos,int val);
int searchByValueUnique(Node *&head, int key);
void searchByValueDuplicate(Node *&head, int key);
Test searchByValueDuplicateReturn(Node *&head, int key);
void insertionByValueUnique(Node* &head,int searchValue,int val);
void deletionAtHead(Node* &head);
void deletionAtTail(Node* &head);
void deletionAtSpecificPosition(Node* &head,int position);
void deletionByValueUnique(Node* &head,int value);
void insertionByValueDuplicate(Node* &head,int value);
void deletionByValueDuplicate(Node* &head,int value);

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}

void display(Node *n)
{
    while (n != NULL)
    {
        cout << n->value;
        if (n->Next != NULL)
            cout << " ";
        n = n->Next;
    }
}

int countLength(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->Next;
        count++;
    }
    return count;
}

void insertionAtSpecificPosition(Node* &head, int pos,int val)
{
    Node *newNode= new Node(val);

    int i=0;
    Node *temp=head;
    while(i<pos-2)
    {
        temp=temp->Next;
        i++;
    }
    newNode->Next=temp->Next;
    temp->Next=newNode;
}


int searchByValueUnique(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    if (temp == NULL)
    {
        return -1;
    }
    while (temp->value != key)
    {
        if (temp->Next == NULL)
        {
            return -1;
        }
        temp = temp->Next;
        count++;
    }
    return count;
}

void searchByValueDuplicate(Node *&head, int key)
{
    Node *temp = head;
    int count = 1;
    int flag=0;
    int len=countLength(head);
    int position[len+1],k=1;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            // cout << count << " ";
            position[k]=count;
            k++;
            flag=1;
        }
        temp = temp->Next;
        count++;
    }
    cout<<endl;
    if(flag==0)
    {
        cout<<"The search value is not yet in list"<<endl;
    }
    else
    {
        position[0]=k;
        cout<<"The value is found at position :";
        for(int i=1; i<position[0]; i++)
        {
            cout<<position[i];
            if(i<position[0]-1)   cout<<",";
        }
    }
    cout<<endl;
}

Test searchByValueDuplicateReturn(Node *&head, int key)
{
    Node *temp = head;
    Test T;
    int count = 1;
    int k=1;
    while (temp != NULL)
    {
        if (temp->value == key)
        {
            // cout << count << " ";
            T.position[k]=count;
            k++;
        }
        temp = temp->Next;
        count++;
    }
    T.position[0]=k;
    return T;
}

void insertionByValueUnique(Node* &head,int searchValue,int value)
{
    int position;
    position=searchByValueUnique(head,searchValue);
    insertionAtSpecificPosition(head,position+1,value);
}

void deletionAtHead(Node* &head)
{
    Node *temp=head;
    if(temp!=NULL)
    {
        head=temp->Next;
        delete temp;
    }
    else
    {
        cout<<"There is no value in link list"<<endl;
    }
}

void deletionAtTail(Node* &head)
{
    Node *temp=head;
    if(temp!=NULL && temp->Next!=NULL)
    {
        while(temp->Next->Next!=NULL)
        {
            temp=temp->Next;
        }
        Node *delNode=temp->Next;
        temp->Next=NULL;
        delete delNode;
    }

    else
    {
        //case 1: head is null//means no vale in link list.
        if(temp==NULL)  cout<<"There is no value in link list"<<endl;
        //case 2:Head is tail// means only one vale in link list.
        else deletionAtHead(head);
    }
}

void deletionAtSpecificPosition(Node* &head,int position)
{
    Node* temp=head;
    if(position<=countLength(head))
    {
        if(position==1)
        {
            deletionAtHead(head);
        }
        else if(position==countLength(head))
        {
            deletionAtTail(head);
        }
        else
        {
            int i=1;
            while(i<position-1)
            {
                temp=temp->Next;
                i++;
            }

            Node* delNode= temp->Next;
            temp->Next=delNode->Next;
            delete delNode;
        }
    }
    else
    {
        cout<<"Position Out of Bound";
    }
}

void deletionByValueUnique(Node* &head,int value)
{
    //find the position of the value.
    int position;
    position=searchByValueUnique(head,value);

    //delete the Node at that position.
    if(position==-1)
    {
        cout<<"Value is not found in the link list"<<endl;
    }
    else
    {
        deletionAtSpecificPosition(head,position);
    }
}

void insertionByValueDuplicate(Node* &head,int searchValue,int value)
{
    Test T=searchByValueDuplicateReturn(head,searchValue);
    if(T.position[0]==1)
    {
        cout<<"The value is not found in the list."<<endl;
    }
    else
    {
        int size=T.position[0];
        for(int i=1; i<size; i++)
        {
            insertionAtSpecificPosition(head,T.position[i]+i,value);
        }
    }
}

void deletionByValueDuplicate(Node* &head,int delValue)
{
    Test T=searchByValueDuplicateReturn(head,delValue);
    if(T.position[0]==1)
    {
        cout<<"The value is not found in the list."<<endl;
    }
    else
    {
        int size=T.position[0];
        int count=0;
        for(int i=1; i<size; i++)
        {
            deletionAtSpecificPosition(head,T.position[i]-count);
            count++;
        }
    }
}

int main()
{
    Node *head = NULL;
    int val, position,searchValue,delValue;
    int choice;
    cout << "Choice 1:Insert At head :" << endl
         << "Choice 2:Insert at Tail:" << endl
         << "Choice 3:Insert at specific position:" << endl
         << "Choice 4:Search Value (Unique list) :" << endl
         << "Choice 5:Search value (Duplicate enabled list):"<<endl
         << "Choice 6:InsertValue After search Value :"<<endl
         << "Choice 7:Deletion at head:"<<endl
         << "Choice 8:Deletion at Tail:"<<endl
         << "Choice 9:Deletion at specific position:"<<endl
         << "Choice 10:Deletion by value (Unique List):"<<endl
         << "Choice 11:Insert after specific value(Duplicate list):"<<endl
         << "Choice 12:Deletion after specific value(Duplicate list):"<<endl
         << "Choice 0:Exit" << endl;

    cout << "Enter Choice:";
    cin >> choice;
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter value:";
            cin >> val;
            insertAtHead(head, val);
            break;
        case 2:
            cout << "Enter value:";
            cin >> val;
            insertAtTail(head, val);
            break;
        case 3:
            cout << "Enter the desired position :";
            cin >> position;
            cout << "Enter value:";
            cin >> val;
            insertionAtSpecificPosition(head, position, val);
            break;
        case 4:
            cout << "Enter value:";
            cin >> val;
            position = searchByValueUnique(head, val);
            if (position != -1)
            {
                cout << "Value found at position : " << position << endl;
            }
            else
            {
                cout << "The number is not yet in the list" << endl;
            }
            break;
        case 5:
            cout << "Enter value to search:";
            cin >> val;
            Test T;
            T=searchByValueDuplicateReturn(head,val);
            if(T.position[0]==1)
            {
                cout<<"The value is not yet in the list."<<endl;
            }
            else
            {
                int size=T.position[0];
                cout<<"Position of the value : ";
                for(int i=1; i<size; i++)
                {
                    cout<<T.position[i];
                    if(i<size-1)    cout<<",";
                }
                cout<<endl;
            }
            break;
        case 6:
            cout<<"Enter value for searchValue:";
            cin>>searchValue;
            cout<<"Enter value to insert :";
            cin>>val;
            insertionByValueUnique(head,searchValue,val);
            break;

        case 7:
            deletionAtHead(head);
            break;

        case 8:
            deletionAtTail(head);
            break;

        case 9:
            if(head==NULL)
            {
                cout<<"There is no value in link list"<<endl;
                break;
            }
            cout << "Enter the desired position :";
            cin >> position;
            deletionAtSpecificPosition(head,position);
            break;

        case 10:
            cout<<"Enter value for deletion:";
            cin>>delValue;
            deletionByValueUnique(head,delValue);
            break;

        case 11:
            cout<<"Enter value for searchValue:";
            cin>>searchValue;
            cout<<"Enter value to insert :";
            cin>>val;
            insertionByValueDuplicate(head,searchValue,val);
            break;

        case 12:
            cout<<"Enter value for deletion:";
            cin>>delValue;
            deletionByValueDuplicate(head,delValue);
            break;

        default:
            break;
        }
        cout << "Next choice:";
        cin >> choice;
    }

    cout<<endl;
    cout<<"Link List:";
    display(head);
    cout << endl<<endl;
    cout << "Length of Link list " << countLength(head) << endl;
    return 0;
}

