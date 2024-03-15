#include<bits/stdc++.h>
#include"myStackPractise.h"
using namespace std;

void reverseSentence(string name){
    Stack<string> st;
    for(int i=0;i<name.length();i++){
        string word="";
        while(i<name.length() && name[i]!=' '){
            word+=name[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.Top()<<" ";
        st.pop();
    }
}

int main(){
    string name;
    getline(cin,name);
    reverseSentence(name);
    return 0;
}
