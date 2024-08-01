/**
 * FILE: txt.h
 * AUTHOR: MARLEY
 * DESCRIPTION: better way to work with txt files in C
 * DATE:29/07/2024  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void tx_add(FILE *file,char *name, char *value);
void tx_delALL(FILE *file);

char* tx_get(FILE *file,char *name);
void tx_set(char *fileName,char *name, char *newValue);

int tx_rm(FILE *file,char *name);

#define MAX_LINELEN 100


void tx_add(FILE *file,char *name, char *value){
    if(strcmp(tx_get(file, name), "1")){
        printf("ALREADY EXIST");
    }else{
        char *string;
        string = (char*) malloc(MAX_LINELEN);

        sprintf(string, "|%s:%s",name,value);

        fprintf(file,"%s\n",string);

        free(string);
    }
}

void tx_delALL(FILE *file){
    file = fopen("test.txt", "w");
}

char* tx_get(FILE *file,char *name){

    char *str = (char*) malloc(sizeof(name)+2);

    sprintf(str, "|%s:", name);

    file = fopen("test.txt", "r");

    char line[MAX_LINELEN];

    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, str))
        {
            strcpy(str,strchr(line, ':')+1); 

            return str;
        }
    }
    return "1";
    free(str);
}

void tx_set(char *fileName,char *name, char *newValue){
    char *compName;
    compName = (char*) malloc(MAX_LINELEN);

    char line[MAX_LINELEN];

    sprintf(compName, "|%s", name);

    FILE *temp;

    FILE *oldFile;

    temp = fopen("temp.txt", "w");

    oldFile = fopen(fileName, "r");

    while (fgets(line, sizeof(line), oldFile))
    {
        if(strstr(line, compName)){

            fprintf(temp,"%s:%s\n", compName, newValue);

            continue;
        }
        fprintf(temp,"%s", line);
    }

    remove(fileName);

    rename("temp.txt", fileName);

}

int tx_rm(FILE *file, char *name){

}
