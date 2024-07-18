/**
 * FILE: bankfunc.c extension of bank.c
 * AUTHOR: MARLEY
 * DESCRIPTION: TRYING HARD MAKE A SIMPLE BANK
 * DATE:17/07/2024  
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> 

#define GRN "\e[0;32m"
#define WHT "\e[0;37m"
#define RED "\e[0;31m"


void startBank(User *user, int option);
void createUserAcc(char *userName,char *userAcc);
void deposit(User *user);
void withdraw();
void transfer();
void accDetails();
void traDetails();


void startBank(User *user, int option)
{
    time_t tm;
    time(&tm);
    printf("%s", ctime(&tm));

    switch (option) {
        case 1:
            deposit(user);
            break;
        case 2:
            withdraw();
            break;
        case 3:
            transfer();
            break;
        case 4:
            accDetails();
            break;
        case 5:
            traDetails();
            break;
        default:
            break;
        }
}

void createUserAcc(char *userName,char *userAcc){
    char *buffer;

    buffer = (char *) malloc(59);

    printf("\n%s",userName);

    sprintf(buffer, "accounts/%s",userName);

    FILE *crAcc = fopen(buffer, "a");

    fprintf(crAcc, "name: %s\naccount number: %s",userName,userAcc);

    char *line = (char *) malloc(250);

    

    free(buffer);
    free(userName);
    free(userAcc);

    fclose(crAcc);
}

inline void deposit(User *user)
{
    createUserAcc(user->name,user->accNo);
}

inline void withdraw()
{
}

inline void transfer()
{
}

inline void accDetails()
{
}

inline void traDetails()
{
}


