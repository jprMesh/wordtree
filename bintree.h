// Jonas Rogers - Mona Yuan - CS 2301 - Assignment 6 - 12/10/2015

#ifndef BINTREE_H
#define BINTREE_H

// Modified from K&R
typedef struct node {
    char *word;
    long int count;
    struct node *left;
    struct node *right;
} node;

/**
 * @brief Initialize the binary tree.
 */
void initTree();

/**
 * @brief Scan through a file and add all words to the tree.
 * 
 * @param infile string containing [path/]filename of the text file to read.
 * @return 1 if successful.
 * @return 0 if unsuccessful.
 */
int readintoTree(char* infile);

/**
 * @brief Outputs the final tree to the specified file.
 * 
 * @param outfile string containing the [path/]filename of the file to dump the
 *        output in. The file will be created if it does not exist.
 */
void outputTree(char* outfile);

/**
 * @brief Adds a node to the tree if word is new, otherwise increments count on
 *        pre-existing node.
 *        From K&R
 * 
 * @param node pointer to the node under which to search
 * @param w string containing word to add
 * 
 * @return pointer to the node that was modified.
 */
node* addNode(struct node *p, char *w);

/**
 * @brief Print the binary tree.
 *        From K&R
 * 
 * @param p pointer to the node at which to start printing
 */
void treeprint(node *p)

/**
 * @brief Frees all memory being used by the tree from node p and down
 * 
 * @param p node to start freeing at
 */
void free_tree(node *p)

#endif // BINTREE_H
