#include <iostream>
#include "Bank.h"

int main() {

    string BankName, BankAddress, BankWorkingHours;
    string userInput;

    cout<< "Welcome to use Bank System" << endl;
    cout<< "    Please Enter the Name of the Bank:";
    getline(cin,BankName);
    cout << "   Please Enter the Address of the Bank:";
    getline(cin,BankAddress);
    cout << "   Please Enter the Working Hours of the Bank:";
    getline(cin,BankWorkingHours);
    Bank bank = Bank(BankName,BankAddress,BankWorkingHours);
    bank.modBank();
    return 0;
}
