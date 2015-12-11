// Jonas Rogers - Mona Yuan - CS 2301 - Assignment 6 - 12/10/2015

#include <stdio.h>
#include "bintree.h"

node *root;

void initTree() {
    ;
}

int readintoTree(char* infile) {
    FILE *in = fopen(infile, "r");
    if (in) {
        
        fclose(in);
    }
    return 0;
}

void outputTree(char* outfile) {
    FILE *out = fopen(outfile, "w");
    if (out) {
        // do stuff
        fclose(out);
    }
}

node* addNode(struct node *p, char *w) {
    int cond;

    if(p == NULL) {
        p = malloc(sizeof(node)); // allocates memory for the new node
        p -> word = strdup(w);
        p -> count = 1;
        p -> left = p -> right = NULL;
    }

    else if ((cond = strcmp(w, p -> word)) == 0)
        p -> count++;

    else if (cond < 0)
        p -> left = addNode(p -> left, w);

    else
        p -> right = addNode(p -> right, w);

    return p;
}

void treeprint(node *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%6d  %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

void free_tree(node *p) {
    if(p != NULL) {
        free_tree(p->left);
        free_tree(p->right);
        free( p->word );
        free( p );
    }
}
