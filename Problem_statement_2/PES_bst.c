// Name:
// SRN:
#include "bst.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// Initializes the root of the bst
void init_bst(bst_t *bst)
{
    bst->root = NULL;
    
}

static node_t *add_N(node_t *node, int key, int *count_ptr);
// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr

void insert(bst_t *tree, int key, int *count_ptr)
{
    tree->root = add_N(tree->root, key, count_ptr);
}


static node_t *add_N(node_t *N, int key, int *count_ptr)
{
    if (N == NULL)
    {
        ++*count_ptr;
        node_t *temp = (node_t *)malloc(sizeof(node_t));
        temp->key = key;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (key < N->key)
    {
        ++*count_ptr;
        N->left = add_N(N->left, key, count_ptr);
    }
    else
    {
        ++*count_ptr;
        N->right = add_N(N->right, key, count_ptr);
    }
    return N;
}


static node_t *del_N(node_t *N, int key, int *count_ptr);

// Delete key from the BST
// Replaces node with in-order successor
void delete_element(bst_t *tree, int key, int *count_ptr)
{
    tree->root = del_N(tree->root, key, count_ptr);
}
static node_t *del_N(node_t *N, int key, int *count_ptr)
{
  node_t *temp;
    if (N == NULL)
        return N;
    if (key < N->key)
    {
        N->left = del_N(N->left, key, count_ptr);
    }
    else if (key > N->key)
    {
        N->right = del_N(N->right, key, count_ptr);
    }
    else
    {
        if (N->left == NULL)
        {
            ++*count_ptr;
            temp = N->right;
            free(N);
            return temp;
        }
        else if (N->right == NULL)
        {
            ++*count_ptr;
            temp = N->left;
            free(N);
            return temp;
        }
        else
        {
            temp = N->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            N->key = temp->key;
            N->right = del_N(N->right, temp->key, count_ptr);
        }
    }
    return N;
}

static int search_N(node_t *N, int key, int *count_ptr);

// Searches for the element key in the bst
// Returns the element if found, else -1

int search(const bst_t *tree, int key, int *count_ptr)
{
    return search_N(tree->root, key, count_ptr);
}
static int search_N(node_t *N, int key, int *count_ptr)
{
    int res;
    if (N == NULL)
        return -1;
    if (N->key == key)
    {
        ++*count_ptr;
        return key;
    }
    if (key < N->key)
    {
        ++*count_ptr;
        res = search_N(N->left, key, count_ptr);
    }
    else
    {
        ++*count_ptr;
        res = search_N(N->right, key, count_ptr);
    }
    return res;
}

static int find_max_N(node_t *N, int *count_ptr);

// Returns the maximum element in the BST
int find_max(const bst_t *tree, int *count_ptr)
{
    return find_max_N(tree->root, count_ptr);
}
static int find_max_N(node_t *N, int *count_ptr)
{
    if (N == NULL)
        return -1;
    if (N->right == NULL)
    {
        ++*count_ptr;
        return N->key;
    }
    find_max_N(N->right, count_ptr);
}

static void free_N(node_t *N);
// Deletes all the elements of the bst
void free_bst(bst_t *bst)
{  
    free_N(bst->root);
    free(bst);
}
static void free_N(node_t *N)
{
    if (N != NULL)
    {
        free_N(N->left);
        free_N(N->right);
        free(N);
    }
}

// Deletes all the elements if the bst and ensures it can be used again
void clear_bst(bst_t *bst)
{
    free_N(bst->root);
    bst->root = NULL;
}