// Jonas Rogers - Mona Yuan - CS 2301 - Assignment 6 - 12/10/2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintree.h"

#define BUFSIZE 100
node *root;

void initTree() {
    root = NULL;
    printf("Initializing.\n");
}

int readintoTree(char* infile) {
    printf("Reading %s\n", infile);
    FILE *in = fopen(infile, "r");
    if (!in) {
        printf("Error reading file.\n");
        return 0;
    }
    fseek(in, 0, SEEK_END);
    int filelen = ftell(in);
    rewind(in);
    char* buffer = (char*) malloc(filelen);
    int result = fread(buffer, 1, filelen, in);
    fclose(in);
    if (result != filelen) {
        printf("Error reading file.\n");
        return 0;
    }
    char* word;
    char* spot = buffer;
    while((word = stringsplit(&spot))) {
        strip(&word);
        printf("word: %s\n", word);
        addNode(root, word);
    }
    free(buffer);
    return 1;
}

void outputTree(char* outfile) {
    FILE *out = fopen(outfile, "w");
    if (out) {
        treeprint(root, out);
        fclose(out);
    }
    free_tree(root);
}

node* addNode(node *p, char *w) {
    int cond;

    if (p == NULL) {
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

char* stringsplit(char* *buf) {
    char* word = strtok(*buf, " ,.-\t\n");
    if (!word)
        return 0;
    *buf += strlen(word) + 1;
    return word;
}

void treeprint(node *p, FILE *file) {
    if (p != NULL) {
        treeprint(p->left, file);
        printf("%6ld  %s\n", p->count, p->word);
        //fprintf(file, "%6ld  %s\n", p->count, p->word);
        treeprint(p->right, file);
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

void strip(char* *word) {
    while (!isalphanum((*word)[0])) {
        ++*word;
    }
    while (!isalphanum((*word)[strlen(*word)-2])) {
        *word[strlen(*word)-2] = '\0';
    }
}

int isalphanum(char ch) {
    return (ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122);
}
