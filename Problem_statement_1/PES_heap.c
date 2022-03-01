// Name:
// SRN:
#include "heap.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header
 *as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// Initialise heap
// Set heap size to 0
// Set heap max_size to paramter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size)
{
    heap->size = 0;
    heap->max_size = max_size;
    heap->arr = (int *)malloc(max_size * sizeof(int));
}

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr)
{
    int i = heap->size-1;
    heap->arr[i] = key;
    heap->size++;
    while (i != 0)
    {   ++(*count_ptr);
        int p = (i - 1) / 2;
        if (heap->arr[p] < heap->arr[i])
        {   ++(*count_ptr);
            int temp = heap->arr[p];
            heap->arr[p] = heap->arr[i];
            heap->arr[i] = temp;
            i = p;
        }
        else
        {
            return ;
        }
    }
    ++*(count_ptr);
}

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr)
{
    int max = heap->arr[0];
    int i = 0;
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    while (i< heap->size)
    {   ++(*count_ptr);
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int max_index = i;
        if (l < heap->size && heap->arr[l] > heap->arr[i])
        {
            ++(*count_ptr);
            max_index = l;
        }
        if (r < heap->size && heap->arr[r] > heap->arr[max_index])
        {
            ++(*count_ptr);
            max_index = r;
        }
        if (max_index != i)
        {
            ++(*count_ptr);
            int temp = heap->arr[i];
            heap->arr[i] = heap->arr[max_index];
            heap->arr[max_index] = temp;
            i = max_index;
        }
        else
        {
            return max;
        }
    }
    ++(*count_ptr);
    return max;
}

// Searches for the element key in the heap
// Returns the element if found, else -1
int search(const heap_t *heap, int key, int *count_ptr)
{
    int i = 0;
    while (i < heap->size)
    {   ++(*count_ptr);
        if (heap->arr[i] == key)
        {   ++(*count_ptr);
            return key;
        }
        i++;
    }
    ++(*count_ptr);
    return -1;
}

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr)
{
    ++(*count_ptr);
    return heap->arr[0];
}

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr){
    ++(*count_ptr);
    return heap->arr[heap->size - 1];
}

// Clears the heap for reuse
void clear_heap(heap_t *heap) {
    heap->size = 0;
}

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap) {
    free(heap->arr);
    heap->arr = NULL;
    heap->size = 0;
}
