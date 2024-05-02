#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define a structure for the bank account
struct Account
{
    char username[50];
    char password[50];
    float balance;
};

// Sample user account
struct Account user = {"user123", "password123", 1000.0};

// Function prototypes
bool authenticate(char username[], char password[]);
void displayMenu();
void checkBalance();
void deposit();
void withdraw();
void logout();

int main()
{
    char username[50];
    char password[50];

    // Authentication loop
    while (true)
    {
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        if (authenticate(username, password))
        {
            printf("Welcome, %s!\n", username);
            break;
        }
        else
        {
            printf("Invalid username or password. Please try again.\n");
        }
    }

    // Display main menu
    displayMenu();

    return 0;
}

// Function to authenticate user
bool authenticate(char username[], char password[])
{
    return (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0);
}

// Function to display main menu
void displayMenu()
{
    int choice;
    do
    {
        printf("\nMain Menu:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            checkBalance();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            logout();
            break;
        default:
            printf("Invalid choice. Please enter a number from 1 to 4.\n");
        }
    } while (choice != 4);
}

// Function to check balance
void checkBalance()
{
    printf("Your balance is: $%.2f\n", user.balance);
}

// Function to deposit money
void deposit()
{
    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    if (amount > 0)
    {
        user.balance += amount;
        printf("Deposit successful. New balance is: $%.2f\n", user.balance);
    }
    else
    {
        printf("Invalid amount. Deposit failed.\n");
    }
}

// Function to withdraw money
void withdraw()
{
    float amount;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= user.balance)
    {
        user.balance -= amount;
        printf("Withdrawal successful. New balance is: $%.2f\n", user.balance);
    }
    else
    {
        printf("Invalid amount or insufficient funds. Withdrawal failed.\n");
    }
}

// Function to logout
void logout()
{
    printf("Logged out. Thank you for using CodedCash!\n");
    exit(0);
}
