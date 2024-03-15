#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d",&n);
    char ch[n];
    scanf("%s",&ch);
    char ch2[n];
    strcpy(ch2,ch);
    strrev(ch2);
    for(int i=0;i<strlen(ch);i++){
        if(ch[i]!=ch2[i]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}

