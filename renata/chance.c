#include <stdio.h>

int main()
{
    int atividadescumpridas, chancedeaprovação, conceito;
    scanf(%d%d, &atividadescumpridas, &chancedeaprovação);

    if (atividadescumpridas <= 20)
    {
        chancedeaprovação = 4.40;
        conceito = "Pessimo";
    }

    return 0;
}