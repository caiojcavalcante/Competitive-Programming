#include <stdio.h>
#include <string.h>

int main()
{
    char s0[100005];
    char s1[100005];
    scanf("%s", s0);
    
    int i = 0;
    
    while(s0[i] != '[') i++;
    s0[i] = '\0';
    
    //printf("%c", s0[i + 1]);
    
    for(int j = 0; s0[j + i + 1] != '\0'; j++)
    {
        printf("%c", s0[j + i + 1]);
    }
        
    printf("%s", s1);
}