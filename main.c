// Jonas Rogers - Mona Yuan - CS 2301 - Assignment 6 - 12/10/2015

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Not enough input arguments.\n"
               "Sample Usage:\n"
               "    ./PA6 outputFile inputFile1 [inputFile2] [inputFile2] ...\n");
        exit(-1);
    }

    initTree();
    int i;
    for (i = 2; i < argc; ++i) {
        readintoTree(argv[i]);
    }

    char* outFile = argv[1];
    outputTree(outFile);
    return 0;
}
