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

#define MAX_NAME_LENGTH 50
#define MAX_ACC_NO 6

typedef struct
{
    char *name;
    char *accNo;
}User;


int menu ();
void initializeUser(User *user);
void createAccount(FILE *fptr);
void joinAccount();
void retrieveAccount();
void deleteAccount();

int main()
{
    FILE *fptr = fopen("user_list.txt", "r");
    switch (menu()) {
        case 1:
            createAccount(fptr);
            break;
        case 2:
            joinAccount();
            break;
        case 3:
            deleteAccount();
        break;
        default:
                return 0;
            break;
        }
}


int menu(){
    int option;

    printf("\nMenu:\n");
    printf("1. Create account\n");
    printf("2. Log into account\n");
    printf("4. Delete account\n");
    printf("5. Exit\n");

    return scanf("%d",&option);
}

void createAccount(FILE *fptr){
    User newUser;
    initializeUser(&newUser);

    printf("Create a name for your account:");
    scanf("%s", newUser.name);

    for (int i = 0; newUser.name[i] != '\0'; i++)
    {
        if (newUser.name[i] >= 'a' && newUser.name[i]  <= 'z')
        {
            newUser.name[i] -= 32;
        }
    }
    
    srand(time(NULL));
    int randomNUM = (rand() % 9000) + 1000;
    char newAccNum[MAX_ACC_NO];
    int tempN = 0;
    char temp[3];

    snprintf(newAccNum, sizeof(newAccNum), "%04d", randomNUM);

    for (int i = 0; i < MAX_ACC_NO-2; i++)
    {
        tempN += newAccNum[i] - '0';
    }
    sprintf(temp, "%02d",tempN);

    strcat(newAccNum, temp);

    printf("account name:%s\naccount number:%s\n",newUser.name,newAccNum);

    //pass information to the file

    fptr = fopen("user_list.txt", "a");
    fprintf(fptr, "%sZ%s\n",newUser.name,newAccNum);
}
void joinAccount(){
    User currentUser;
    initializeUser(&currentUser);

    printf("Account name:");
    scanf("%s", currentUser.name);

    printf("Account number:");
    scanf("%s", currentUser.name);
}
void deleteAccount(){}

void initializeUser(User *user) {
    // Allocate memory for name and account number
    user->name = (char *)malloc((MAX_NAME_LENGTH + 1) * sizeof(char));
    user->accNo = (char *)malloc((MAX_ACC_NO + 1) * sizeof(char));
}
