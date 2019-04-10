
#ifndef GTREE_H
#define GTREE_H

typedef struct _GTree *GTree;

GTree initGTree(int (*cmp)(void *, void *), void (*print)(void *));
void insertGTree(GTree, void *);
void printGTree(GTree);

#endif