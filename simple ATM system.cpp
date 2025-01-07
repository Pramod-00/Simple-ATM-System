// Description: this program will implement a simple bank ATM system

#include <iostream>
using namespace std;

char getactInput();
float checkbalance(float);
float withdraw(float, float);
float deposit(float, float);

int main()
{
    int account, sum;
    char option, cont;
    float balance = 1000;

    do {
        option = getactInput();
        switch(option) {
            case 'A':
            case 'a':
                checkbalance(balance);
                break;
            case 'B':
            case 'b':
                cout << "Enter the amount: $";
                cin >> sum;
                balance = withdraw(balance, sum);
                checkbalance(balance);
                break;
            case 'C':
            case 'c':
                cout << "Enter the amount: $";
                cin >> sum;
                balance = deposit(balance, sum);
                checkbalance(balance);
                break;
            default:
                cout << "ERROR: Invalid option.\n";
        }

        cout << "Would you like to continue (y/n)? ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    return 0;
}

char getactInput()
{
    cout << "Select an option from the following:\n"
         << "a) Check Balance\n"
         << "b) Withdraw\n"
         << "c) Deposit\n"
         << "Please select an option: ";
    char option;
    cin >> option;
    return option;
}

float checkbalance(float balance)
{
    cout << "Your account balance is $" << balance << "\n";
    return balance;
}

float withdraw(float balance, float amount)
{
    if (amount > balance) {
        cout << "ERROR: Insufficient funds.\n";
    } else {
        balance -= amount;
    }
    return balance;
}

float deposit(float balance, float amount)
{
    balance += amount;
    return balance;
}
