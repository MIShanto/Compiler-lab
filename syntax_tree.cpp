#include<bits/stdc++.h>
using namespace std;

//char gr[][10] = {"E+E","E-E","E*E","E/E","(E)","a","b","c"};
string grammar[] = {"E+E","E-E","E*E","E/E","(E)","a","b","c"};

int Operator(char ch)
{
    switch (ch)
    {
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '(':
            return 4;
        default:
            return -1;
    }
}

int main()
{
    string str, res;

    cin>>str;
    int len = str.size(), index;

    res.push_back('E');
    cout<<res<<endl;

    for(int i = 0 ; i < len ; i++)
    {
        index = Operator(str[i]);
        if(index != -1){
            res.erase(res.begin()+res.size()-1);
            res += grammar[index];
            cout<<res<<endl;
        }
    }

    for(int i = res.size()  - 1 ; i >= 0; i--)
    {
        if(res[i] == 'E')
        {
            res[i] = str[i];
            cout<<res<<endl;
        }
    }
    return 0;
}
