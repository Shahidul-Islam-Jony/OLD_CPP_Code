#include<bits/stdc++.h>
using namespace std;
void linearSearch(int A[],int size_a,int B[],int size_b){
    int found=0;
    for(int i=0;i<size_a;i++){
        for(int j=0;j<size_b;j++){
            if(A[i]==B[j]){
                cout<<A[i]<<" ";
                found=1;
            }
        }
    }
    if(found==0){
        cout<<"Empty set"<<endl;
    }
}

int main(){
    int size_a;
    cin>>size_a;
    int A[size_a];
    for(int i=0;i<size_a;i++){
        cin>>A[i];
    }
    int size_b;
    cin>>size_b;
    int B[size_b];
    for(int i=0;i<size_b;i++){
        cin>>B[i];
    }
    linearSearch(A,size_a,B,size_b);
    return 0;
}
