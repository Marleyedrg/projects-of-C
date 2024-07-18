/**
 * FILE: bank.c
 * AUTHOR: MARLEY
 * DESCRIPTION: TRYING HARD MAKE A SIMPLE BANK
 * DATE:15/07/2024  
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> 

#include "structTypes.h"

#include "authentication.h"
#include "bankFunc.h"

#define GRN "\e[0;32m"
#define WHT "\e[0;37m"
#define RED "\e[0;31m"

int menu (int type);

int main()
{
    User user;
    initializeUser(&user);
    switch (menu(1)) {
        case 1:
            createAccount();
            menu(1);
            break;
        case 2:
            if(joinAccount(&user) == 1){
                free(user.name);
                free(user.accNo);
                main();
            }else{
                startBank(&user,menu(2));
            }
            break;
        default:
                return 0;
            break;
        }
}


int menu(int type){
    int option;

    if(type == 1){
    printf("\nMenu:\n");
    printf("1. Create account\n");
    printf("2. Log into account\n");
    printf("3. Exit\n");
    (scanf("%d",&option));

    return option;
    }
    printf("\nMenu:\n");
    printf("1. DEPOSIT MONEY\n");
    printf("2. WITHDRAW MONEY\n");
    printf("3. TRANSFER MONEY\n");
    printf("4. ACCOUNT DETAILS\n");
    printf("5. TRANSACTIONS DETAILS\n");
    printf("6. Exit\n");
    (scanf("%d",&option));

    return option;
}