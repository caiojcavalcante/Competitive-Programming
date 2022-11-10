#include <stdio.h>

int tamanho_string(char* string)
{
    if(*string == '\0')
        return 0;
    return 1 + tamanho_string(string + 1);
}
int tamanho_string(char s[], int index)
{
    if(index == strlen(s))
        return index;
    return tamanho_string(s, index + 1);
}
int main()
{
    return 0;
}