#include<bits/stdc++.h>
using namespace std;

stack<char> stck;
string res;

int Precedence(char ch)
{
    if(ch == '^')
        return 3;
    else if(ch == '/' || ch =='*')
        return 2;
    else if(ch == '+' || ch =='-')
        return 1;
    else
        return -1;
}

int isOperand(char ch)
{
    if((tolower(ch) >= 'a' && tolower(ch) <= 'z') || (ch >= '0'  && ch <= '9'))
        return 1;
    else
        return 0;
}
void InfixToPostfix(string str)
{
    int len = str.size();

    for(int i=0; i<len; i++)
    {
        if(isOperand(str[i]))
        {
            res += str[i];
        }
        else if(str[i] == '(')
            stck.push('(');
        else if(str[i] == ')')
        {
            while(stck.top() != '(')
            {
                res += stck.top();
                stck.pop();
            }
            stck.pop();
        }
        else
        {
            while(!stck.empty() && Precedence(str[i]) <= Precedence(stck.top()))
            {
                res += stck.top();
                stck.pop();
            }
            stck.push(str[i]);
        }
    }

    while(!stck.empty())
    {
        res += stck.top();
        stck.pop();
    }

    cout<<res<<endl;
}
int main()
{
	string str;
	cin>>str;

	InfixToPostfix(str);

	return 0;
}
