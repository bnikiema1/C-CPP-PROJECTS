#include "util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

char* subString(const char *str, int start, int length);


void simpleCalc()
{
    int again = 1;

    while(again)
    { 
        float num1; // assuming user isn't trying to break app since there are no try statements
        float num2;
        float result;
        char choice = printMenu();
        printf("Enter a number: ");
        fflush(stdin);

        scanf("%f", &num1);

        printf("Enter second number: ");
        scanf("%f", &num2);

        switch (choice)
        {
        case '+':
            result = num1 + num2;
            printf("\nResult: %.02f", result);
            break;
        case '-':
            result = num1 - num2;
            printf("\nResult: %.02f", result);
            break;
        case '*':
            result = num1 * num2;
            printf("\nResult: %.02f", result);
            break;
        case '/':
            if(num2 == 0){
                printf("\nCan't divide a number by zero!");
                break;
            }else{
                result = num1 / num2;
                printf("\nResult: %.02f", result);
                break;
            }
        
        default:
            printf("%c is not an option", choice);
            break;
        }
        fflush(stdin);
        printf("\nDo you wanna try again? [y/n]");
        char answer = getch();

        if(answer == 'Y' || answer == 'y'){
            continue;
        }else{
            again = 0;
        }
    }
    printf("\nEXITING...");
}

char printMenu()
{
    char choice;
    system("cls");
    printf("\t___Basic Calculator___\n");
    printf("Select: +\n");
    printf("Select: -\n");
    printf("Select: *\n");
    printf("Select: /\n");

    choice = getch();

    return choice;

}

void advancedCalc()
{
    char equation[100];
    char cleanExp[100];
    char operationSign[4] = "-+*/";
    int cleanExpIdx = 0;

    system("cls");
    printf("Enter a expression: ");
    fgets(equation, sizeof(equation), stdin);

    
    for(int i = 0; i<strlen(equation); i++){ // removes whitespace form from the eqauation
        if(equation[i] != ' ' && equation[i] != '\n'){
            cleanExp[cleanExpIdx++] = equation[i];
        }

    }
    cleanExp[cleanExpIdx] = '\0';
    printf("Clean expression: %s\n", cleanExp);


    char allSigns[100] = {0};
    int signsIdx = 0;
    float numbers[100] = {0};
    int numbersIdx = 0;
    int start = 0;

    for(int i = 0; i<strlen(cleanExp); i++){
        char currentChar = cleanExp[i];

        if((currentChar == '+' || currentChar == '-') || (currentChar == '*' || currentChar == '/')){

            if(i > start){
                char *sub = subString(cleanExp, start, i-start);

                if(sub !=NULL){
                    numbers[numbersIdx++] = atof(sub);
                    free(sub);
                }
            }
            allSigns[signsIdx++] = cleanExp[i];
            start = i + 1;
        }
    }
    if(start < strlen(cleanExp)){
        char *sub = subString(cleanExp, start, strlen(cleanExp) - start);
        if(sub != NULL){
            numbers[numbersIdx++] = atof(sub);
            free(sub);
        }
    }
    printf("\n=== RESULTS ===\n");
    printf("Numbers found (%d): ", numbersIdx);
    for(int i = 0; i < numbersIdx; i++){
        printf("%.2f ", numbers[i]);
    }
    printf("\n");

    printf("Operators found (%d): '%s'\n", signsIdx, allSigns);
    float highPrecedence[50] = {};
    float lastNum;
    int highIdx = 0;


}


char* subString(const char *str, int start, int length){
    if(length  <= 0) return NULL;

    char *sub = malloc(length + 1);
    
    if(sub == NULL) {
        return NULL; // Memory allocation failed
    }
    
    // Copy the substring
    strncpy(sub, str + start, length);
    sub[length] = '\0'; // Null terminate
    
    return sub;
}

void removeIndex(float arr[], int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Invalid index!\n");
        return;
    }
    
    // Shift all elements after the index one position left
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Decrease the size
    (*size)--;