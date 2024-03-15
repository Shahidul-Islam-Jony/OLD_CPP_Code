#include<bits/stdc++.h>
using namespace std;

template<typename N> class QNode{
public:
    N value;
    QNode* next;

    QNode(N val){
        value=val;
        next=NULL;
    }
};

template<typename Q> class Queue{
    QNode<Q> *front;
    QNode<Q> *rear;

public:
    Queue(){
        front=NULL;
        rear=NULL;
    }

    //enqueue ----> push(val)
    void push(Q val){
        QNode<Q> *newNode=new QNode<Q>(val);

        if(front==NULL){
            front=newNode;
            rear=newNode;
            return;
        }

        rear->next=newNode;
        rear=rear->next;
    }

    //dequeue ---->pop()
    Q pop(){

        Q chk;
        if(rear==NULL){
            cout<<"Queue underFlow | There is no element in the Queue"<<endl;
            return chk;
        }
        QNode<Q> *delNode;
        delNode=front;
        front=front->next;
        if(front==NULL){    //when we pop after pop and queue will empty then rear also point NULL;
            rear=NULL;
        }
        chk=delNode->value;
        delete delNode;

        return chk;
    }

    //peek ---->front() back()
    Q Front(){
        Q chk;
        chk=front->value;
        return chk;
    }

    Q Back(){
        Q chk;
        chk=rear->value;
        return chk;
    }

    //empty ---->empty()
    bool empty(){
        if(front==NULL && rear==NULL)
            return true;
        else
            return false;
    }

};
