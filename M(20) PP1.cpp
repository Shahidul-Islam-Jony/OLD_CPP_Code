#include<bits/stdc++.h>
using namespace std;
void printArray(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int bubbleSortAssending(int A[],int size){
    for(int i=1;i<size;i++){
        int flag=0;
        for(int j=0;j<size-i;j++){
            if(A[j]>A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0) break;
    }
    return *A;
}
int bubbleSortDessending(int A[],int size){
    for(int i=1;i<size;i++){
        int flag=0;
        for(int j=0;j<size-i;j++){
            if(A[j]<A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0) break;
    }
    return *A;
}
int findMin(int array[],int k){
    int min=array[0];
    for(int i=1;i<k;i++){
        if(min<array[i]){
            min=array[i];
        }
    }
    return min;
}
int findMax(int array[],int k){
    int max=array[0];
    for(int i=1;i<k;i++){
        if(max>array[i]){
            max=array[i];
        }
    }
    return max;
}

int main(){
    int size,k;
    cin>>size>>k;
    int A[size];
    for(int i=0;i<size;i++){
        cin>>A[i];
    }
    cout<<"Before sort:";
    printArray(A,size);

    //Bubble sort...with optimization ..
    cout<<endl;
    bubbleSortAssending(A,size);
    cout<<"After Assending:";
    printArray(A,size);

    int Min;
        Min=findMin(A,k);
        cout<<k<<" no Min="<<Min<<endl;
    cout<<endl;
    bubbleSortDessending(A,size);
    cout<<"After Dessending :";
    printArray(A,size);
    cout<<endl;
    int Max;
    Max=findMax(A,k);
    cout<<k<<" no Max="<<Max<<endl;
    return 0;
}
