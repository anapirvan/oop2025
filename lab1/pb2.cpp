

#include <iostream>
int length(char str[])
{
     int l = 0, i;
     for (i = 0;str[i];i++)
         l++;
     return l;
}
 void customSwap(char str1[], char str2[])
 {
     char aux[100];
     int i;
     for (i = 0;str1[i];i++)
         aux[i] = str1[i];
     aux[i] = 0;
     for (i = 0;str2[i];i++)
         str1[i] = str2[i];
     str1[i] = 0;
     for (i = 0;aux[i];i++)
         str2[i] = aux[i];
     str2[i]=0;
           
 }
 bool lowercaseLetter(char c)
 {
     return (c >= 'a' and c <= 'z');
 }
 bool uppercaseLetter(char c)
 {
     return (c >= 'A' and c <= 'Z');
 }
 bool alphabeticSort(char str1[],char str2[])
 {
     int i;
     for (i = 0;str1[i];i++)
     {
         if (lowercaseLetter(str1[i]) && uppercaseLetter(str2[i]))
         {
             if (str1[i] > str2[i] + 32)
                 return 0;
             else
                 if (str1[i] < str2[i] + 32)
                     return 1;

         }
         else
             if (uppercaseLetter(str1[i]) && lowercaseLetter(str2[i]))
             {
                 if (str1[i] + 32 > str2[i])
                     return 0;
                 else
                     if (str1[i] + 32 < str2[i])
                         return 1;
             }
             else
                 if (str1[i] > str2[i])
                     return 0;
                 else
                     if (str1[i] < str2[i])
                         return 1;

     }
     return 1;
 }
 
int main()
{
    int i, j, line = 0, length1, length2, m, n;
    bool sorted;
    char str[1000], a[1000][1000],word[100];
    scanf("%[^\n]s", str);
    n = length(str);
    for (i = 0;i<n - 1;i++)
        if (str[i] != ' ')
        {
            m = 0;
            for (j = i;str[j] != ' ' and str[j]!=NULL ;j++)
            {
                word[m] = str[j];
                m++;
            }
            word[m] = 0;
            i = j;
            line++;
            for (j = 0;word[j];j++)
                a[line][j] = word[j];
            a[line][j] = 0;
        }
    
    do
    {
        sorted= 1;
        for (i = 1;i < line;i++)
        {
            length1 = length(a[i]);
            length2 = length(a[i+1]);
            if (length1 < length2)
            {
                customSwap(a[i], a[i + 1]);
                sorted = 0;
            }
            else
                if (length1 == length2 && !alphabeticSort(a[i], a[i+1]))
                {
                    customSwap(a[i], a[i + 1]);
                    sorted = 0;
                }
        }
    } while (!sorted);
    for (i = 1;i <= line;i++)
        printf("%s\n", a[i]);
    return 0;
}

