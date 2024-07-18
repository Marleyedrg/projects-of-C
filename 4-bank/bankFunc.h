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

void startBank(User *user);

void startBank(User *user)
{
    time_t tm;
    time(&tm);
    printf("%s", ctime(&tm));

    // switch (menu(1)) {
    //     case 1:
    //         break;
    //     case 2:
    //         }else{
    //         }
    //         break;
    //     default:
    //             return 0;
    //         break;
    //     }
}

