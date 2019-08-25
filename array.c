#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int array_create(struct array_t *a, int N)
{
    if (a==NULL) return 1;
    else if (N<1) return 1;

    a->ptr = malloc(sizeof(int)*N);
    if (a->ptr==NULL) return 2;

    a->size = 0;
    a->capacity = N;

    return 0;
}

int array_push_back(struct array_t *a, int value)
{
    if (a==NULL || a->ptr == NULL) return 1;
    else if (a->size <0 || a->capacity <=0) return 1;
    else if (a->size > a->capacity) return 1;
    else if (a->size == a->capacity) return 2;
    else
    {
        *(a->ptr+(a->size)) = value;
        (a->size)++;
        return 0;
    }
}

void array_display(const struct array_t *a)
{
    if (a==NULL || a->ptr==NULL) return;
    if (a->size>a->capacity) return;
    for (int i=0; i <(a->size); i++)
    {
        printf("%d ", *(a->ptr+i));
    }
}

void array_destroy(struct array_t *a)
{
    if (a==NULL || a->ptr==NULL) return;

    free(a->ptr);
}
