#include<bits/stdc++.h>
using namespace std;

void follow(char c);

int m=0, i=0, j=0;
char followSet[10];

char production[10][10];
char firstTable[10][10];
char followTable[10][10];

vector<char> terminals;

int mark[500];

void PrintTabSpace(int j)
{
    for(int i=0; i<j; i++)
    {
        cout<<'\t';
    }
}
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


void FindTerminals()
{
     for(int i=0; i<8; i++)
    {
        for(int j=0; j<strlen(firstTable[i]); j++)
        {
            if(mark[firstTable[i][j]] == 0 && firstTable[i][j] != '#')
            {
                terminals.push_back(firstTable[i][j]);
                mark[firstTable[i][j]] = 1;
            }
        }
    }

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<strlen(followTable[i]); j++)
        {
            if(mark[followTable[i][j]] == 0 && firstTable[i][j] != '#')
            {
                terminals.push_back(followTable[i][j]);
                mark[followTable[i][j]] = 1;
            }
        }
    }

    //for (auto v : terminals)
     //   cout << v << " ";
}

void MakeParsingTable()
{
    cout<<"\n\t\tParsing table\t\t"<<endl;
    cout<<"===========================================================\n"<<endl;
    printf("%-8s","");
    for(int i=0; i<terminals.size(); i++)
    {
        //cout<<'\t'<<terminals[i];
        printf("%-8c",terminals[i]);
    }

    cout<<"\n---------------------------------------------------------------\n"<<endl;

    for(int i=0; i<8; i++)
    {
        //cout<<production[i][0]<<"      |";
        printf("%-7c|", production[i][0]);

        for(int j=0; j<terminals.size(); j++)
        {
            if(production[i][2] != '#')
            {
                int isfound = 0;
                for(int k=0; k<strlen(firstTable[i]); k++)
                {
                    if(terminals[j] == firstTable[i][k])
                    {
                        printf("%-8s",production[i]);
                        isfound = 1;
                        break;
                    }

                }

                if(isfound == 0)
                    printf("%-8s","");
            }
            else
            {
                int isfound = 0;
                for(int k=0; k<strlen(followTable[i]); k++)
                {
                    if(terminals[j] == followTable[i][k])
                    {
                        printf("%-8s",production[i]);
                        isfound = 1;
                        break;
                    }
                }

                if(isfound == 0)
                    printf("%-8s","");
            }

        }
        cout<<endl;
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

        printf("FOLLOW(%c) = {", c);

        strcpy(followTable[i], followSet);

        for(int i=0; i<m; i++)
       {
            printf("%c,",followSet[i]);

       }

        printf("}\n");

        m=0;
    }

    //construct the map
    FindTerminals();
    MakeParsingTable();

 return 0;
}
