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

#define MAX_NAME_LENGTH 50
#define MAX_ACC_NO 8

char name[MAX_NAME_LENGTH],accNo[MAX_ACC_NO ];

int menu ();
void createAccount(FILE *fptr);
void joinAccount();
void retrieveAccount();
void deleteAccount();

int main()
{
    FILE *fptr = fopen("user_list.txt", "w");
    switch (menu()) {
        case 1:
            createAccount(fptr);
            break;
        case 2:
            joinAccount();
            break;
        case 3:
            retrieveAccount();
            break;
        case 4:
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
    printf("1. Criar conta\n");
    printf("2. Entrar na conta\n");
    printf("3. Recuperar conta\n");
    printf("4. Excluir conta\n");
    printf("5. Sair\n");

    return scanf("%d",&option);
}

void createAccount(FILE *fptr){
    char *newAccName = (char*) malloc((MAX_NAME_LENGTH + 1) * sizeof(char));
    printf("Create a name for your account:");
    scanf("%s", newAccName);

    srand(time(NULL));
    int randomNUM =  rand() % 1000000;
    char newAccNum[MAX_ACC_NO];
    int tempN = 0;
    char temp[3];

    snprintf(newAccNum, sizeof(newAccNum), "%06d", randomNUM);

    for (int i = 0; i < MAX_ACC_NO-2; i++)
    {
        tempN += newAccNum[i] - '0';
    }
    sprintf(temp, "%02d",tempN);

    strcat(newAccNum, temp);

    printf("account name:%s\naccount number:%s\n",newAccName,newAccNum);

    //pass information to the file

    fptr = fopen("user_list.txt", "w");
    fprintf(fptr, "account name:%s\naccount number:%s\n",newAccName,newAccNum);
}
void joinAccount(){}
void retrieveAccount(){}
void deleteAccount(){}