#include<bits/stdc++.h>
using namespace std;
int main(){
    string st="abcdefghij";
    string::iterator it;
    for(it=st.begin();it!=st.end();it++){
        cout<<*it<<endl;
    }
    cout<<endl;

    for(int i=0;i<st.length();i++){
        cout<<st[i]<<" ";
    }

    /*string::reverse_iterator it2;
    for(it2=st.rbegin();it2!=st.rend();it2++){
        cout<<*it2<<endl;
    }*/
   /* for(string::reverse_iterator it3=st.rbegin();it3!=st.rend();it3++){
        cout<<*it3<<endl;
    }*/
    for(auto it4=st.rbegin();it4!=st.rend();it4++){
        cout<<*it4<<endl;
    }
    return 0;
}
