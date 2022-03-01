// Name: Foo Bar
// SRN: PES..*
#include "array.h"
#include <stdlib.h>

// Covers a hole in the array at position i
static void cover_hole(Array *a, int i)
{
    for (int j = i; j < a->n - 1; ++j)
        // Shift elements from right to cover the hole
        a->arr[j] = a->arr[j + 1];
}

// Creates a hole in the array at postion i
static void create_hole(Array *a, int i)
{
    for (int j = a->n; j > i; --j) // Assume arr[a->n] can be dereferenced
        // Shift elements to the left to create the hole
        a->arr[j] = a->arr[j - 1];
}

// Initializes the array by setting number of elements to 0
void init_array(Array *arr) 
{ 
    arr->n = 0;
}

// Inserts element key to the array while keeping it sorted
int insert(Array *arr, int key, int *count_ptr)
{
    int i = 0;
    int c = 0;
    // Find position to insert, left most in this case
    // Not the most efficient method!!
    // Think about it!!
    while (i < arr->n && ++c && arr->arr[i] < key)
        ++i;
    create_hole(arr, i);
    // Moving elements is proportional to the length of the array,
    // hence it is counted.
    *count_ptr += (arr->n - i);
    arr->arr[i] = key;
    ++arr->n;
    *count_ptr = c;
    return i;
}

static int binary_search(const Array *arr, int key, int l, int r,
                         int *count_ptr)
{
    if (l > r)
        return -1;
    int m = (l + r) / 2;

    // Search right subarray if middle element is smaller
    if (++*count_ptr && arr->arr[m] < key)
        return binary_search(arr, key, m + 1, r, count_ptr);

    if (++*count_ptr && arr->arr[m] == key &&
        (m == 0 || ++*count_ptr && arr->arr[m - 1] < key))
        return m;

    // Check left subarray if middle element is larger or equal to key
    return binary_search(arr, key, l, m - 1, count_ptr);
}

// Returns the index of the first occurence of key in the array
int search(const Array *arr, int key, int *count_ptr)
{
    int l = 0;
    int r = arr->n - 1;
    return binary_search(arr, key, l, r, count_ptr);
}

// Removes the first occurence of the key in the array
void remove_element(Array *arr, int key, int *count_ptr)
{
    int i = 0;
    // Find index of element
    // Again, not the most efficient implementation
    while (i < arr->n && ++*count_ptr && arr->arr[i] < key)
        ++i;
    if (arr->arr[i] != key)
        return;
    cover_hole(arr, i);
    // For the same reasons mentioned above
    *count_ptr += arr->n - i - 1;
    --arr->n;
}

// Returns the maximum element in the array
int max(const Array *arr, int *count_ptr)
{
    *count_ptr = 0;
    return arr->n ? arr->arr[arr->n - 1] : -1;
}

// Returns the maximum element in the array
int min(const Array *arr, int *count_ptr)
{
    *count_ptr = 0;
    return arr->n ? arr->arr[0] : -1;
}

// Removes the rightmost occurence of the maximum element in the array
int remove_max(Array *arr, int *count_ptr)
{
    *count_ptr = 0;
    return arr->n ? arr->arr[--arr->n] : -1;
}

// Removes the left most occurence of the minimum element in the array
int remove_min(Array *arr, int *count_ptr)
{
    if (!arr->n)
        return -1;
    int min = arr->arr[0];
    cover_hole(arr, 0);
    *count_ptr += arr->n - 1;
    return min;
}

// Clears the array of elements by setting length to 0
void clear_array(Array *arr) 
{ 
    arr->n = 0;
}
