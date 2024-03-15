#include<bits/stdc++.h>
#include"myStackPractise.h"
using namespace std;

int precisionCalc(char ch)
{
    if(ch=='^')
    {
        return 3;
    }
    else if(ch=='*' || ch=='/')
    {
        return 2;
    }
    else if(ch=='+' || ch=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPrefix(string chk)
{
    Stack<char> st;
    string result;

    reverse(chk.begin(),chk.end());

    for(int i=0; i<chk.length(); i++)
    {
        if(chk[i]>='0' && chk[i]<='9')
        {
            result+=chk[i];
        }
        else if(chk[i]==')')
        {
            st.push(chk[i]);
        }
        else if(chk[i]=='(')
        {
            while(!st.empty() && st.Top()!=')')
            {
                result+=st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else
        {
            while(!st.empty()&& precisionCalc(st.Top()) >= precisionCalc(chk[i]))
            {
                result+=st.pop();
            }
            st.push(chk[i]);
        }
    }
    while(!st.empty())
    {
        result+=st.pop();
    }

    reverse(result.begin(),result.end());

    return result;
}

string infixToPostfix(string chk)
{
    Stack<char> st;
    string result;

    for(int i=0; i<chk.length(); i++)
    {
        if(chk[i]>='0' && chk[i]<='9')
        {
            result+=chk[i];
        }
        else if(chk[i]=='(')
        {
            st.push(chk[i]);
        }
        else if(chk[i]==')')
        {
            while(!st.empty() && st.Top()!='(')
            {
                result+=st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else
        {
            while(!st.empty()&& precisionCalc(st.Top()) >= precisionCalc(chk[i]))
            {
                result+=st.pop();
            }
            st.push(chk[i]);
        }
    }
    while(!st.empty())
    {
        result+=st.pop();
    }

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

double postfixEvaluation(string chk)
{
    Stack<double> st;
    for(int i=0; i<chk.length(); i++)
    {
        if(chk[i]>='0' && chk[i]<='9')
        {
            st.push(chk[i]-'0');
        }
        else
        {
            double a=st.pop();
            double b=st.pop();
            switch(chk[i])
            {
            case'+':
                st.push(b+a);
                break;
            case '-':
                st.push(b-a);
                break;
            case '*':
                st.push(b*a);
                break;
            case '/':
                st.push(b/a);
                break;
            case '^':
                st.push(pow(b,a));
                break;
            default:
                break;
            }
        }
    }
    return st.Top();
}


int main()
{
    string infix1= "(5*((6^2)+(7-(2/6))))-((7*(8+1))+(5*4))";   //"(7+(4*5))-(2+0)";
    string infix2= "(5*((6^2)+(7-(2/6))))-((7*(8+1))+(5*4))";   //"(4*(3+5))-(2+0)";

    //(6/2*(2+1)) this equation show error ans an phone cal but my program show correct ans

    string prefix;
    prefix=infixToPrefix(infix1);
    cout<<endl<<prefix<<endl
        <<prefixEvaluation(prefix)<<endl;

    string postfix;
    postfix=infixToPostfix(infix2);
    cout<<endl<<postfix<<endl
        <<postfixEvaluation(postfix)<<endl;

    return 0;
}
