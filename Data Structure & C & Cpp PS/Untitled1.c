#include<stdio.h>
int main(){
    int a=5;
    for(int i=0;i<a;i++){
        if(i==0){
            printf("%d",i+1);
        }
        else{
            printf("%8d",i+1);
        }
    }
    printf("\n");
    for(int i=0;i<a;i++){
        printf("%d\t",i+1);
    }
    return 0;
}
