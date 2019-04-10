#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "GenTree.h"

void printInt(void *);
void printStr(void *);
int cmpInt(void *, void *);
int cmpStr(void *, void *);

int main(void)
{
    GTree intT = initGTree(&cmpInt, &printInt);
    GTree strT = initGTree(&cmpStr, &printStr);

    int *vs = malloc(5 * sizeof(int));
    vs[0] = 3;
    vs[1] = 2;
    vs[2] = 1;
    vs[3] = 4;
    vs[4] = 5;
    for (int i = 0; i < 5; i++) insertGTree(intT, &vs[i]);
    printGTree(intT);
}

void printInt(void *a)
{
    printf("%d", *(int *)a);
}

void printStr(void *a)
{
    printf("%s", (char *)a);
}

int cmpInt(void *a, void *b)
{
    int *p_a = (int *)a;
    int *p_b = (int *)b;
    return *p_a - *p_b;
}

int cmpStr(void *a, void *b)
{
    char *p_a = (char *)a;
    char *p_b = (char *)b;
    return strcmp(p_a, p_b);
}