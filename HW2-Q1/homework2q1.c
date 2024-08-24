#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 250
float myAtof(char *string, char *error);

int main()
{
    char string[SIZE];            // Array declaration.
    float fnum1;
    char errorState=0;

    printf("Enter a number:\n");
    gets(string);

    fnum1=myAtof(string,&errorState);

    if (errorState==0){
        printf("Your number is: %.2f \n", fnum1);
    }else if (errorState==1){
        printf("Error has been occurred due to inappropriate input!\n");
    }

    return 0;
}

float myAtof(char* string, char* error){          // Function to convert string into float.
    float num = 0;
    int digits = 10;
    int point = 0;
    int count = 0;

    int whichDigit = 0;

    int size = sizeof(string);

    int sizeWithoutSpace = 0;
    for (int i = 0; i < sizeof(string); i++) {
        if (string[i] == ' ') continue;
        else if (string[i] == '\0') break;
        else sizeWithoutSpace++;
    }

    for (int i = 0; i < size; i++) {
        if (string[i] == ' ') continue;
        if (string[i] == '\0') break;

        if (string[i] < 48 || string[i] > 57) {
                if (string[i] != 46) {
                    *error = 1;
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

    return num;
}
