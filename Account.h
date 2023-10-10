#ifndef BANKSYSTEM_ACCOUNT_H
#define BANKSYSTEM_ACCOUNT_H

#include <string>
#include <iostream>
#include <vector>
#include "CheckAccount.h"
#include "SaveAccount.h"


class Account{
    const static string a_head;
    static int a_tail;
    string uI;
private:
    string firstName;
    string secondName;
    string SSN;
    string accountNum;

public:

    void secondMenu(){
        cout << "Eligiable Services For Bank-Account " << accountNum << endl;
        cout << "      S---Open Saving Sub-Account\n"
                "      C---Open Checking Sub-Account\n"
                "      M---Modify a Sub-Account\n"
                "      E---Close a Sub-Account\n"
                "      D---Detailed Bank Account Info Sorted Based on Balance of Sub-Accounts\n"
                "      B---Brief Bank Accounts Information\n"
                "      X---Exit\n"
                "Please enter your selection: ";
    }

    void modMenuPage(){

        cout << "Account Number " << getAccountNum() << endl;
        cout << "        S---Modify Saving Account" << endl;
        cout << "        C---Modify Checking-Accounts" << endl;
        cout << "        X---Exit" << endl;
        cout << "Please enter the Sub-Account kind that you want to modify: ";
    }

    void closeMenuPage(){
        cout << "Account Number: " << getAccountNum() << endl;
        cout << "        S---Close Saving Account" << endl;
        cout << "        C---Close Checking-Accounts" << endl;
        cout << "        X---Exit" << endl;
        cout << "Please enter the Sub-Account kind that you want to Close: ";
    }

    void AccountPage();
    bool saveListIsEmpty();
    bool checkListIsEmpty();
    void printSaveList();
    void printCheckList();
    int searchTwoVector(string num);
    int totalBalance();
    int countAccount();
    void sortCheckList();
    void sortSaveList();
    void printPersonInfo();
    string fullName;
    vector<CheckAccount> checkList;
    vector<SaveAccount> saveList;
    Account(string firstName, string secondName, string SSN){
        this -> firstName = firstName;
        this -> secondName = secondName;
        this -> SSN = SSN;
        this -> accountNum = a_head + to_string(a_tail);
        this -> fullName = firstName + secondName;
        a_tail = a_tail + 1;
    }
    string const getFirstName(){
        return this->firstName;
    }
    string const getSecondName(){
        return this -> secondName;
    }
    string const getSSN(){
        return this -> SSN;
    }
    string const getAccountNum(){
        return this -> accountNum;
    }
    void setFirstName(string name){
        this -> firstName =  name;
    }
    void setSecondName(string name){
        this -> secondName = name;
    }
    void setSSN(string num){
        this -> SSN = num;
    }
    void openSaveAccount(){
        int balance;
        cout << "   Enter the initial balance:";
        cin >> balance;
        if(saveListIsEmpty()){
            saveList.emplace_back(100+balance);
            cout <<"    | A new Saving Sub-Account " << saveList.back().getSavingAccountNum()<< " was successfully created." << endl << endl;
        }else{
            SaveAccount temp = SaveAccount(balance);
            saveList.push_back(temp);
            cout <<"    | A new Saving Sub-Account " << saveList.back().getSavingAccountNum()<< " was successfully created." << endl << endl;
        }
    }
    void openCheckAccount(){
        int balance,capacity;
        string status;
        bool temp2;
        cout << "   Enter the initial balance:";
        cin >> balance;
        cout << "   Enter the desired maximum capacity: ";
        cin >> capacity;
        cout <<"    Define initial state:(L - Locked, Otherwise - Unlocked)";
        cin >> status;

        if(status == "L" || status == "l"){
            temp2 = true;
        }else{
            temp2 = false;
        }

        if(checkListIsEmpty()){
            int i = 100 + balance;
            CheckAccount temp = CheckAccount(100 + balance,capacity,temp2);
            checkList.push_back(temp);
            cout <<"    | A new Checking Sub-Account " << checkList.back().getCheckingAccountNum()<< " was successfully created." << endl << endl;
        }else{
            CheckAccount temp = CheckAccount(balance,capacity,temp2);
            checkList.push_back(temp);
            cout <<"    | A new Checking Sub-Account " << checkList.back().getCheckingAccountNum()<< " was successfully created." << endl << endl;
        }
    }



