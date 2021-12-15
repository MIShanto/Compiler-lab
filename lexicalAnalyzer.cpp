#include<bits/stdc++.h>
using namespace std;

char str[500];

bool isAllDigit()
{
    for(int i=0; str[i];i++)
    {
        if(str[i]<'0'||str[i]>'9')
            return 0;
    }
    return 1;
}

bool isValidFloat(int len)
{
    int onlyOneDot = 0;
    for(int i=0; i<len; i++)
    {
        if(str[i] == '.')
            onlyOneDot = 1;
        if((str[i]>='0'&& str[i] <= '9')||(str[i]=='.' && onlyOneDot == 1)){}
        else
            return 0;
    }
    return 1;
}
bool isValidForOtherCases(int len)
{
    for(int i=0; i<len; i++)
    {
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')){}
        else
            return 0;
    }
    return 1;
}
int isFloat(int len)
{
    int cnt = 0,i, startCounting = 0;

    for(i=0; i< len; i++)
    {
        if(startCounting == 1)
        {
            cnt++;
        }
        if(str[i] == '.')
        {
            startCounting = 1;
        }

    }
    return cnt;
}

bool isValidFor_Char_Bin_Cases(int len)
{
    int onlyOneUnderscore = 0;
    for(int i=0; i<len; i++)
    {
        if(str[i] == '_')
            onlyOneUnderscore = 1;
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || (str[i] == '_' && onlyOneUnderscore == 1 )){}
        else
            return 0;
    }
    return 1;
}

bool isValidBinary(int len)
{
    for(int i=0; i<len; i++)
    {
        if(str[i] == '0' || str[i] == '1'){}
        else
            return 0;
    }
    return 1;
}

int main()
{
    gets(str);

    int ln = strlen(str);

    if(isValidForOtherCases(ln) && ((str[0]>='i'&&str[0]<='n')||(str[0]>='I'&&str[0]<='N')))
    {
        puts("Integer Variable");
    }
    else if(isAllDigit() && (str[0]>='1'&&str[0]<='9') && ln<=4)
    {
        puts("Short Integer");
    }
    else if(isAllDigit() && (str[0]>='1'&& str[0]<='9'))
    {
        puts("Long Integer");
    }
    else if(isValidForOtherCases(ln) && ((str[0]>='a'&&str[0]<='h')||(str[0]>='A'&&str[0]<='H')||(str[0]>='o'&&str[0]<='z')||(str[0]>='O'&&str[0]<='Z')))
    {
        puts("Float Variable");
    }
    else if(isValidFloat(ln) &&((isFloat(ln) ==2) && ((str[0]>='1'&&str[0]<='9')||(str[0]=='0' && str[1] == '.'))))
    {
        puts("Float Number");
    }
    else if(isValidFloat(ln) && ((isFloat(ln) > 2) && ((str[0]>='1'&&str[0]<='9')||(str[0]=='0' && str[1] == '.'))))
    {
       puts("Double Number");
    }
    else if(isValidFor_Char_Bin_Cases(ln)&&( str[0]=='c'&&str[1]=='h'&&str[2]=='_'))
    {
        puts("Character Variable");
    }
    else if(isValidFor_Char_Bin_Cases(ln)&&( str[0]=='b'&&str[1]=='h'&&str[2]=='_'))
    {
        puts("Binary Variable");
    }
    else if(isValidBinary(ln) && str[0]=='0')
    {
        puts("Binary Number");
    }
    else
        puts("Invalid Input or Undefined");

    return 0;
}
