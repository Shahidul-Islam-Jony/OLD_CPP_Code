#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }


   //Finding max;
    int max=array[0];
    for(int i=1;i<n;i++){
        if(array[i]>max){
            max=array[i];
        }
    }

    //initialization of counter array..
    int count[max+1]={0};

    //frequency array...
    for(int i=0;i<n;i++){
        count[array[i]]++;
    }

    //cumulative sum...
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }

    //sorting array...
   int sortedArray[n];
    for(int i=n-1;i>=0;i--){
       count[array[i]]--;
       int k=count[array[i]];
       sortedArray[k]=array[i];
    }

    //Reinitialization of counter array..
   for(int i=0;i<=max;i++){
        count[i]=0;
    }

    //again count frequency array..
    for(int i=0;i<n;i++){
        int val=sortedArray[i];
        count[val]++;
    }


     for(int i=0;i<=max;i++){
        if(count[i]>0){
            cout<<i<<" => "<<count[i]<<endl;
        }
    }

    return 0;
}
