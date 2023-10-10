#ifndef INC_053FIINALPROJECT_CHECKACCOUNT_H
#define INC_053FIINALPROJECT_CHECKACCOUNT_H
#include <string>
#include <iostream>
#include "SortDiff.h"
using namespace std;
void warning(){
    cout << "   | Invalid value! Please enter again!"<< endl << endl;
}
class CheckAccount{
    string uI;
    const static string c_head;
    static int c_tail;

private:
    string checkingAccountNum;
    long int checkingAccountBalance;
    long int maxCapacity;
public:
    void checkMenu(){
        cout << "------Saving Account:" << checkingAccountNum << "------\n"
                "        W---Withdraw\n"
                "        D---Deposit\n"
                "        U---Unlock Checking Account\n"
                "        L---Lock Checking Account\n"
                "        C---Set up max capacity\n"
                "        X---Exit\n";
        cout << "Please enter selection: ";
    }
    bool lock;

    CheckAccount(){};
    CheckAccount(int Balance,int capacity,bool status){
        this -> checkingAccountNum = c_head + to_string(c_tail);
        this -> checkingAccountBalance = Balance;
        this -> maxCapacity = capacity;
        this -> lock = status;
        c_tail = c_tail + 1;
    }


    string getCheckingAccountNum(){
        return this -> checkingAccountNum;
    }
    long int getBalanceCheckingAccount(){
        return this -> checkingAccountBalance;
    }
    void setMaxCapacity(long int num){
        this -> maxCapacity = num;
    }

    void lockCheckingAccount(){
        lock = true;
    }
    void unlockCheckingAccount(){
        lock = false;
    }



    void deposit(long int num){
        if(!lock){
            if(checkingAccountBalance + num > maxCapacity){
                cout <<"    | Checking Account maximum limit exceeded\n" << endl << endl;
            }else{
                checkingAccountBalance = checkingAccountBalance + num;
                cout <<"    | Your money has been deposited! Checking Account Balance: $" << checkingAccountBalance << endl << endl;
            }
        }
    }



    void withdraw(long int num){
            if(checkingAccountBalance - num < 0){
                cout <<"    |  Balance is not enough!" << endl << endl;
            }else{
                checkingAccountBalance = checkingAccountBalance - num;
                cout << "   | Your money has been withdrew! Checking Account Balance: $"<<checkingAccountBalance<< endl<< endl;
        }

    }

    void printAccountInfo(){
        cout << "   | Sub-account number: " << checkingAccountNum << endl;
        cout << "   | Balance: $" << checkingAccountBalance << endl;
        cout << "   | The maximum capacity is: $" << maxCapacity << endl;
        if(lock){
            cout << "   | The sub-account is locked." << endl<< endl;
        }else{
            cout << "   | The sub-account is not locked." << endl<< endl;
        }
    }

    void modCheckAccount(){
        checkMenu();
        cin >> uI;
        while(uI != "x" || uI != "X"){
            if(uI == "w" || uI == "W"){
                if(lock){
                    cout <<"    | Checking Account has been locked! Please to Unlock Checking Account" << endl << endl;
                }else{
                    cout << "   Please enter money you want withdraw:";
                    int num;
                    cin >> num;
                    if (num > 0) {
                        withdraw(num);
                    }else{
                        cout << "   | Invalid value! Please enter again!" << endl<< endl;
                    }
                }
            }else if(uI == "d" || uI == "D"){
                if(lock){
                    cout <<"    | Checking Account has been locked! Please to Unlock Checking Account" << endl<< endl;
                }else{
                    cout << "   Please enter money you want deposit:";
                    int num;
                    cin >> num;
                    if (num > 0) {
                        deposit(num);
                    }else{
                        cout << "   | Invalid value! Please enter again!" << endl<< endl;
                    }
                }
            }else if(uI == "U" || uI == "u") {
                 unlockCheckingAccount();
                cout << "   | Checking Account has been successfully Unlocked" << endl<< endl;

            }else if(uI == "L" || uI == "L"){
                lockCheckingAccount();
                cout << "   | Checking Account has been successfully locked" << endl<<endl;
            }else if(uI == "x" || uI == "X"){
                break;
            }else if(uI == "c" || uI == "C"){
                if(lock){
                    cout <<"    | Checking Account has been locked! Please unlock Checking Account" << endl<< endl;
                }else{
                    cout << "   | Please enter max capacity:";
                    int num;
                    cin >> num;
                    if(num>0){
                        setMaxCapacity(num);
                    }else{
                        cout << "   | Invalid value! Please enter again!" << endl << endl;
                    }
                }
            }else {
                cout << "   | Invalid value! Please enter again!" << endl << endl;
            }
            checkMenu();
            cin >> uI;
        }
    }
};


const string CheckAccount :: c_head = "CHK";
int CheckAccount :: c_tail = 6000;

#endif //INC_053FIINALPROJECT_CHECKACCOUNT_H
