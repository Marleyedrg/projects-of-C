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

#define MAX_LINE_LENGTH 100

void startBank(User *user, int option);
char* getUserAcc(char *userName,char *userAcc);
char* extractAttributeValue(char *buffer,char *attribute);
void deposit(User *user);
void withdraw(User *user);
void transfer();
void accDetails(User *user);
void addTraDetails(char*time,char *userName,char *userAcc, char *type, double value);
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
            withdraw(user);
            break;
        case 3:
            transfer();
            break;
        case 4:
            accDetails(user);
            break;
        case 5:
            traDetails();
            break;
        default:
            break;
        }
}

char* getUserAcc(char *userName,char *userAcc){

    time_t tm;
    time(&tm);

    char *buffer;

    buffer = (char *) malloc(59);

    sprintf(buffer, "accounts/%s%s",userName,userAcc);

    FILE *crAcc = fopen(buffer, "a");

    fseek(crAcc, 0, SEEK_END);

    long fileSize = ftell(crAcc);

    if (fileSize == 0)
    {
        fprintf(crAcc, "account created in: %sname: %s\naccount number: %s\nbalance: R$0.00",ctime(&tm),userName,userAcc);
    }
    fclose(crAcc);
    return buffer;
}

char* extractAttributeValue(char *buffer, char *attribute){
    char *value;
    value = (char *) malloc(MAX_LINE_LENGTH-10);
    char line[MAX_LINE_LENGTH];
    char *token;

    FILE *file = fopen(buffer, "r");
    FILE *tempFile = fopen("accounts/temp", "w");

    while (fgets(line, sizeof(line), file) != NULL) {
        
        if (strstr(line, attribute) == line) {
            
            token = strtok(line, "$");  
            if (token != NULL) {
                token = strtok(NULL, "$"); 

                if (token != NULL) {
                    strcpy(value, token);
                    break;
                }
            }
        }
        fputs(line, tempFile);
    }
    fclose(file);
    fclose(tempFile);

    remove(buffer);

    rename("accounts/temp", buffer);

    return value;
}
inline void deposit(User *user)
{
    time_t tm;
    time(&tm);

    double deposit;
    char *strAccValue;
    double oldValue;
    strAccValue = (char *) malloc(MAX_LINE_LENGTH-10);

    char *cpBuffer = getUserAcc(user->name,user->accNo);

    printf("\nAmount to deposit: ");
    (scanf("%le",&deposit));

    strAccValue = extractAttributeValue(cpBuffer, "balance:");

    oldValue = strtod(strAccValue, NULL);

    FILE *crAcc = fopen(cpBuffer, "a");

    fprintf(crAcc,"balance: R$%.2f\n",(oldValue+deposit));

    addTraDetails(ctime(&tm),user->name,user->accNo,"DEPOSIT",deposit);
}

inline void withdraw(User *user){
    time_t tm;
    time(&tm);

    double withdraw;
    char *strAccValue;
    double oldValue;
    strAccValue = (char *) malloc(MAX_LINE_LENGTH-10);

    char *cpBuffer = getUserAcc(user->name,user->accNo);

    printf("\nAmount to withdraw: ");
    (scanf("%le",&withdraw));

    strAccValue = extractAttributeValue(cpBuffer, "balance:");

    oldValue = strtod(strAccValue, NULL);

    FILE *crAcc = fopen(cpBuffer, "a");

    if ((oldValue - withdraw) < 0)
    {
        printf(RED"\ninsufficient funds!\n"WHT);
        fprintf(crAcc,"balance: R$%.2f\n",(oldValue));
    }else{
    fprintf(crAcc,"balance: R$%.2f\n",(oldValue-withdraw));
    }

    addTraDetails(ctime(&tm),user->name,user->accNo,"WITHDRAW",withdraw);
}

inline void transfer()
{
}

inline void accDetails(User *user)
{
    char *cpBuffer = getUserAcc(user->name,user->accNo);

    FILE *file;
    char line[MAX_LINE_LENGTH];

    file = fopen(cpBuffer, "r");
    
    printf("%s\n", "-----------------");

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    printf("%s", "-----------------");

    fclose(file);
}

inline void traDetails()
{
    FILE *file;
    char line[MAX_LINE_LENGTH];


    file = fopen("traDetails", "r");

    printf("\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

void addTraDetails(char*time,char *userName,char *userAcc, char *type, double value){
    FILE *file;

    file = fopen("traDetails", "a");

    fprintf(file, "date of transaction: %s%s\nname: %s\naccount number: %s\nvalue: %.2f\n",time,type,userName,userAcc,value);
    fprintf(file,"----\n");
}
// void addTranferDetails(char*time,char *userName,char *userAcc, char *type, double value){
//     FILE *file;

//     file = fopen("traDetails", "a");

//     fprintf(crAcc, "date of transaction: %sname: %s\naccount number: %s\n%s\nvalue: %ld\n",timeTra,userName,userAcc,type,value);
//     printf("%s\n", "-----------------");
// }


