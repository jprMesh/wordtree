// Jonas Rogers - Mona Yuan - CS 2301 - Assignment 6 - 12/10/2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bintree.h"

#define BUFSIZE 100
node *root;
int wordcount;

void initTree() {
    printf("Initializing.\n");
    root = NULL;
    wordcount = 0;
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
    while (spot < buffer + filelen) {
        if ((word = getword(&spot))) {
            if (strip(&word)) {
                for (int i = 0; i < strlen(word); ++i)
                    word[i] = tolower(word[i]);
                node *temp = addNode(root, word);
                if (root == NULL)
                    root = temp;
            }
        }
    }
    free(buffer);
    return 1;
}

void outputTree(char* outfile) {
    printf("Outputting tree to file %s\n", outfile);
    FILE *out = fopen(outfile, "w");
    if (out) {
        treeprint(root, out);
        fprintf(out, "----------------------------------------\n");
        fprintf(out, "%6d  Total number of unique words\n", wordcount);
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
        ++wordcount;
    }

    else if ((cond = strcmp(w, p -> word)) == 0)
        p -> count++;

    else if (cond < 0)
        p -> left = addNode(p -> left, w);

    else
        p -> right = addNode(p -> right, w);

    return p;
}

char* getword(char **buf) {
    char* word = strtok(*buf, " /\n");
    if (!word) {
        *buf += 1;
        return 0;
    }
    *buf += strlen(word) + 1;
    return word;
}

void treeprint(node *p, FILE *file) {
    if (p != NULL) {
        treeprint(p->left, file);
        // printf("%6ld  %s\n", p->count, p->word);
        fprintf(file, "%6ld  %s\n", p->count, p->word);
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

int strip(char* *word) {
    int length = strlen(*word);
    while (!isalphanum((*word)[0])) {
        ++*word;
        --length;
        if (length == 0)
            return 0;
    }
    while (!isalphanum((*word)[length-1])) {
        (*word)[strlen(*word)-1] = '\0';
        length = strlen(*word);
    }
    return 1;
}

int isalphanum(char ch) {
    return (ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122);
}