    void modSubAccount(){

        modMenuPage();
        cin >> uI;
        while(uI != "x" || uI != "X"){
            if(uI == "s" || uI == "S" ){
                printSaveList();
                cout << "   Please enter the saving account number you want to modify:";
                cin >> uI;
                for(auto &i : saveList){
                    if(i.getSavingAccountNum()==uI){
                        i.modSaveAccount();
                    }else {
                        cout << "   | Invalid Saving Account Number.\n";
                        return;
                    }
                }
            }else if(uI == "c" || uI == "C"){
                printCheckList();
                cout << "   Please enter the saving account number you want to modify:";
                cin >> uI;
                for(auto &i : checkList){
                    if(i.getCheckingAccountNum()==uI){
                        i.modCheckAccount();
                    }else {
                        cout << "   | Invalid Checking Account Number.\n";
                        return;
                    }
                }
            }else if(uI == "x" || uI == "X"){
                break;
            }else{
                warning();
            }
            modMenuPage();
            cin >> uI;
        }
    }
    void closeSubAccount(){
        closeMenuPage();
        cin >> uI;
        while(uI != "x" || uI != "X"){
            if(uI == "s" || uI == "S" ){
                printSaveList();
                cout << "   Please enter the saving account number you want to close:";
                cin >> uI;
                for(int i = 0; i<saveList.size();++i){
                    if(saveList[i].getSavingAccountNum()==uI){
                        cout <<"    | Your Saving Account: "<< saveList[i].getSavingAccountNum()<< " has been closed successfully!" << endl;
                        saveList.erase(saveList.begin()+i);
                        break;
                    }else{
                        cout <<"    | Your Sub-account is not exist." << endl;
                        return;
                    }
                }
            }else if(uI == "c" || uI == "C"){
                printSaveList();
                cout << "   Please enter the checking account number you want to close:";
                cin >> uI;
                for(int i = 0; i<saveList.size();++i){
                    if(saveList[i].getSavingAccountNum()==uI){
                        cout <<"    | Your Checking Account: "<< checkList[i].getCheckingAccountNum()<< " has been closed successfully!" << endl;
                        checkList.erase(checkList.begin()+i);
                        break;
                    }else{
                        cout << "   | Your Sub-account is not exist." << endl;
                        return;
                    }
                }
            }else if(uI == "x" || uI == "X"){
                break;
            }else{
                warning();
            }
            modMenuPage();
            cin >> uI;
        }
//
    }
    void printBankAccountInfo(){
      cout << " | Aggregated Balance of the bank account: "<< accountNum << " with " << countAccount() << " Sub-Accounts is " << totalBalance() << endl;
    }

