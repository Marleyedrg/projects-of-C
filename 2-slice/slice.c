/**
 * FILE: slice.c
 * AUTHOR: MARLEY
 * DESCRIPTION: A implementatio of slice function in C
 * DATE:10/07/2024
 */

#include <stdio.h>
#include <stdlib.h>

//Global declaration
char* slice(char* string, int start, int end);

int main(){

    char string[] = "Marley";
    int start = 3;
    int end = 1;

    printf("-> %s\n",slice(string,start,end));
    
}

char* slice(char* string, int start, int end){

    int oldString_size = sizeof(char) * sizeof(string)-3;

    if(end > oldString_size){
        printf("%s","the end is higher than the size [end = string size]\n");
        end = oldString_size;
    }
    if(start > oldString_size){
        printf("%s","the start is higher than the size [start = string size]\n");
        start = oldString_size;
    }

    if(end < 0 || start < 0){
        end = oldString_size+1;
        printf("%s\n","end cannot be less than zero");
    }
    if(start < 0){
        start = 0;
        printf("%s\n","start cannot be less than zero");
    }

    if (end < start || (start > end))
    {
        printf("start:%d end:%d\n",start,end);
        int temp = 0;

        temp = start;
        start = end;
        end = temp;
        printf("%s\n","swapped: (end < start) or (start > end)");
        printf("start:%d end:%d\n",start,end);
    }
    

    int size = (end - start) + 1;

    char *output = (char *)malloc(size+1);

    int new = 0,old = start;
    do
    {
        output[new] = string[old];
        //Assign each position between the start and end in the new string corresponding.

        new++, old++;
    } while (new < size-1);
    //Why use do-while?
    //
    
    output[size] = '\0';

    return output;

}


