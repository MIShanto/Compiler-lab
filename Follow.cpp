#include<bits/stdc++.h>
using namespace std;

void follow(char c);

int m=0, i=0, j=0, index_first_table = 0, index_follow_table = 0;
char followSet[10];

char production[10][10];
char firstTable[10][10];
char followTable[10][10];

map< char, map< char, string> > mp;

void follow(char c)
{
     if(production[0][0] == c)
        followSet[m++]='$';

     for(i=0; i<8; i++)
     {
          for(j=2; j<strlen(production[i]); j++)
          {
               if(production[i][j] == c)
               {
                   if(production[i][j+1] != '\0')
                   {
                       char ch = production[i][j+1];

                       if(!isupper(production[i][j+1])) // if terminal
                       {
                           followSet[m++]=ch;
                       }
                       else
                       {
                           //find which index has the non terminal
                           for (int l = 0; l<8; l++)
                           {
                               if(production[l][0] == ch)
                               {
                                   for(int n=0; firstTable[l][n]!='\0'; n++)
                                   {
                                       if(firstTable[l][n] == '#')
                                            follow(production[i][0]);
                                       else
                                            followSet[m++] = firstTable[l][n];
                                   }
                               }
                           }
                       }
                   }

                    if(production[i][j+1]=='\0' && c!=production[i][0])
                        follow(production[i][0]);
               }
          }
     }
}


void MakeParsingTable()
{
    mp.insert({ 'c', {'b', "hi"} });
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout<<itr->first<<'\t'<<endl;//itr->second <<endl;//'\n';
    }

}
int main()
{
    int z;
    char c;

    //  The Input grammar
    strcpy(production[0], "E=TR");
    strcpy(production[1], "R=+TR");
    strcpy(production[2], "R=#");
    strcpy(production[3], "T=FY");
    strcpy(production[4], "Y=*FY");
    strcpy(production[5], "Y=#");
    strcpy(production[6], "F=(E)");
    strcpy(production[7], "F=i");

    // The First table
    strcpy(firstTable[0], "i(");
    strcpy(firstTable[1], "+");
    strcpy(firstTable[2], "#");
    strcpy(firstTable[3], "i(");
    strcpy(firstTable[4], "*");
    strcpy(firstTable[5], "#");
    strcpy(firstTable[6], "(");
    strcpy(firstTable[7], "i");

    m=0;

    for(int i=0; i<8; i++)
    {
        c = production[i][0];

        follow(c);

        printf("FOLLOW(%c) = { ", c);

        strcpy(followTable[i], followSet);

        for(int i=0; i<m; i++)
       {
            printf("%c, ",followSet[i]);

       }

        printf("}\n");

        m=0;
    }

    //construct the map
    MakeParsingTable();

 return 0;
}
