#include <stdio.h>  
#include <assert.h>  
#include <string.h>  
#define MAX 1000                        //ÊäÈë×Ö·û´®³¤¶È  
//ÊäÈë×Ö·û´®º¯Êı  
int getline(char line[], int max)             
{  
    int ch;  
    int i = 0;  
    while (max > 0 &&  
        (ch = getchar()) != EOF && ch != '\n')  
    {  
        line[i] = ch;  
        i++;  
        max--;  
    }  
    if (ch == '\n')  
        line[i++] = '\n';  
    line[i] = '\0';  
    if (i > 0)  
        return 1;  
    else  
        return 0;  
}  
//Æ¥Åä×Ö·û´®  
int match(char line[], char *mat)  
{  
    assert(line);                       //¶ÏÑÔ  
    assert(mat);                  
    int i = 0, j = 0, k = 0;  
    for (i = 0; i < strlen(line); i++)  
    {  
        for (k = i, j = 0; j < strlen(mat); j++, k++)  
        {  
            if (line[k] != *(mat + j))  
                break;  
        }  
        if (*(mat + j) == '\0' && k>0)  
            return 1;  
    }  
    return 0;  
}  
int main()  
{  
    char line[MAX];  
    char *mat = "oul";  
    while (getline(line, MAX))  
    {  
        if (match(line, mat))  
            printf("%s", line);  
    }  
    return 0;  
} 
