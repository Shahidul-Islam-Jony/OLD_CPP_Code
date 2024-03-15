#include<bits/stdc++.h>
#include"myStackPractise.h"
using namespace std;

int main(){
    Stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    if(!st.empty()){
        cout<<"Top before pop ="<<st.Top()<<endl;
    }
    cout<<"Size before POP = "<<st.size()<<endl;
    while(!st.empty()){
        cout<<st.pop()<<endl;
       // cout<<"TOP"<<st.Top()<<endl;
    }
    cout<<"Size after POP = "<<st.size()<<endl;

    if(!st.empty()){
        cout<<"Top after pop ="<<st.Top()<<endl;
    }

    return 0;
}
