#include<bits/stdc++.h>
using namespace std;
class Student
{
public:
    int roll;
    string name;
    string phone;
    string section;
    float attend;
    Student *Next;

    Student(int roll,string name,string phone,string section,float attend)
    {
        this->roll=roll;
        this->name=name;
        this->phone=phone;
        this->section=section;
        this->attend=attend;
        Next=NULL;
    }
};

void insert(Student* &head,int roll,string name,string phone,string section,float attend)
{
    Student *newNode=new Student(roll,name,phone,section,attend);
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    Student *temp=head;
    while(temp->Next!=NULL)
    {
        temp=temp->Next;
    }
    temp->Next=newNode;
}

void display(Student *node)
{
    while(node!=NULL)
    {
        cout<<"Roll no :"<<node->roll<<endl;
        cout<<"Name : "<<node->name<<endl;
        cout<<"Phone no : "<<node->phone<<endl;
        cout<<"Section : "<<node->section<<endl;
        cout<<"Attendance : "<<node->attend<<endl;
        node=node->Next;

        cout<<endl;
    }
}

void search(Student* &head,int roll)
{
    Student *temp=head;
    while(temp!=NULL){
        if(temp->roll==roll){
            cout<<endl;
            cout<<"Roll no :"<<temp->roll<<endl;
            cout<<"name :"<<temp->name<<endl;
            cout<<"phone :"<<temp->phone<<endl;
            cout<<"Section :"<<temp->section<<endl;
            cout<<"Attendance :"<<temp->attend<<endl;
            cout<<endl;
            return;
        }
        temp=temp->Next;
    }
    cout<<"Not found"<<endl;
}

void delet(Student* &head,int roll){
    Student *temp1=head;
    Student *temp2=head;
    while(temp1!=NULL){
        if(temp1->roll==roll){
            if(temp1==temp2){
               head=head->Next;
               free(temp1);
            }
            else{
                temp2->Next=temp1->Next;
            }
            return;
        }
        temp2=temp1;
        temp1=temp1->Next;
    }
    cout<<"Not Found"<<endl;
}

void update(Student* &head,int roll){
    Student *temp=head;
    while(temp!=NULL){
        if(temp->roll==roll){
            cout<<"Enter name :";
            cin>>temp->name;
            cout<<"Enter phone no :";
            cin>>temp->phone;
            cout<<"Enter Section:";
            cin>>temp->section;
            cout<<"Enter Attendance :";
            cin>>temp->attend;
            return;
        }
        temp=temp->Next;
    }
    cout<<"Not found"<<endl;
}

int main()
{
    Student *head=NULL;
    int option;
    int roll;
    string name,phone,section;
    float attend;

    cout<<"1.for insertion"<<endl
        <<"2.for display"<<endl
        <<"3.for search"<<endl
        <<"4.for delete"<<endl
        <<"5.for update"<<endl;

        cout<<endl<<endl;

    do
    {
        cout<<"Enter option:";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Enter roll no:";
            cin>>roll;
            cout<<"Enter name:";
            cin>>name;
            cout<<"Enter Phone no:";
            cin>>phone;
            cout<<"Enter section:";
            cin>>section;
            cout<<"Enter attendance :";
            cin>>attend;

            insert(head,roll,name,phone,section,attend);
            break;

        case 2:
            cout<<endl;
            display(head);
            break;
        case 3:
            cout<<"Enter roll no for searching :";
            cin>>roll;
            search(head,roll);
            break;
        case 4:
            cout<<"Enter roll no for delete :";
            cin>>roll;
            delet(head,roll);
            break;
        case 5:
            cout<<"Enter roll no for update :";
            cin>>roll;
            update(head,roll);
            break;

        }
    }while(option!=0);
    return 0;
}
