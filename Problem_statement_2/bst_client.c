#include "bst.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Copies a simple integer array to the data structure
void copy_array(bst_t *dst, const int *src, int n)
{
    int c = 0;
    for (int i = 0; i < n; ++i)
    {
        c = 0;
        insert(dst, src[i], &c);
    }
}

int print_if(int i)
{
    return i < 10 || (i < 100 && !(i % 10)) || (i < 1000 && !(i % 50)) ||
           (i < 10000 && !(i % 200));
}

void randomize_insert(bst_t *b, int n, int p)
{
    int c;
    for (int i = 1; i <= n; ++i)
    {
        c = 0;
        insert(b, rand() % n + 1, &c);
        if (p && print_if(i))
            printf("%d,%d\n", i, c);
    }
}

void ordered_insert(bst_t *b, int n, int p)
{
    int c;
    for (int i = 1; i <= n; ++i)
    {
        c = 0;
        insert(b, i, &c);
        if (p && print_if(i))
            printf("%d,%d\n", i, c);
    }
}
int main()
{
    srand(0);
    const int n = 1000;
    bst_t b;
    init_bst(&b);

    /*
    **
    ** A few test cases to ensure correct functioning of basic operations
    **
    */

    int a[] = {6, 3, 7, 4, 8, 1, 5, 9, 2, 0};
    copy_array(&b, a, 10);
    int c = 0;
    for (int i = 0; i < 10; ++i)
    {
        c = 0;
        assert(search(&b, a[i], &c) == a[i]);
    }
    c = 0;
    assert(find_max(&b, &c) == 9);

    for (int i = 0; i < 10; ++i)
    {
        c = 0;
        delete_element(&b, a[i], &c);
        c = 0;
        assert(search(&b, a[i], &c) == -1);
        if (i == 9)
            break;
        int max = a[i + 1];
        for (int j = i + 1; j < 10; ++j)
        {
            c = 0;
            assert(search(&b, a[j], &c) == a[j]);
            if (a[j] > max)
                max = a[j];
        }
        c = 0;
        assert(find_max(&b, &c) == max);
    }
    c = 0;
    assert(find_max(&b, &c) == -1);
    c = 0;
    clear_bst(&b);

    /*
    **
    ** Analysis of asymptotic complexities of binary search tree operations
    **
    */

    printf("DS: BST\n"
           "Operation: Insert\n"
           "Input: In order insert\n\n");
    ordered_insert(&b, n, 1);
    clear_bst(&b);

    printf("\nInput: Random Inserts\n");
    randomize_insert(&b, n, 1);
    clear_bst(&b);

    printf("\nOperation: Search\n"
           "\nInput: Random element in random tree\n\n");
    for (int i = 1; i < n; ++i)
    {
        if (print_if(i))
        {
            int c = 0;
            randomize_insert(&b, i, 0);
            search(&b, rand() % i + 1, &c);
            printf("%d,%d\n", i, c);
            clear_bst(&b);
        }
    }

    printf("\nInput: Random element in ordered tree\n\n");
    for (int i = 1; i < n; ++i)
    {
        if (print_if(i))
        {
            int c = 0;
            ordered_insert(&b, i, 0);
            search(&b, rand() % i + 1, &c);
            printf("%d,%d\n", i, c);
            clear_bst(&b);
        }
    }

    printf("\nInput: Element not present in ordered tree\n\n");
    for (int i = 1; i < n; ++i)
    {
        if (print_if(i))
        {
            int c = 0;
            ordered_insert(&b, i, 0);
            search(&b, rand() + 1, &c);
            printf("%d,%d\n", i, c);
            clear_bst(&b);
        }
    }

    printf("\nOperation: delete_element\n"
           "\nInput: Random element from random tree\n\n");
    for (int i = 1; i < n; ++i)
    {
        if (print_if(i))
        {
            int c = 0;
            randomize_insert(&b, i, 0);
            delete_element(&b, rand() % i + 1, &c);
            printf("%d,%d\n", i, c);
            clear_bst(&b);
        }
    }

    printf("\nInput: Random element from ordered tree\n\n");
    for (int i = 1; i < n; ++i)
    {
        if (print_if(i))
        {
            int c = 0;
            ordered_insert(&b, i, 0);
            delete_element(&b, rand() % i + 1, &c);
            printf("%d,%d\n", i, c);
            clear_bst(&b);
        }
    }
    printf("\nInput: Extreme element from ordered tree\n\n");
    for (int i = 1; i < n; ++i)
    {
        if (print_if(i))
        {
            int c = 0;
            ordered_insert(&b, i, 0);
            delete_element(&b, i, &c);
            printf("%d,%d\n", i, c);
            clear_bst(&b);
        }
    }
}
