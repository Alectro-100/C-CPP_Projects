#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double Addition(double* a, double* b) {
    // Basic addition
    return ((*a)+(*b)) ;
}

double subtraction( double* a, double* b ) {
    // Basic subraction
    return ((*a)-(*b));
}

double multiplication(double* a, double* b) {
    // Basic multiplication
    return ((*a)*(*b));
}

double division(double* a, double* b) {
    // Basic division
    if (*b != 0) {
        return ((*a)/(*b));
    }
    else {
        // If denominator is zero
        printf("\nCannot be divisible by zero\n");
        return NAN;
    }
}

typedef struct {
    // New type for two numbers
    double n1;
    double n2;
} TwoNums ;

TwoNums get_numbers() {
    // Ask use to for inputs
    TwoNums nums;
    printf("Enter first number: ");
    scanf("%lf", &nums.n1);
    printf("Enter second number: ");
    scanf("%lf", &nums.n2);
    return nums;
}

int main() {
    // Main body of code

    // Variables and pointers
    double* Ptr_num1;
    double* Ptr_num2;
    short int choice=0;
    TwoNums numbers;

    // Some rgb colors
    char red[] = "\033[38;2;255;0;0m";
    char green[] = "\033[38;2;0;255;0m";
    char blue[] = "\033[38;2;0;0;255m";
    char orange[] = "\033[38;2;252;206;56m";
    char sky[] = "\033[38;2;0;240;200m";
    char no_col[] = "\033[0m";

    // First message to terminal
    printf("Choose one of the following:\n");
    printf("0. Clear the screen\n");
    printf("5. Exit the calculator\n\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    while (1) {
        // Asking for user input
        printf("Enter from (0, 5) and (1, 2, 3, 4): ");
        scanf("%d", &choice);

        if (choice == 0) {
            #ifdef _WIN32
                system("cls");
            #elif defined(__linux__)
                system("clear");
            #else
                printf("System Unknown\n")
            #endif
            continue;

        } else if (choice == 1) {
            numbers = get_numbers();
            printf( "\n%sAddition%s = %s%.2lf%s\n\n", red, no_col, blue,  Addition( &numbers.n1,  &numbers.n2), no_col );

        } else if (choice == 2) {
            numbers = get_numbers();
            printf( "\n%sSubtraction%s = %s%.2lf%s\n\n", green, no_col, blue, subtraction(&numbers.n1, &numbers.n2), no_col );

        } else if (choice == 3) {
            numbers = get_numbers();
            printf( "\n%sMultiplication%s = %s%.2lf%s\n\n", orange, no_col, blue, multiplication(&numbers.n1, &numbers.n2), no_col );

        } else if (choice == 4) {
            numbers = get_numbers();

            printf( "\n%sDivision%s = %s%.2lf%s\n\n", sky, no_col, blue, division(&numbers.n1, &numbers.n2), no_col );
        }

        else if (choice == 5) {
            break;
        }

        else {
            printf( "Number out of range (0, 1, 2, 3, 4, 5)\n\n" );
        }
    }
    return 0;
}
