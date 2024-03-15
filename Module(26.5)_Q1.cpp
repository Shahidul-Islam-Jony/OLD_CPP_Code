#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

void checkBalanced(string chk)
{
    Stack<char> st;

    for(int i=0; i<chk.length(); i++)
    {
        if(chk[i]=='(' || chk[i]=='{' || chk[i]=='['){
            st.push(chk[i]);
        }
        else{
            if(chk[i]==')' && st.Top()=='('){
                st.pop();
            }
            else if(chk[i]=='}' && st.Top()=='{'){
                st.pop();
            }
            else if(chk[i]==']' && st.Top()=='['){
                st.pop();
            }
            else{
                cout<<"NO"<<endl;
                return;
            }

        }
    }

    if(st.empty()){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}


int main()
{
    string ch;
    cin>>ch;
    checkBalanced(ch);

    return 0;
}
