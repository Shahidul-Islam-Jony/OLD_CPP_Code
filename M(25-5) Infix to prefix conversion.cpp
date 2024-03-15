#include<bits/stdc++.h>
#include"myStackPractise.h"
using namespace std;

int precisionCalc(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='/' || c=='*'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPrefix(string chk){

    reverse(chk.begin(), chk.end());
    Stack<char> st; //because we insert +,-,(,),*,/ etc in stack which are char.
    string result;

    for(int i=0;i<chk.length();i++){
        if(chk[i]>='0' && chk[i]<='9'){
            result+=chk[i];
        }
        else if(chk[i]==')'){
            st.push(chk[i]);
        }
        else if(chk[i]=='('){
            while(!st.empty() && st.Top()!=')'){  //for corner case when stack is empty.
                result+=st.pop();
            }
            if(!st.empty()) st.pop();   //clearing ')' bracket.
        }
        else{   //Operator case.

            while(!st.empty() && precisionCalc(st.Top()) >= precisionCalc(chk[i])){
                result+=st.pop();
            }
            st.push(chk[i]);
        }
    }

    while(!st.empty()){
        result+=st.pop();
    }

    reverse(result.begin(), result.end());

    return result;

}


double prefixEvaluation(string chk){
    Stack<double> st;

    for(int i=chk.length()-1;i>=0;i--){
        if(chk[i]>='0' && chk[i]<='9'){
            st.push(chk[i]-'0');
        }
        else{
            double a=st.pop();
            double b=st.pop();
            switch(chk[i]){
            case '+':
                st.push(a+b);
                break;
            case '-':
                st.push(a-b);
                break;
            case '*':
                st.push(a*b);
                break;
            case'/':
                st.push(a/b);
                break;
            case '^':
                st.push(pow(a,b));
                break;

            default:
                break;

            }
        }
    }
    return st.Top();
}

int main(){
    string infix="(5*((6^2)+(7-(2/6))))-((7*(8+1))+(5*4))";   //(7+(4*5))-(2+0)
    string prefix;
    prefix=infixToPrefix(infix);
    cout<<endl<<prefix<<endl
        <<prefixEvaluation(prefix)<<endl;
    return 0;
}


