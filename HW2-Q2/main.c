#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 250
float myAtof(char *string, char *error);
void operate(char* string, char* errorState);
int main()
{
    char mystring[SIZE];            // Array declaration.
    float fnum1;
    char errorState=0;
    //char errorState;

    printf(">Enter arithmetic operation:\n");
    scanf("%s", mystring);
    //gets(mystring);

    operate(mystring, &errorState);

    if (errorState==1){
        printf("Error has been occurred due to inappropriate input!\n");
    }else if (errorState==2){
        printf("Invalid operator type!\n");
    }
    else if (errorState==3){
        printf("Cannot divided into 0.\n");
    }

    return 0;
}

float myAtof(char* string, char* error){          // Function to convert string into float.
    float num = 0;
    int digits = 10;
    int point = 0;
    int count = 0;
    char minusSign;
    int countMinus = 0;
    int whichDigit = 0;
    int numIrrelevant = 0;
    int size = sizeof(string);

    int sizeWithoutSpace = 0;
    for (int i = 0; i < sizeof(string); i++) {
        if (string[i] == ' ') continue;
        else if (string[i] == '\0') break;
        else if (string[i] < 48 || string[i] > 57) {
                if (string[i] != 46) {
                    continue;
                } else sizeWithoutSpace++;
        }
        else sizeWithoutSpace++;
    }


    for (int i = 0; i < size; i++) {
        if (string[i] == 45 && countMinus == 0) {
            minusSign = string[i];
            countMinus = 1;
            continue;
        }
        if (string[i] == ' ') continue;
        if (string[i] == '\0') break;

        if (string[i] < 48 || string[i] > 57) {
                if (string[i] != 46) {
                        if (countMinus == 0) {
                            *error = 1;
                            numIrrelevant++;
                        }

                }
        }
        if (*error == 1) break;

        if (string[i] == 46) {
            point = 1;
            whichDigit = count;
        } else {
            if (sizeWithoutSpace == 1){
                num = (float)(string[i] - 48);
                }
            else {
                num = num + (float)(string[i] - 48) * pow(digits,sizeWithoutSpace-2-count);
                count++;
            }

        }

    }

    // to find the place of point (.)
    if (point == 1)
        num = num / pow(digits, count - whichDigit);
    else if (sizeWithoutSpace != 1) num = num * 10;

    if (minusSign == 45) num = (-1.0) * num;


    if (numIrrelevant == 0 || numIrrelevant == 1) {*error = 0;}
    else if (numIrrelevant > 1) {*error = 1;}

    //printf("irrelevant: %d\n", numIrrelevant);
    return num;
}


void operate(char* string, char* errorState) {

    int size = sizeof(string);
    char temp1[size];
    char temp2[size];
    int indexTemp1 = 0;
    int indexTemp2 = 0;
    int leftOfOperator = 0;
    char operatorr;
    float num1;
    float num2;
    int skip = 0;
    int space = 0;
    int numIrr = 0;
    for (int i = 0; i < size; i++) {
        if (string[i] == ' ') {
            space = 1;
            *errorState = 1;
            break;
        }
        if (leftOfOperator == 0) {
        if (string[i] != '+' && string[i] != '-' && string[i] != '*' && string[i] != '/') {
            temp1[indexTemp1] = string[i];
            indexTemp1++;
            } else {
                operatorr = string[i];
                num1 = myAtof(temp1, errorState);
                leftOfOperator = 1;
                skip = 1;
            }
        }


        if (skip == 1) {
            skip = 2;
            continue;
        }

        if (leftOfOperator == 1) {
            if (string[i] < 48 || string[i] > 57) {
                    if (string[i] != 46) {
                            numIrr++;
                    }
                }
            if(string[i] != '\0') {
                temp2[indexTemp2] = string[i];
                indexTemp2++;
            }
        }
        if (string[i] == '\0') break;
    }

    if (space == 1) {
        *errorState = 1;
        return;
    }

    // printf("irrelvant2: %d\n", numIrr);
    if (numIrr != 1) {
        *errorState = 1;
        return;
    } else {
        *errorState = 0;
    }
    num2 = myAtof(temp2, errorState);


    float result = 0;
    if (operatorr == '+') {
        result = num1 + num2;
    }
    else if (operatorr == '-') {
        result = num1 - num2;
    }
    else if (operatorr == '*') {
        result = num1 * num2;
    }
    else if (operatorr == '/') {
            if(num2 == 0) {
                *errorState = 3;
                return;
            } else {
                result = num1 / num2;
            }
    }

    printf("%.2f %c %.2f = %.2f", num1, operatorr, num2, result);

}
