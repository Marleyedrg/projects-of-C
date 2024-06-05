#include <stdio.h>

int slice(char string[], int size,int start, int end);

int main(){
    char string[] = "Hello World";

    int size = sizeof(string)/(sizeof(char))-2;
    
    slice(string, size, 5, 112);
}

int slice(char string[], int size,int start, int end){
    
    if(start > 0 && start > end || (end > size || end < start)){
        printf("The start needs to be lower than the end|The end needs to be bigger than the end!\n");
        return -1;
    }
    
    char newStr[end - start + 2];
    
    for (int pX = start,pY = 0 ; pX <= end; pX++, pY++){
        newStr[pY] = string[pX];
    }
    newStr[end - start+1] = '\0';
    printf("%s\n",newStr);

}

