/**
 * FILE: slice.c
 * AUTHOR: MARLEY
 * DESCRIPTION: An implementation of the slice function in C
 * DATE: 10/07/2024 
 * USE:
 * slice(string, start, end)
 * start: The position where your slice starts, starting with 0
 * end: The position where your slice ends; the character at this position is not included in the string.
 */

#include <stdio.h>
#include <stdlib.h>

// Global declaration
char* slice(char* string, int start, int end);

int main() {
    char string1[] = "Marley";  
    printf("Array: -> %s\n", slice(string1, 4, 1));  

    char* string2 = "Marley";  
    printf("Pointer: -> %s\n", slice(string2, 1, 4));  

    return 0;  
}

char* slice(char* string, int start, int end) {
    int oldString_size = 0;  // Variable to count the size of the string
    while (string[oldString_size] != '\0') {  
        oldString_size++;  
    }

    // Check and adjust start and end indices
    if (start < 0) {  // If the start index is less than 0, set it to 0
        start = 0;
        printf("start cannot be less than zero. Set to 0.\n");  
    }
    if (end > oldString_size) {  // If the end index is greater than the string size, set it to the string size
        end = oldString_size;
        printf("end cannot be greater than string size. Set to %d.\n", end);  
    }
    if (end < start) {  // If the end index is less than the start index, swap the values
        int temp = start;  // Use a temporary variable to swap
        start = end;
        end = temp;
        printf("Swapped start and end: start=%d, end=%d\n", start, end);
    }

    int size = end - start;  // The size of the new string will be the difference between end and start

    // Allocate memory for the new string (+1 for the null terminator)
    char* output = (char*)malloc(size + 1); 

    if (output == NULL) {  // If memory allocation fails
        printf("Memory allocation failed!\n");  
        return NULL;  
    }

    for (int i = 0; i < size; i++) {  // Iterate over the range [start, end) -> (size = end - start)
        output[i] = string[start + i]; // The first position (start) of the slice and increment until the end is reached.
    }

    output[size] = '\0';  // Add the null terminator '\0' at the end of the new string

    return output;
}