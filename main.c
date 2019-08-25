#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main()
{
    int rozmiar;
    printf("Podaj rozmiar tablicy:\n");
    if (scanf("%d", &rozmiar)==0)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (rozmiar<1)
    {
        printf("Incorrect input data");
        return 2;
    }
    struct array_t tab;
    if (array_create(&tab, rozmiar)==2)
    {
        printf("Failed to allocate memory\n");
        return 8;
    }


    int i=0;
    int liczba=1;
    int buffer=0;
    printf("Podaj liczby do zapisania:\n");
    while(liczba!=0)
    {
        if (scanf("%d", &liczba)==0)
        {
            printf("Incorrect input\n");
            array_destroy(&tab);
            return 1;
        }
        if (buffer==0)
        {
            buffer = array_push_back(&tab, liczba);
        }
        i++;
    }

    if (i==1) printf("Buffer is empty\n");
    else if (buffer==2)
    {
        printf("Buffer is full\n");
        array_display(&tab);
    }
    else array_display(&tab);

    array_destroy(&tab);

    return 0;
}