    void printDetailBankInfo(){
        if(saveListIsEmpty() && checkListIsEmpty()){
            cout << "   | No Sub-Accounts!" << endl;
        }else{
            sortCheckList();
            sortSaveList();
            int i = 0;
            int j = 0;

            if(saveListIsEmpty() && !checkListIsEmpty()){
                while(j < checkList.size()){
                    checkList[j].printAccountInfo();
                    j++;
                }
                return;
            }else if(!saveListIsEmpty() && checkListIsEmpty()){
                while(i<saveList.size()){
                    saveList[i].printSavingAccountInfo();
                    i++;
                }
                return;
            }else{
                while(i<saveList.size() || j < checkList.size()){
                    if(saveList[i].getBalanceSavingAccount() > checkList[j].getBalanceCheckingAccount()){
                        saveList[i].printSavingAccountInfo();
                        i++;
                    }else{
                        checkList[j].printAccountInfo();
                        j++;
                    }
                }
                while(i<saveList.size()){
                    saveList[i].printSavingAccountInfo();
                    i++;
                }
                while(j < checkList.size()){
                    checkList[j].printAccountInfo();
                    j++;
                }
                return;
            }









        }

    }
};
const string Account :: a_head = "BNK";
int Account :: a_tail = 10000;
bool Account :: saveListIsEmpty(){
    if(saveList.size()<=0){
        return true;
    }else{
        return false;
    }
}
bool Account ::checkListIsEmpty() {
    if(checkList.size() <=0){
        return true;
    }else{
        return false;
    }
}
void Account ::printSaveList() {
    for(auto i: saveList){
        i.printSavingAccountInfo();
    }
}
void Account ::printCheckList() {
    for(auto i:checkList){
        i.printAccountInfo();
    }
}
int Account :: searchTwoVector(string num){
    for(int i = 0 ; i<checkList.size(); ++i){
        if(checkList[i].getCheckingAccountNum()==num){
            return i;
        }
    }
    for(int i = 0; i<saveList.size();++i){
        if(saveList[i].getSavingAccountNum()==num){
            return i;
        }
    }
    return -1;
}
int Account :: totalBalance (){
    int temp = 0;
    for(auto i : checkList){
        temp = temp + i.getBalanceCheckingAccount();
    }
    for(auto i : saveList){
        temp = temp + i.getBalanceSavingAccount();
    }
    return temp;
}
void Account::AccountPage (){
    secondMenu();
    cin >> uI;
    while(uI != "X" || uI != "x"){
        if(uI == "S" || uI == "s"){
            openSaveAccount();
        }else if(uI == "C" || uI == "c"){
            openCheckAccount();
        }else if(uI == "M" || uI == "m"){
            modSubAccount();
        }else if(uI == "E" || uI == "e"){
            closeSubAccount();
        }else if(uI == "D" || uI == "d"){
            printDetailBankInfo();
        }else if(uI == "B" || uI == "b"){
            printBankAccountInfo();
        }else if(uI == "X" || uI == "x"){
            cout << "   End of Service for Bank-Account " << accountNum << endl;
            break;
        }else{
            warning();
        }
        secondMenu();
        cin >> uI;
    }
}

int Account:: countAccount(){
    return  checkList.size() + saveList.size();
}
void Account :: sortCheckList(){
    for(int i = 0 ; i < checkList.size();++i){
        int largestIndex=i;
        for(int j = i +1 ; j<checkList.size();++j){

            if(checkList[j].getBalanceCheckingAccount()>checkList[largestIndex].getBalanceCheckingAccount()){
                largestIndex = j;
            }
        }
        CheckAccount temp;
        temp = checkList[i];
        checkList[i] = checkList[largestIndex];
        checkList[largestIndex] = temp;
    }
}
void Account :: sortSaveList(){
    for(int i = 0 ; i < saveList.size();++i){
        int largestIndex=i;
        for(int j = i +1 ; j<saveList.size();++j){

            if(saveList[j].getBalanceSavingAccount()>saveList[largestIndex].getBalanceSavingAccount()){
                largestIndex = j;
            }
        }
        SaveAccount temp;
        temp = saveList[i];
        saveList[i] = saveList[largestIndex];
        saveList[largestIndex] = temp;
    }
}
void Account :: printPersonInfo(){
    cout << "   | Bank Account Number: " << accountNum << endl;
    cout << "   | Account Holder Full Name: " << firstName << " " <<  secondName << endl;
    cout << "   | Account Holder SSN: " << SSN << endl;
    cout << "   | Aggregated Balance: " << totalBalance() << endl;
    cout << "   | Consists of " << countAccount()<< " Sub-Accounts" << endl<< endl;
}
#endif //BANKSYSTEM_ACCOUNT_H
