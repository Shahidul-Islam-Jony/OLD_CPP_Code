#include<bits/stdc++.h>
using namespace std;

/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/

int max_of_two(int num1,int num2){
    cout<<"Max of two"<<num1<<" "<<num2<<endl;
    if(num1>num2){
        return num1;
    }
    else{
        return num2;
    }
}

int max_of_four(int a,int b,int c,int d){
    int num[4] = {a,b,c,d};
    int max=num[0];
    for(int i=1;i<4;i++){
         max = max_of_two(max,num[i]);
        
    }
    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}