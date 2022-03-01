#ifndef ARRAY_H_
#define ARRAY_H_

#define MAX 10000

struct array
{
    int arr[MAX];
    int n;
};

typedef struct array Array;

// Initialize Array
void init_array(Array *arr);

// Insert key to Array arr and keeps the array sorted
// Stores the number of key comparisons in *count_ptr
int insert(Array *arr, int key, int *count_ptr);

// Returns the index of the element key if it is present in array arr
// Returns -1 if the element is not found
int search(const Array *arr, int key, int *count_ptr);

// Removes the element key from the array
void remove_element(Array *arr, int key, int *count_ptr);

// Returns the maximum element from the array
int max(const Array *arr, int *count_ptr);

// Returns the minimum element from the array
int min(const Array *arr, int *count_ptr);

// Removes and returns the maximum element in the array
int remove_max(Array *arr, int *count_ptr);

// Removes and returns the minimum element in the array
int remove_min(Array *arr, int *count_ptr);

// Clears the array of all elements
void clear_array(Array *arr);

#endif // ARRAY_H_
