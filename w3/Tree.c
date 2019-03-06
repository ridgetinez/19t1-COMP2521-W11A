#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define data(tree)  ((tree)->value)
#define left(tree)  ((tree)->left)
#define right(tree) ((tree)->right)

typedef struct _tree {
    int value;
    struct _tree *left, *right;
} *Tree;

int max(int a, int b) {
    return (a > b) ? a : b;
}
// make a new node containing data
Tree newNode(int it) {
   Tree new = malloc(sizeof(struct _tree));
   assert(new != NULL);
   data(new) = it;
   left(new) = right(new) = NULL;
   return new;
}

// create a new empty Tree
Tree newTree() {
   return NULL;
}

// free memory associated with Tree
void freeTree(Tree t) {
   if (t != NULL) {
      freeTree(left(t));
      freeTree(right(t));
      free(t);
   }
}

// display Tree sideways
void showTreeR(Tree t, int depth) {
   if (t != NULL) {
      showTreeR(right(t), depth+1);
      int i;
      for (i = 0; i < depth; i++)
	 putchar('\t');            // TAB character
      printf("%d\n", data(t));
      showTreeR(left(t), depth+1);
   }
}

void showTree(Tree t) {
   showTreeR(t, 0);
}

// insert a new item into a Tree
Tree TreeInsert(Tree t, int it) {
   if (t == NULL)
      t = newNode(it);
   else if (it < data(t))
      left(t) = TreeInsert(left(t), it);
   else if (it > data(t))
      right(t) = TreeInsert(right(t), it);
   return t;
}

// ? Q1: Starting from t = NULL, what does the tree look like when inserting:
// ?    (a) 1 2 3 4 5 6 7 9 10 (sorted order)
// ?    (b) 10 9 8 7 6 5 4 3 2 1 (reverse order)
// ?    (c) 4 3 1 2 6 5 7 (prefix order)

// ? Q2: Say we have a complete tree of height N (N layers)
// ?     How many nodes do we have in this tree?

int countNodes(Tree);


int countNodes(Tree t) {
    if (t == NULL) return 0;
    return 1 + countNodes(t->left) + countNodes(t->right);
}

// the maximum number of nodes along the longest path from root to leaf.
int height(Tree t) {
    if (t == NULL) return 0;
    return 1 + max(height(t->left), height(t->right));
}

// Q5
// Compute the width of a tree, where each node has width 3
int width(Tree t) {
    if (t == NULL) return 0;
    return width(t->left) + width(t->right) + 3;
}

// Q4
// The number of edges on the longest path from root to leaf
int treeMaxBranchLen(Tree t) {
    if (t == NULL) return 0;
    if (t->left == NULL && t->right == NULL) return 0;
    return max(treeMaxBranchLen(t->left), treeMaxBranchLen(t->right)) + 1;
}

// Q2.
// We define an internal node to be any node node that can be retrieved by some sequence of
// BOTH t->left AND t->right.
int countInternal(Tree t) {
    if (t == NULL) return 0;
    Tree currLeft = t->left;
    Tree currRight = t->right;
    int sumNodes = 0;
    while (currLeft != NULL) {
        sumNodes += countNodes(currLeft->right);
        currLeft = currLeft->left;
    }
    while (currRight != NULL) {
        sumNodes += countNodes(currRight->left);
        currRight = currRight->right;
    }
    return sumNodes;
}

// Q3
// Given a binary search tree, find the depth (numNodes in path from root)
// else return -1 (not found)
int nodeDepth(Tree t, int key) {
    if (t == NULL) return -1;
    if (t->value == key) return 0;
    int found;
    if (key < t->value) {
        found = nodeDepth(t->left, key);
    } else {
        found = nodeDepth(t->right, key);
    }
    return found == -1 ? found : found + 1;
}


Tree constructN(int n) {
    int values[13] = {5, 8, 3, 4, 9, 1, 7, 20, 21, 0, 2, 16, 11};
    int i;
    Tree t = NULL;
    for (i = 0; i < 13; i++) {
        t = TreeInsert(t, values[i]);
    }
    return t;
}

void infix(Tree t) {
    infix(t->left);
    printf("%d\n", t->value);
    infix(t->right);
}

void prefix(Tree t) {
    printf("%d\n", t->value);
    prefix(t->left);
    prefix(t->right);
}

void postfix(Tree t) {
    postfix(t->left);
    postfix(t->right);
    printf("%d\n", t->value);
}

void test_em(Tree t) {
    if (t  != NULL) {
        showTree(t);
    }
    printf("countInternal: %d\n", countInternal(t));
    printf("height: %d\n\n", height(t));

    printf("nodeDepth for 21: %d\n", nodeDepth(t, 21));
    printf("nodeDepth for -1: %d\n", nodeDepth(t, -1));
    printf("nodeDepth for 6: %d\n", nodeDepth(t, 6));
    printf("nodeDepth for 2: %d\n\n", nodeDepth(t, 2));

    printf("treeMaxBranchLen: %d\n\n", treeMaxBranchLen(t));

    printf("width: %d\n", width(t));
}

int main(void) {
    test_em(constructN(7));
    //test_em(NULL);
    //test_em(TreeInsert(NULL, 2));
}
