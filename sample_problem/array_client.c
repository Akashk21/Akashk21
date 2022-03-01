#include "array.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Copies a simple integer array to the data structure
void copy_array(Array *dst, const int *src, int n)
{
    dst->n = 0;
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

void randomize_insert(Array *arr, int n, int p)
{
    int c;
    for (int i = 1; i <= n; ++i)
    {
        c = 0;
        insert(arr, rand(), &c);
        if (p && print_if(i))
            printf("%d,%d\n", i, c);
    }
}

void ordered_insert(Array *arr, int n, int p)
{
    int c;
    for (int i = 1; i <= n; ++i)
    {
        c = 0;
        insert(arr, i, &c);
        if (p && print_if(i))
            printf("%d,%d\n", i, c);
    }
}

void reverse_insert(Array *arr, int n, int p)
{
    int c;
    for (int i = 1; i <= n; ++i)
    {
        c = 0;
        insert(arr, arr->n - i, &c);
        if (p && print_if(i))
            printf("%d,%d\n", i, c);
    }
}

int main()
{
    Array a;
    init_array(&a);
    const int n = 1000;
    srand(0);
    int c = 0;

    /*
    **
    ** Test cases to assess correctness of operations on the array
    **
    */

    int insert_arr[] = {1, 2, 5, 6};
    copy_array(&a, insert_arr, 4);

    c = 0;
    assert(insert(&a, 4, &c) == 2 && c == 3);

    c = 0;
    assert(insert(&a, 1, &c) == 0 && c == 1);

    c = 0;
    assert(search(&a, 1, &c) == 0);

    c = 0;
    assert(search(&a, 11, &c) == -1);

    c = 0;
    remove_element(&a, 2, &c);
    assert(search(&a, 2, &c) == -1);

    c = 0;
    remove_element(&a, 11, &c);
    assert(search(&a, 11, &c) == -1);

    c = 0;
    assert(remove_max(&a, &c) == 6);

    c = 0;
    assert(search(&a, 6, &c) == -1);

    c = 0;
    assert(remove_min(&a, &c) == 1);

    c = 0;
    assert(search(&a, 1, &c) == 0);

    clear_array(&a);

    /*
    **
    **
    ** Print the number of comparisons performed by different inputs
    ** for different operations.
    **
    **
    */

    printf("DS: Array\n"
           "Operation: Insert\n"
           "Input: In-order input\n\n");

    ordered_insert(&a, n, 1);
    clear_array(&a);

    printf("\nInput: Random insert\n\n");
    randomize_insert(&a, n, 1);
    clear_array(&a);

    printf("\nInput: Reverse order input\n\n");
    reverse_insert(&a, n, 1);
    clear_array(&a);

    printf("\nOperation: Search\n"
           "Input: Small element\n\n");
    for (int i = 1; i <= n; ++i)
    {
        if (print_if(i))
        {
            randomize_insert(&a, i, 0);
            c = 0;
            search(&a, 2, &c);
            printf("%d,%d\n", i, c);
            clear_array(&a);
        }
    }

    printf("\nInput: Random Search\n\n");
    for (int i = 1; i <= n; ++i)
    {
        if (print_if(i))
        {
            ordered_insert(&a, i, 0);
            c = 0;
            search(&a, rand() % i + 1, &c);
            printf("%d,%d\n", i, c);
            clear_array(&a);
        }
    }

    printf("\nInput: Greater than last element\n\n");
    for (int i = 1; i <= n; ++i)
    {
        if (print_if(i))
        {

            ordered_insert(&a, i, 0);
            c = 0;
            search(&a, i + 1, &c);
            printf("%d,%d\n", i, c);
            clear_array(&a);
        }
    }

    printf("\nOperation: Remove\n"
           "\nInput: First Element\n\n");
    for (int i = 1; i <= n; ++i)
    {
        if (print_if(i))
        {

            ordered_insert(&a, i, 0);
            c = 0;
            remove_element(&a, 1, &c);
            printf("%d,%d\n", i, c);
            clear_array(&a);
        }
    }

    printf("\nInput: Random element\n\n");
    for (int i = 1; i <= n; ++i)
    {
        if (print_if(i))
        {

            ordered_insert(&a, i, 0);
            c = 0;
            remove_element(&a, rand() % i + 1, &c);
            printf("%d,%d\n", i, c);
            clear_array(&a);
        }
    }

    printf("\nInput: Last element\n\n");
    for (int i = 1; i <= n; ++i)
    {
        if (print_if(i))
        {

            ordered_insert(&a, i, 0);
            c = 0;
            remove_element(&a, i, &c);
            printf("%d,%d\n", i, c);
            clear_array(&a);
        }
    }

    printf("\nOperation: Remove Max\n"
           "\nInput: Remove max\n\n");
    for (int i = 1; i <= n; ++i)
    {
        if (print_if(i))
        {
            c = 0;
            randomize_insert(&a, i, 0);
            remove_max(&a, &c);
            printf("%d,%d\n", i, c);
            clear_array(&a);
        }
    }

    printf("\nOperation: Remove Min\n"
           "\nInput: Remove min\n\n");
    for (int i = 1; i <= n; ++i)
    {
        if (print_if(i))
        {
            c = 0;
            randomize_insert(&a, i, 0);
            remove_min(&a, &c);
            printf("%d,%d\n", i, c);
            clear_array(&a);
        }
    }
}
