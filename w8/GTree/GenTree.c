#include <stdio.h>
#include <stdlib.h>
#include "GenTree.h"

typedef struct _GTreeNode {
    void *val;
    struct _GTreeNode *left, *right;
} *GTreeLink;

struct _GTree {
    GTreeLink root;
    int (*cmp)(void *, void *);
    void (*print)(void *);
};

static GTreeLink initGTreeNode(void *);

GTree initGTree(int (*cmp)(void *, void *), void (*print)(void *))
{
    GTree t = malloc(sizeof(struct _GTree));
    if (t == NULL) {
        return NULL;
    }
    t->root = NULL;
    t->cmp = cmp;
    t->print = print;
    return t;
}

GTreeLink insertGTreeR(GTreeLink t, void *v, int (*cmp)(void *, void *))
{
    if (t == NULL) return initGTreeNode(v);
    int cmpKey = cmp(t->val, v);
    if (cmpKey > 0) {
        t->left = insertGTreeR(t->left, v, cmp);
    } else {
        t->right = insertGTreeR(t->right, v, cmp);
    }
    return t;
}

void insertGTree(GTree t, void *v)
{
    t->root = insertGTreeR(t->root, v, t->cmp);
}

/* Print in infix order */
void printGTreeR(GTreeLink t, void (*print)(void *))
{   
    if (t == NULL) return;
    print(t->val);
    printf("\n");
    printGTreeR(t->left, print);
    printGTreeR(t->right, print);
}

void printGTree(GTree t)
{
    printGTreeR(t->root, t->print);
}

/* We should definitely be deep copying these pointers
 * however for now we'll just shallow copy the pointer over
 * and be peachy with this MVP. */
static GTreeLink initGTreeNode(void *v)
{
    GTreeLink t = malloc(sizeof(struct _GTreeNode));
    if (t == NULL) return t;
    t->val = v;
    t->left = t->right = NULL;
    return t;
}
