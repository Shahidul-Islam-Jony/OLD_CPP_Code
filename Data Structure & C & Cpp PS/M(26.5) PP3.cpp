#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

void sortedStack(Stack<int> st)
{
    Stack<int> tempStack;
    while(!st.empty())
    {
        int temp=st.pop();
        while((!tempStack.empty()) && (tempStack.Top()<temp))
        {
            st.push(tempStack.pop());
        }
        tempStack.push(temp);
    }
    while(!tempStack.empty())
    {
        cout<<tempStack.pop()<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    Stack<int> st;
    for(int i=0; i<n; i++)
    {
        int val;
        cin>>val;
        st.push(val);
    }
    sortedStack(st);
    return 0;
}
