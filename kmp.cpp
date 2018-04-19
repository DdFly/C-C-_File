#include <stdio.h>  
#include <assert.h>  
#include <string.h>  
#define MAX 50                       //ÊäÈë×Ö·û´®³¤¶È  
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
	int n=0;
    char line[MAX];  
    char mat[MAX];
    gets(line);
    gets(mat);
    printf("%s\n%s",line,mat);
    while (getline(line,MAX))  
    {  
        if (match(line, mat))  
            n++; 
    } 
	printf("%d",n); 
    return 0;  
} 
