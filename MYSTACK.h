#include<bits/stdc++.h>
using namespace std;
template<typename N> class Node{
public:
    N value;
    Node* prev;
    Node* next;

    Node(N val){
        value=val;
        prev=NULL;
        next=NULL;
    }
};

template<typename S> class Stack{

    Node<S>* head;
    Node<S>* top;
    int count=0;

public:
    Stack(){
        head=NULL;
        top=NULL;
    }

    //PUSH....Operation..
    void push(S val){
        Node<S>* newNode =new Node<S>(val);
        if(head==NULL){
            head=top=newNode;
            count++;
            return;
        }
        top->next=newNode;
        newNode->prev=top;
        top=newNode;
        count++;
    }

    //POP...operation..
    S pop(){
        Node<S>* delNode;
        delNode=top;
        S check; //OR int check;//then underflow return -1;

        if(head==NULL){ // when there is no element...//means Underflow..
            cout<<"Stack Underflow"<<endl;
            return check; // return -1;
        }

        if(top==head){  //when there is only one element..
            head=top=NULL;
        }
        else{   //when there is more than one element..
            top=delNode->prev;
            top->next=NULL;
        }
        check=delNode->value;
        delete delNode;
        count--;
        return check;
    }

    //EMPTY...Operation...
    bool empty(){
        if(head==NULL)  return true;
        else return false;
    }

    //TOP...Operation..
    S Top(){
        S chk;
        if(top==NULL){
            cout<<"Stack Underflow | There is no element in top "<<endl;
        }
        else
            chk=top->value;

        return chk;
    }

    //SIZE...Operation..
    int size(){
       return count;
    }

};

