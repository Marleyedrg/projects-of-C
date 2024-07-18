/**
 * FILE: structTypes.h extension of bank.c
 * AUTHOR: MARLEY
 * DESCRIPTION: TRYING HARD MAKE A SIMPLE BANK
 * DATE:17/07/2024  
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> 

#define MAX_NAME_LENGTH 50
#define MAX_ACC_NO 6

typedef struct
{
    char *name;
    char *accNo;
}User;

typedef struct
{
    char *traTime;
    char *type;
    double value;
    
    User fromUser;
    User toUSER;
}Tra;

void initializeUser(User *user);
void initializeTransaction(Tra *tra);

void initializeUser(User *user) {
    // Allocate memory for name and account number
    user->name = (char *)malloc((MAX_NAME_LENGTH + 1) * sizeof(char));
    user->accNo = (char *)malloc((MAX_ACC_NO + 1) * sizeof(char));
}

void initializeTransaction(Tra *tra) {
    tra->traTime = (char *)malloc(25*sizeof(char));
    tra->type = (char *)malloc(18+1*sizeof(char));
}
