/**
 * FILE: calculator.c
 * AUTHOR: MARLEY
 * DESCRIPTION: A simple terminal calculator
 * DATE:30/05/2024
 */

#include <stdio.h>

//Global declaration
double calc(double x, double y, char oper);
char isValidOperator(char oper);

int main(){
    double first = 0;
    double second = 0;
    char operator;

    printf("Operator(+, -, *, /): ");
    scanf("\n%c", &operator);

    if (isValidOperator(operator) == 0)
    {
        return 1;
    }else{
        printf("values [first second]: ");
        scanf("\n%lf%lf",&first,&second);

        double result = calc(first,second,operator);

        printf("%.2lf %C %.2lf= %.2lf\n",first,second,operator,result);

        return 0;
    }
}

double calc(double x, double y, char oper){
    switch (oper)
    {
    case '+':
        return x + y;
    case '-':
        return x + y;
    case '*':
        return x + y;
    case '/':
        if (y == 0)
        {
            printf("EROR!!! CANT DIVIDE BY ZERO");
            return 0;
        }else{
            return x / y;
        }

    default:
        printf("EROR!!! invalid operator");
        return 0;
    }
}

char isValidOperator(char oper) {
    switch (oper)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 1;
        break;
    case '/':
        return 1;
        break;
    default:
        printf("EROR!!! invalid operator\n");
        return 0;
    }
}