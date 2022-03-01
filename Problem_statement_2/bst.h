#ifndef BST_H_
#define BST_H_

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct bst
{
    struct node *root;
};

typedef struct node node_t;
typedef struct bst bst_t;

// Initializes the root of the bst
void init_bst(bst_t *bst);

// Inserts element key into the Binary search tree
void insert(bst_t *tree, int key, int *count_ptr);

// Delete key from the BST
// Replaces node with in-order successor
void delete_element(bst_t *tree, int key, int *count_ptr);

// Searches for the element key in the bst
// Returns the element if found, else -1
int search(const bst_t *tree, int key, int *count_ptr);

// Returns the maximum element in the BST
int find_max(const bst_t *tree, int *count_ptr);

// Deletes all the elements of the bst
void clear_bst(bst_t *bst);

// Deletes all the elements of the bst, indicating the tree will not be used
// again
void free_bst(bst_t *bst);

#endif // BST_H_
