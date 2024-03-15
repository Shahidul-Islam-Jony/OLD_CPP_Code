#include<bits/stdc++.h>
using namespace std;

int binarySearch(int array[],int x,int lb ,int ub){
    if(lb<=ub)
    {
        int mid=(lb+ub)/2;
        if(x==array[mid])  return mid;
        else if(x<array[mid])
        {
            binarySearch(array,x,lb,mid-1);
        }
        else
        {
            binarySearch(array,x,mid+1,ub);
        }
    }
    else return -1;
}

int main(){
    int size;
    cin>>size;
    int array[size];
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    int checkValue;
    cout<<"Input the value which you want to search :";
    cin>>checkValue;
    int index;
    index=binarySearch(array,checkValue,0,size-1);
    if(index!=-1){
        cout<<"Index no. "<<index<<" position no. "<<index+1<<endl;
    }
    else{
        cout<<"Not found "<<endl;
    }
    return 0;
}
