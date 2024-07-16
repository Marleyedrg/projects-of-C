/**
 * FILE: calendar.c
 * AUTHOR: MARLEY
 * DESCRIPTION: A implementatio of a calendar :) in C
 * DATE:12/07/2024
 */

#include <stdio.h>

//Global declaration
void makeSpace();
void makeDays(int total);

//just colors
#define GRN "\e[0;32m"
#define WHT "\e[0;37m"

int main(){

    int year, month;

    printf("%s","YEAR:");
    scanf("%d", &year);

    char *months[] = {"jan", "fev","mar", "apr","may", "jun", "jul", "aug", "sep","oct", "nov", "dec"};

    char monthDay[] = {31, 28, 31,30, 31,30,31,31,30,31,30,31};

    if((year % 4 == 0 && year % 100 != 0)|| year % 400==0){
        monthDay[1] = 29;
    }

    for (int pos = 0; pos < 12; pos++)
    {
        makeSpace();
        printf(GRN"%s",months[pos]);
        makeSpace();
        makeDays(monthDay[pos]);
    }
    



}

void makeSpace(){
    int space = 0;
    while (space < 18)
    {
        printf(GRN"%s","-");
        space++;
    }
}
void makeDays(int total){

    printf(WHT"\n%s\n","   sun  mon  tue  wed  thu  fri  sat");


    for (int i = 1; i <= total; i++)
    {
        printf("   %2.d",i);
        if(i % 7 == 0){
            printf(WHT"\n");
        }
    }
    printf("\n");
}