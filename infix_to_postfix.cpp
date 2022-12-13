#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int precendence(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infix_to_postfix(string s)
{
    stack<char> st;
    string result;

    for(int i=0; i<s.length(); i++)
    {
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
        {
            result=result+s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                result=result+st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() && precendence(st.top())>precendence(s[i]))
            {
                result+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }

    return result;
}

int main()
{
    cout<<"Infix to postfix evaluation is: "<<infix_to_postfix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}