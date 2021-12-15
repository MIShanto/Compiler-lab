#include<stdio.h>
#include<string.h>

char name[] = "  Md. Tareq Zaman, Part-3, 2011";

char words[100][100];

int isLetter(char c)
{
    if(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
        return 1;
    else
        return 0;
}

int isDigit(char c)
{
    if(c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

int isOther(char c)
{
    if(!isLetter(c) && !isDigit(c) && c != ' ')
        return 1;
    else
        return 0;
}

void SeperateLetters()
{
    int i;

    printf("Seperated Letters: ");
    for(i=0; i<strlen(name)-1; i++)
    {
        if(isLetter(name[i]))
            printf("%c ", name[i]);
    }
    printf("%c\n\n" ,name[i]);
}

void SeperateDigits()
{
    int i;

    printf("Seperated Digits: ");
    for(i=0; i<strlen(name)-1; i++)
    {
        if(isDigit(name[i]))
            printf("%c ", name[i]);
    }
    printf("%c\n\n" ,name[i]);
}

void SeperateOthers()
{
    int i;

    printf("Seperated Other Characters: ");
    for(i=0; i<strlen(name)-1; i++)
    {
        if(isOther(name[i]))
            printf("%c ", name[i]);
    }
    printf("%c\n\n" ,name[i]);
}

int IsVowels(char c)
{
    if(isLetter(c))
    {
         if(c =='a' ||c =='A' ||c =='e' ||c =='E' ||c =='i' ||c =='I' ||c =='o' ||c =='O' ||c =='u' ||c =='U' )
            return 1;
        else
            return -1;
    }

}

int FindWords()
{
    int i,j,k;

    for(i=0,k=0; k<strlen(name);)
    {
        for(j=0; j<strlen(name); j++)
        {

            if(name[k] != ' ' && name[k] != '\0')
            {
                if(k!=0)
                {
                    if(name[k-1]==' ')
                    {
                        if(words[0][0]!=0)
                            i++;
                    }
                }

                words[i][j] = name[k];
                k++;
            }
            else
            {
                k++;
                break;
            }
        }
    }

    return i+1;
}

void ShowVowelWords(int wc)
{
    printf("String Contains only vowel words: ");

    int i,j,k;
    for(i=0; i<wc; i++)
    {
        if(IsVowels(words[i][0]) == 1)
        {
            for(j=0; words[i][j]!='\0' ; j++)
            {
                printf("%c", words[i][j]);
            }

        }
    }
    printf("\n");
}

void ShowConsonatWords(int wc)
{
    printf("String Contains only Consonat words: ");

    int i,j,k;
    for(i=0; i<wc; i++)
    {
        if(IsVowels(words[i][0]) == -1)
        {
            for(j=0; words[i][j]!='\0' ; j++)
            {
                printf("%c", words[i][j]);
            }

        }
    }
    printf("\n");
}

void FindVowelsConsonants()
{
    int i;

    printf("Existed Vowels in the string: ");

    for(i=0; i<strlen(name); i++)
    {
        if(IsVowels(name[i]) == 1)
            printf("%c ", name[i]);
    }
    printf("\n\n");

    printf("Existed Consonants in the string: ");

    for(i=0; i<strlen(name); i++)
    {
        if(IsVowels(name[i]) == -1)
            printf("%c ", name[i]);
    }
    printf("\n\n");
}
int main()
{
    int wordCount, lettersCount, digitCount, othersCount, delimCount, vowelCount, ConsonantsCount;
    int i;

    wordCount = lettersCount = digitCount = othersCount = delimCount  = vowelCount = ConsonantsCount = 0;

    printf("Input String: %s\n\n", name);

    SeperateLetters();
    SeperateDigits();
    SeperateOthers();
    FindVowelsConsonants();
    wordCount = FindWords();
    ShowVowelWords(wordCount);
    ShowConsonatWords(wordCount);

    for(i=0; i<strlen(name); i++)
    {
        if(isLetter(name[i]))
        {
             lettersCount++;
             delimCount = 0;
        }

        if(isDigit(name[i]))
        {
            digitCount++;
            delimCount = 0;
        }

        if(isOther(name[i]))
        {
             othersCount++;
             delimCount = 0;
        }

        if(IsVowels(name[i]) == 1)
            vowelCount++;

    }

    ConsonantsCount = lettersCount - vowelCount;

    printf("Number of Words: %d\nNumber of Letters: %d\nNumber of Digits: %d\nNumber of Other characters: %d\nNumber of Vowels: %d\nNumber of Consonants %d\n",
           wordCount, lettersCount, digitCount, othersCount, vowelCount, ConsonantsCount);

    return 0;
}
