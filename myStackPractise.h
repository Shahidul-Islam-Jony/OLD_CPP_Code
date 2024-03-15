#include<bits/stdc++.h>
using namespace std;

template<typename N> class Node{
public:
    N value;
    Node *next;
    Node *prev;

    Node(N val){
        value=val;
        next=NULL;
        prev=NULL;
    }
};

template<typename S> class Stack{
    Node<S> *head;
    Node<S> *top;
    int count=0;

public:
    Stack(){
        head=NULL;
        top=NULL;
    }

    //PUSH operaton..
    void push(S val){
        Node<S> *newNode=new Node<S>(val);
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

    //POP operation..
    S pop(){
        Node<S> *delNode;
        delNode=top;
        S chk;
        if(head==NULL){
            cout<<"Stack UnderFlow"<<endl;
            return chk;
        }
        if(head==top){
            head=top=NULL;
        }
        else{
            top=delNode->prev;
            top->next=NULL;
        }
        chk=delNode->value;
        delete delNode;
        count--;
        return chk;
    }

    //EMPTY operation..
    bool empty(){
        if(head==NULL)  return true;
        else return false;
    }

    //SIZE operation..
    int size(){
        return count;
    }

    //TOP Operation...
    S Top(){
        S chk;
        if(top==NULL){
            cout<<"Stack UnderFlow | there is no value in the link list"<<endl;
        }
        else
            chk=top->value;

        return chk;

    }

};
