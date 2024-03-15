#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int array[],int n,int current){
    int largest=current;
    int leftChild=2*current+1;  //law of left child
    int rightChild=2*current+2; //law of right child;

    if(leftChild<n && array[leftChild]>array[largest]){
        largest=leftChild;
    }
    if(rightChild<n && array[rightChild]>array[largest]){
        largest=rightChild;
    }
    if(largest!=current){
        swap(array[current],array[largest]); //largest er value r current er value swap hobe.
        heapify(array,n,largest);
    }
}

void printArray(int array[],int size){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void heapSort(int array[],int size){
    for(int i=size-1;i>=0;i--){
        swap(array[0],array[i]);    //prothome root orthat array[0] and latest val orthat array[i] swap hobe.
        //cout<<"Every swap ";
        //printArray(array,i);    //here print the array to see how swap work;
        heapify(array,i,0); //here i=array size and 0 first index.
    }
}

int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<"Before heapify : ";
    printArray(array,n);

    //heapify
    int nonLeafStart=(n/2)-1; // law of non leaf
    for(int i=nonLeafStart;i>=0;i--){
        heapify(array,n,i);
    }
    cout<<"After heapify : ";
    printArray(array,n);

    heapSort(array,n);
    cout<<"After heap sort: ";
    printArray(array,n);

    return 0;
}
/*
9
2 10 1 5 4 8 3 8 7

*/

