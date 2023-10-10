#ifndef BANKSYSTEM_BANK_H
#define BANKSYSTEM_BANK_H
#include "Account.h"


const static string B_HEAD = "BNK";
int B_TAIL = 10000;

class Bank {
private:
    string bankName;
    string bankAddress;
    string bankWorkingHours;

public:
    string uI;
    vector<Account> accountList;
    int numSaveAccount();
    int numCheckAccount();
    bool checkAccountExist(string SSN);
    string getAccountNumberBasedSSN(string SSN);
    void modBank();
    int aggregatedBalance();
    void printBankInfo();
    void homePage() {
        cout << "Eligiable services for " << bankName << endl;
        cout << "      A---Number of Bank-Accounts\n"
                "      S---Number of Saving-Accounts\n"
                "      H---Number of Checking-Accounts\n"
                "      O---Open Bank-Account\n"
                "      C---Close Bank-Account\n"
                "      M---Modify Bank-Account\n"
                "      D---Detailed Bank-Account\n"
                "      B---Brief Bank-Accounts Information (Sorted by Aggregated Balances)\n"
                "      X---Exit\n"
                "Please enter your selection: ";
    }
    Bank() = default;
    Bank(string bankName, string bankAddress, string bankWorkingHours) {
        this->bankName = bankName;
        this->bankAddress = bankAddress;
        this->bankWorkingHours = bankWorkingHours;
    }

    string getBankName() {
        return bankName;
    }
    void detailedBankAccount() {
        printBankInfo();
        for (auto &i: accountList) {
            i.printPersonInfo();
            i.printDetailBankInfo();
        }
    }
    void briefInfoSorted() {
        printBankInfo();
        for (int i = 0; i < accountList.size(); ++i) {
            int largestIndex = i;
            for (int j = i + 1; j < accountList.size(); ++j) {

                if (accountList[j].totalBalance() > accountList[largestIndex].totalBalance()) {
                    largestIndex = j;
                }
            }
            Account temp = accountList[i];
            accountList[i] = accountList[largestIndex];
            accountList[largestIndex] = temp;
        }
        int j = 0;
        while(j<accountList.size()){
            accountList[j].printPersonInfo();
            for(auto i : accountList){
                i.printDetailBankInfo();
            }
            j++;
        }
    }
    void openAccount() {
            string firstName, secondName, SSN;
            cout << "   Enter the first name of the account holder: ";
            cin >> firstName;
            cout << "   Enter the last name of the account holder: ";
            cin >> secondName;
            cout << "   Enter the SSN of the account holder: ";
            cin >> SSN;
            if (checkAccountExist(SSN)) {
                cout << "   | Based your Social Security Number, you already have an account" << endl;
                cout << "   | Your account number is: " << getAccountNumberBasedSSN(SSN) << endl;
            } else {
                Account newAccount = Account(firstName, secondName, SSN);
                accountList.push_back(newAccount);
                cout<<"   | A new Bank Account " << accountList.back().getAccountNum() << " was successfully created." << endl << endl;
                accountList.back().AccountPage();
            }
    }
    void closeAccount(string num){
        for (int i = 0; i < accountList.size(); ++i) {
            if (accountList[i].getAccountNum() == num) {
                cout << "   | Your account " << accountList[i].getAccountNum() << "has been closed!\n" <<endl;
                accountList.erase(accountList.begin() + i);
                break;
            } else {
            cout << "   | Your account " << accountList[i].getAccountNum() << "is not exist.\n" << endl;
            }
        }
    }

};


void Bank::printBankInfo(){
    cout << "   | Bank Name: " << bankName <<  endl;
    cout << "   | Bank Address: " << bankAddress << endl;
    cout << "   | Bank Working Hours: " << bankWorkingHours << endl;
    cout << "   | Aggregated Balance: " << aggregatedBalance() << endl;
    cout << "   | Consists of " << accountList.size()<< " Bank-Accounts" << endl << endl;
}

int Bank:: aggregatedBalance(){
    int balance =0;
    for(auto i : accountList){
        balance  = balance + i.totalBalance();
    }
    return balance;
}

int Bank::numSaveAccount() {
    int num = 0;
    for (auto & i : accountList) {
        num = num + i.saveList.size();
    }
    return num;
}

int Bank ::numCheckAccount() {
    int num = 0;
    for (auto & i : accountList) {
        num = num + i.checkList.size();
    }
    return num;
}

bool Bank :: checkAccountExist(string SSN){
    for(auto & i : accountList){
        if(i.getSSN() == SSN){
            return true;
        }
    }
    return false;
}

string Bank :: getAccountNumberBasedSSN(string SSN){
    for (auto i: accountList) {
        if (i.getSSN() == SSN) {
            return i.getAccountNum();
        }
    }
    return "0";
}

void Bank:: modBank(){
    homePage();
    cin >> uI;
    while(uI!="X" || uI != "x"){
        if(uI=="A" || uI == "a"){
            cout <<"    | The number of Bank-Account is " << accountList.size() << endl << endl;
        }else if(uI=="S" || uI == "s"){
            cout <<"    | The number of Saving-Account is " << numSaveAccount() << endl << endl;
        }else if(uI=="H" || uI == "h"){
            cout <<"    | The number of Checking-Account is " << numCheckAccount() << endl << endl;
        }else if(uI=="O" || uI == "o"){
            openAccount();
        }else if(uI=="C" || uI == "c"){
            cout << "   Please enter your Account number that you want to close:";
            cin >> uI;
            closeAccount(uI);
        }else if(uI=="M" || uI == "m"){
            cout << "   Please enter your Account number that you want to modify:";
            cin >> uI;
            for(auto &i : accountList){
                if(i.getAccountNum()==uI){
                   i.AccountPage();
                }else{
                    cout << "   | "<< uI << " is not exist in system."<< endl;
                }
            }
        }else if(uI=="D" || uI == "d"){
            detailedBankAccount();
        }else if(uI=="B" || uI == "b"){
            briefInfoSorted();
        }else if(uI=="X" || uI == "x"){
            break;
        }else {
            cout << "   | Invalid value! Please enter again!" << endl;
        }
        homePage();
        cin >> uI;
    }
}

#endif //BANKSYSTEM_BANK_H
