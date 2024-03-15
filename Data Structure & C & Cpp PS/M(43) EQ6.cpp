#include<bits/stdc++.h>
using namespace std;

void magicColor(char color[],int size){
    stack<char> st;
    stack<char>magicST;
    int i=0;
    while(i<size){
        char a,b;
        if(i<size && i+1<size){
            a=color[i];
            b=color[i+1];
            i+=2;
            if(st.empty()){
                if(a==b)    continue;
                else if(a=='R'&& b=='B'|| a=='B'&& b=='R')    st.push('P');
                else if(a=='R'&& b=='G' || a=='G'&& b=='R')   st.push('Y');
                else if(a=='B'&& b=='G' || a=='G'&& b=='B')   st.push('C');
                else{
                    st.push(a);
                    st.push(b);
                }
            }
            else{
                if(a==b)    continue;
                else if(a=='R'&& b=='B' || a=='B'&& b=='R'){
                    if(st.top()=='P') st.pop();
                    else    st.push('P');
                }
                else if(a=='R'&& b=='G' || a=='G'&& b=='R'){
                    if(st.top()=='Y')  st.pop();
                    else    st.push('Y');
                }
                else if(a=='B'&& b=='G' || a=='G'&& b=='B'){
                    if(st.top()=='C')  st.pop();
                    else    st.push('C');
                }
                else{
                    st.push(a);
                    st.push(b);
                }
            }

        }
        else{
            a=color[i];
            st.push(a);
            i++;
        }
    }
    while(!st.empty()){
        char x=st.top();
        st.pop();
        magicST.push(x);
    }
    while(!magicST.empty()){
        cout<<magicST.top();
        magicST.pop();
    }
}

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int N;
        cin>>N;
        char color[N+1];
        for(int i=0;i<N;i++){
            cin>>color[i];
        }
        magicColor(color,N);
        cout<<endl;
    }

    return 0;
}
