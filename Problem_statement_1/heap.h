#ifndef HEAP_H_
#define HEAP_H_

struct heap
{
    int *arr;
    int size;
    int max_size;
};

typedef struct heap heap_t;

// Initialise heap
// Set heap size to 0
// Set heap max_size to paramter max_size
// Allocate memory of max_size to the array
void init_heap(heap_t *heap, int max_size);

// Insert element "key" to heap "heap"
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
void insert(heap_t *heap, int key, int *count_ptr);

// *Removes and Returns* the maximum element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int extract_max(heap_t *heap, int *count_ptr);

// Searches for the element key in the heap
// Returns the element if found, else -1
int search(const heap_t *heap, int key, int *count_ptr);

// Returns the maximum value of the element in the heap
// and store the number of key comparisons made in the
// location pointed to by count_ptr.
int find_max(const heap_t *heap, int *count_ptr);

// Returns the minimum value in the heap
int find_min(const heap_t *heap, int *count_ptr);

// Clears the heap for reuse
void clear_heap(heap_t *heap);

// Frees all resources acquired to initialize heap
void free_heap(heap_t *heap);

#endif // HEAP_H_
