# CMPE 252 C Programming

## Homework 2

### Q1

**atof** is a function in the **C** programming language that converts a string into a floating-point numerical representation. **atof** stands for ASCII to float.

In this part of the assignment, you are going to implement <ins>your own</ins> **atof** function

<br>

> _**float myAtof(char\* string, char\* error)**_

<br>

that will convert an input read as a character array into a floating-point number. Here are the specifications:

- You should just fill in the missing function definition in the skeleton code for Q1 (homework2q1.c). The remaining part of the code (such as the main function) will stay as it is.

- Your **atof** function will get two inputs. One for the character array to convert and the other to check for the error. The output of the function will be a floating-point number.

- If the character array cannot be converted (it includes letters, special characters, etc.) the **error** will be 1, otherwise 0.

- If the numbers cannot be converted (**error = 1**), give an error message to the user as “Error has been occurred due to inappropriate input!”

<br>

**Sample input/output:**

```
Enter a number:

> 6

Your number is: 6.00
```

### Q2

In this part of the assignment, you will use your own **atof** function that you implement in the Q1 to extend arithmetic operations evaluation `(+,-,*, /)` to operate on floating-point numbers.

You will get a character array from the user with operation and print the result. Here are the specifications:

- You will use **gets()** function to get the character array with operation from the user. The maximum array size is 250.

- Notice that end of input is indicated by null character **'\0'**

- Numbers should be printed with <ins>two-digit</ins> precision after decimal point.

- If the user enters an invalid operation, give an error to the user as “Error has been occurred due to inappropriate input!”

- If the user enters an invalid operator, give an error to the user as “Invalid operator type!”

- If the user enters for a division by 0 operations, give an error to the user as “Cannot divided into 0.”

<br>

**Sample input/output:**

```
Enter arithmetic operation:

> 3.7/3

3.70 / 3.00 = 1.23
```
