#include<bits/stdc++.h>
using namespace std;
class doublyNode
{
public:
    int value;
    doublyNode* next;
    doublyNode* prev;

    doublyNode(int val)
    {
        value=val;
        next=NULL;
        prev=NULL;
    }
};

void insertNode(doublyNode* &head,int val)
{
    doublyNode* newNode=new doublyNode(val);
    if(head==NULL){
        head=newNode;
        cout<<"Head value ="<<head->value<<endl;
        return;
    }
    doublyNode *temp=head;
    while(temp->next!=NULL){
        cout<<"Temp value ="<<temp->value<<endl;
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void display(doublyNode *n)
{
    while(n->next!=NULL)
    {
        cout<<n->value<<" ";
    }
    cout<<endl;
}

int main()
{
    doublyNode *head=NULL;
    int n;
    cin>>n;
    int l[n+1], r[n+1];
    for(int i=1; i<=n; i++){
        cin>>l[i]>>r[i];
    }


    int temp=0;
    int left=0;
    int right=0;
    for(int i=1; i<=n; i++)
    {
        if(l[i] == 0)
        {
           // cout<<"Now li= "<<l[i]<<endl<<endl;
            if(temp != 0)
            {
               // cout<<"Now i= "<<i<<endl<<endl;
                left=temp;
                insertNode(head,left);
               // cout<<"l[i]= "<<l[i]<<endl<<endl;
                right=i;
                insertNode(head,right);
               // cout<<"r[temp]= "<<r[temp]<<endl<<endl;
            }
            temp=i;
            //cout<<"Now temp = i "<<temp<<endl<<endl;
            while(r[temp]){
                temp=r[temp];
                cout<<" while temp=r[temp] "<<temp<<endl<<endl;
                insertNode(head,temp);
            }

        }
    }
    //display(head);
    return 0;
}
