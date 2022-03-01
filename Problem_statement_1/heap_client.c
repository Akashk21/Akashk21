#include "heap.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Copies a simple integer array to the data structure
void copy_array(heap_t *dst, const int *src, int n)
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

void randomize_insert(heap_t *b, int n, int p)
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

void ordered_insert(heap_t *b, int n, int p)
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

void reversed_insert(heap_t *b, int n, int p)
{
    int c;
    for (int i = 1; i <= n; ++i)
    {
        c = 0;
        insert(b, n - i, &c);
        if (p && print_if(i))
            printf("%d,%d\n", i, c);
    }
}
int main()
{
    srand(0);
    const int n = 1000;
    heap_t h;
    init_heap(&h, n);

    /*
    **
    ** A few test cases to ensure correct functioning of basic operations
    **
    */

    int a[] = {6, 3, 7, 4, 8, 1, 5, 9, 2, 0};
    copy_array(&h, a, 10);
    int c = 0;
    assert(find_max(&h, &c) == 9);
    c = 0;
    assert(extract_max(&h, &c) == 9);
    c = 0;
    assert(search(&h, 4, &c) == 4);
    c = 0;
    assert(search(&h, 10, &c) == -1);
    c = 0;
    assert(find_max(&h, &c) == 8);
    c = 0;
    assert(find_min(&h, &c) == 0);
    c = 0;
    clear_heap(&h);

    /*
    **
    ** Analysis of asymptotic complexities of Heap operations
    **
    */

    printf("DS: Max Heap\n"
           "Operation: Insert\n"
           "Input: In order insert\n\n");
    ordered_insert(&h, n, 1);
    clear_heap(&h);

    printf("\nInput: Random Inserts\n\n");
    randomize_insert(&h, n, 1);
    clear_heap(&h);

    printf("\nInput: Reversed Inserts\n\n");
    reversed_insert(&h, n, 1);
    clear_heap(&h);

    printf("\nOperation: Find Max\n"
           "\nInput: Random inserted Heap\n\n");
    for (int i = 1; i <= n; ++i)
    {
        if (print_if(i))
        {
            randomize_insert(&h, n, 0);
            int c = 0;
            find_max(&h, &c);
            printf("%d,%d\n", i, c);
            clear_heap(&h);
        }
    }
    printf("\nInput: Ordered inserted Heap\n\n");
    for (int i = 1; i <= n; ++i)
    {
        if (print_if(i))
        {
            ordered_insert(&h, n, 0);
            int c = 0;
            find_max(&h, &c);
            printf("%d,%d\n", i, c);
            clear_heap(&h);
        }
    }
    printf("\nOperation: Delete_max\n"
           "\nInput: Random inserted tree\n\n");
    for (int i = 1; i <= n; ++i)
    {
        if (print_if(i))
        {
            int c = 0;
            randomize_insert(&h, i, 0);
            extract_max(&h, &c);
            printf("%d,%d\n", i, c);
            clear_heap(&h);
        }
    }
    printf("\nInput: Ordered delete on random inserted heap\n\n");
    randomize_insert(&h, n, 0);
    for (int i = n; i >= 1; --i)
    {
        int c = 0;
        extract_max(&h, &c);
        if (print_if(i))
        {
            printf("%d,%d\n", i, c);
        }
    }
    clear_heap(&h);
    printf("\nOperation: Search\n"
           "\nInput: Random element in random tree\n\n");
    for (int i = 1; i < n; ++i)
    {
        if (print_if(i))
        {
            int c = 0;
            randomize_insert(&h, i, 0);
            search(&h, rand() % i + 1, &c);
            printf("%d,%d\n", i, c);
            clear_heap(&h);
        }
    }

    printf("\nInput: Random element in ordered tree\n\n");
    for (int i = 1; i < n; ++i)
    {
        if (print_if(i))
        {
            int c = 0;
            ordered_insert(&h, i, 0);
            search(&h, rand() % i + 1, &c);
            printf("%d,%d\n", i, c);
            clear_heap(&h);
        }
    }

    printf("\nInput: Element not present in ordered tree\n\n");
    for (int i = 1; i < n; ++i)
    {
        if (print_if(i))
        {
            int c = 0;
            ordered_insert(&h, i, 0);
            search(&h, rand() + 1, &c);
            printf("%d,%d\n", i, c);
            clear_heap(&h);
        }
    }
    printf("\nOperation: Find min\n"
           "\nInput: Ordered input\n\n");
    for (int i = 1; i <= n; ++i)
    {
        if (print_if(i))
        {
            int c = 0;
            ordered_insert(&h, i, 0);
            find_min(&h, &c);
            printf("%d,%d\n", i, c);
            clear_heap(&h);
        }
    }
    printf("\nInput: Random input\n\n");
    for (int i = 1; i <= n; ++i)
    {
        if (print_if(i))
        {
            int c = 0;
            randomize_insert(&h, i, 0);
            find_min(&h, &c);
            printf("%d,%d\n", i, c);
            clear_heap(&h);
        }
    }
}
