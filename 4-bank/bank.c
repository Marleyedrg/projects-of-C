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

#define GRN "\e[0;32m"
#define WHT "\e[0;37m"
#define RED "\e[0;31m"

typedef struct
{
    char *name;
    char *accNo;
}User;


int menu ();
void initializeUser(User *user);
void createAccount();
int joinAccount(User *possibleUser);
int isValidAccNo(char *accNo);
void startBank(User *user);
void deleteAccount();       

int main()
{
    User user;
    initializeUser(&user);
    switch (menu()) {
        case 1:
            createAccount();
            break;
        case 2:
            if(joinAccount(&user) == 1){
                free(user.name);
                free(user.accNo);
                main();
            }else{
                startBank(&user);
            }
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

    (scanf("%d",&option));

    return option;
}

void createAccount(){
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

    FILE *fptr = fopen("user_list.txt", "a");
    fprintf(fptr, "%s@%s\n",newUser.name,newAccNum);
    fclose(fptr);

    free(newUser.name);
    free(newUser.accNo);

    printf(GRN"\n%s\n","account created!!!"WHT);
    main();
}
int joinAccount(User *possibleUser){

    printf("Account name:");
    scanf("%s", possibleUser->name);

    for (int i = 0; possibleUser->name[i] != '\0'; i++)
    {
        if (possibleUser->name[i] >= 'a' && possibleUser->name[i]  <= 'z')
        {
            possibleUser->name[i] -= 32;
        }
    }

    printf("Account number:");
    scanf("%s", possibleUser->accNo);

    if(isValidAccNo(possibleUser->accNo) == 1){
        return 1;
    }

    char *auth = (char *) malloc((strlen(possibleUser->name) + strlen(possibleUser->accNo) + 2) * sizeof(char));

    sprintf(auth,"%s@%s", possibleUser->name, possibleUser->accNo);
    snprintf(auth, sizeof(auth), "%s@%s", possibleUser->name, possibleUser->accNo);

    FILE *fptr = fopen("user_list.txt", "r");

    char *line = (char *) malloc((strlen(possibleUser->name) + strlen(possibleUser->accNo) + 2) * sizeof(char));

    while(fgets(line,sizeof(line), fptr)){
        if(strstr(line, auth) != NULL){
            printf(GRN"\nlogin successful!\n"WHT);
            return 0;
        }
    }
    if(feof(fptr)){
        printf(RED"\nfail to login!\n"WHT);
        return 1;
    }

    fclose(fptr);
}
void deleteAccount(){}

int isValidAccNo(char *accNo){
    int sum = 0;
    int endOfAccNo = 0;

    int AccNolen = sizeof(accNo); 

    if (AccNolen != MAX_ACC_NO + 2)
    {
        printf(RED"\nfail to login!\n"WHT);
        return 1;
    }
    

    for (int i = 0, j = 4; i < 4; i++,j++)
    {
        char a[3];
        a[i] = accNo[j];

        sum += accNo[i] - '0';

        if(j == 5){
            endOfAccNo += atoi(a);
        }
    }

    if(sum == endOfAccNo){
        return 0;
    }
    
    printf(RED"\nfail to login!\n"WHT);
    return 1;
}

void startBank(User *user)
{
}

void initializeUser(User *user) {
    // Allocate memory for name and account number
    user->name = (char *)malloc((MAX_NAME_LENGTH + 1) * sizeof(char));
    user->accNo = (char *)malloc((MAX_ACC_NO + 1) * sizeof(char));
}