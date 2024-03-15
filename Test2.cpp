#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

Node<int>* removeZero(Node<int>* head,int n){
    Node<int>* zero=new Node<int>(0);
    zero->next=head;
    Stack<int> st;
    st.push(zero->value);
    int sum=0;
    while(head){
        sum+=head->value;
        st.push(head->value);
        head=head->next;
    }
    head=zero;
    sum=0;
    while(head){
        sum+=head->value;
            Node<int> temp=st.pop();

        if(!temp){
            head->next=temp->next;
        }
        head=head->next;
    }
    return zero->next;
}


int main(){
    Node *head=NULL;
    Stack<int> st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        st.push(val);
    }
    removeZero(head,n);

    return 0;
}
