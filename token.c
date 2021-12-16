#include<stdio.h>
#include <stdbool.h>
#include <ctype.h>


bool isValidKeyword(char* str)
{
   if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") ||    !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int")
   || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str,    "char") || !strcmp(str, "case") || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned")
   || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
   return (true);
   return (false);
}

bool isValidInteger(char* str)
{
   int i, len = strlen(str);
   if (len == 0)
        return (false);
   for (i = 0; i < len; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return (false);
   }
   return (true);
}

bool isValidOperator(char *str)
{
    if(strcmp(str,"+") == 0 || strcmp(str,"-") == 0 || strcmp(str,"*") == 0||
        strcmp(str,"/") == 0 ||strcmp(str,"^") == 0 || strcmp(str,"=") == 0)
        return 1;
    return 0;
}

bool isvalidIdentifier(char* str)
{
   if ((tolower(str[0]) >= 'a' && tolower(str[0]) <= 'z') || str[0] == '_')
   return true;
   return false;
}

bool isValidFloat(char* str)
{
    int onlyOneDot = 0;
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i] == '.')
            onlyOneDot = 1;
        if((str[i]>='0'&& str[i] <= '9')||(str[i]=='.' && onlyOneDot == 1)){}
        else
            return 0;
    }
    return 1;
}

int main()
{
    char str[500];

    while(gets(str))
    {
        if(isValidKeyword(str))
        {
            puts("Keyword");
        }
        else if(isValidOperator(str))
        {
            puts("Arithmetic Operator");
        }
        else if(isvalidIdentifier(str))
        {
            puts("Identifier");
        }
        else if(isValidInteger(str))
        {
            puts("Integer");
        }
        else if(isValidFloat(str))
        {
            puts("Float");
        }
        else
            puts("Invalid");
    }
    return 0;
}
