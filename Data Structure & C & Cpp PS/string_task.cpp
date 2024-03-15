#include<bits/stdc++.h>
using namespace std;

string task(string chk){
    int sz=chk.length();
    string result="";
    for(int i=0;i<sz;i++){
        if(chk[i]=='a' || chk[i]=='o' || chk[i]=='y' || chk[i]=='e' || chk[i]=='u' || chk[i]=='i'){
            continue;
        }
        else{
            result+='.';
            result+=chk[i];
        }
    }

    return result;
}

int main(){
    string st;
    cin>>st;

    for(int i=0;i<st.length();i++){
        st[i]=tolower(st[i]);
    }

    string result=task(st);

    cout<<result;

    return 0;
}
