#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>


double Addition(double& a, double& b) {
    // Basic addition
    return (a+b) ;
}

double subtraction( double& a, double& b ) {
    // Basic subraction
    return (a-b);
}

double multiplication(double& a, double& b) {
    // Basic multiplication
    return (a*b);
}

double division(double& a, double& b) {
    // Basic division
    if (b != 0) {
        return (a/b);
    }
    else {
        // If denominator is zero
        printf("\nCannot be divisible by zero\n");
        return NAN;
    }
}

struct TwoNumbers {
    double n1;
    double n2;
};

TwoNumbers get_numbers() {
    // Get user input
    TwoNumbers nums;
    std::cout << "Enter first number: ";
    std::cin >> nums.n1;
    std::cout << "Enter second number: ";
    std::cin >> nums.n2;
    return nums;
}

int main() {
    // Variables
    TwoNumbers nums_;
    int num1 {};
    int num2 {};
    short int choice {};
    
    // Some colors
    std::string red = "\033[38;2;255;0;0m";
    std::string green = "\033[38;2;0;255;0m";
    std::string blue = "\033[38;2;0;0;255m";
    std::string orange = "\033[38;2;252;206;56m";
    std::string sky = "\033[38;2;0;240;200m";
    std::string no_col = "\033[0m";

    // First message to terminal
    std::cout << "Choose one of the following:" << std::endl;
    std::cout << "0. Clear the screen" << std::endl;
    std::cout << "5. Exit the calculator\n" << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Subtraction" << std::endl;
    std::cout << "3. Multiplication" << std::endl;
    std::cout << "4. Division" << std::endl;

    while (true) { // While loop
        std::cout << "Enter from (0, 5) and (1, 2, 3, 4): ";
        std::cin >> choice;

        if (choice == 0) {
            #ifdef __WIN32
                system("cls");
            #elif defined(__linux__)
                system("clear");
            #else
                std::cout << "System is Unknown" << std::endl;
            #endif

        } else if (choice == 1) {
            nums_ = get_numbers();
            std::cout << red << "Addition" << no_col << " = " << blue << Addition( nums_.n1, nums_.n2 ) << no_col << std::endl;
            
        } else if (choice == 2) {
            nums_ = get_numbers();
            std::cout << green << "subtraction" << no_col << " = " << blue << subtraction( nums_.n1, nums_.n2 ) << no_col << std::endl;
            
        } else if (choice == 3) {
            nums_ = get_numbers();
            std::cout << orange << "multiplication" << no_col << " = " << blue << multiplication( nums_.n1, nums_.n2 ) << no_col << std::endl;
            
        } else if (choice == 4) {
            nums_ = get_numbers();
            std::cout << sky << "division" << no_col << " = " << blue << division( nums_.n1, nums_.n2 ) << no_col << std::endl;
            
        } else if (choice == 5) {
            break;
        }
    }
}

