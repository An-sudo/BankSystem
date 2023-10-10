#ifndef INC_053FIINALPROJECT_SAVINGACCOUNT_H
#define INC_053FIINALPROJECT_SAVINGACCOUNT_H
# include <string>
#include <iostream>
#include "SortDiff.h"
using namespace std;


class SaveAccount{

    static const string s_head;
    static int s_tail;
    static string savingAccountNum_s;
    string uI;

private:
    string savingAccountNum;
    long int savingAccountBalance;

public:
    void saveMenu(){
        cout << "|------Saving Account:" << savingAccountNum << "\n"
                "|        W---Withdraw\n"
                "|        D---Deposit\n"
                "|        X---Exit\n";
        cout << "Please enter selection: \033[0m";
    }
    SaveAccount(){
    }
    SaveAccount(long int savingAccountBalance){
        this -> savingAccountNum = s_head + to_string(s_tail);
        this -> savingAccountBalance = savingAccountBalance;
        s_tail = s_tail + 1;
    }
    string const getSavingAccountNum(){
        return savingAccountNum;
    }
    int const getBalanceSavingAccount(){
        return savingAccountBalance;
    }

    void setBalanceSavingAccount (long int num){
        this -> savingAccountBalance=  num;
    }



    void deposit(long int num){
        if(num>0){
            savingAccountBalance = savingAccountBalance + num;
            cout <<"    | Your money has been deposited! Saving Account Balance: $"<<savingAccountBalance<< endl<< endl;
        }else {
            cout <<"    | Invalid value!" << endl<<endl;
        }
    }

    void withdraw(long int num){
        if(savingAccountBalance<num){
            cout << "   | Balance is not enough." << endl << endl;
        }else{
            savingAccountBalance = savingAccountBalance - num;
            cout << "-----------------------------" << endl;
            cout << "| Your money has been withdrew!"<< endl;
            cout << "| Saving Account Balance: $"<<savingAccountBalance<< endl;
            cout << "-----------------------------" << endl;
        }
    }

    void printSavingAccountInfo(){
        cout << "   | Sub-Account Number: " << savingAccountNum <<endl;
        cout << "   | Balance: $" << savingAccountBalance << endl<< endl;
    }

    void modSaveAccount() {
        saveMenu();
        cin >> uI;
        while (uI != "x" || uI != "X") {
            if (uI == "w" || uI == "W") {
                cout << "   Please enter money:";
                int uI;
                cin >> uI;
                if (uI > 0) {
                    withdraw(uI);
                } else {
                    cout << "   | Invalid value! Please enter again!" << endl << endl;
                }
            } else if (uI == "d" || uI == "D") {
                cout << "Please enter money:";
                int uI;
                cin >> uI;
                if (uI > 0) {
                    deposit(uI);
                } else {
                    cout << "   | Invalid value! Please enter again!" << endl<< endl;
                }
            }else if (uI == "x" || uI == "X"){
                break;
            }else {
                cout << "   | Invalid value! Please enter again!" << endl << endl;
            }
            saveMenu();
            cin >> uI;
        }
    }
};



int SaveAccount :: s_tail = 1000;
const string SaveAccount :: s_head = "SAV";


#endif //INC_053FIINALPROJECT_SAVINGACCOUNT_H
