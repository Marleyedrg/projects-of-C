/**
 * FILE: record.c
 * AUTHOR: MARLEY
 * DESCRIPTION: Student record management system 
 * DATE:29/07/2024  
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "easy_txt/txt.h"

int main(void)
{
    FILE *a;

    a = fopen("test.txt", "a");

    tx_set("test.txt","ola","123");
    
}
