#include <iostream>
#include <string>
#include <ctime>
#include <random>
using namespace std;

class BankAcc
{
    int acc_no, total_amount, deposite_amount, remaining_balance;

public:
    string acc_type, acc_holder_name;
    int initial_balance;
    // Create account by default
    BankAcc(string, int); // parametarized constructor

    int deposite(int); // deposite money
    int withdraw(int); // withdraw money
    void getAccDetail(string acc_type, string acc_holder_name);// get acc details
};

BankAcc ::BankAcc(string name, int amount)
{
    srand((unsigned)time(0)); // set seed

    acc_holder_name = name;
    initial_balance = amount;
    total_amount = initial_balance;
    acc_no = 1925271964 + rand() % 90491; // generate acc no randomly
    cout << "Initial balance is :" << initial_balance << endl;
    cout << "Total Balance : " << total_amount << endl;
}

int BankAcc ::deposite(int deposite_money)
{
    deposite_amount = deposite_money;
    total_amount = total_amount + deposite_amount;
    return total_amount;
}

int BankAcc ::withdraw(int withdraw_money)
{
    if (withdraw_money > 0 && total_amount-withdraw_money > 0)
        cout<<"Amount to be withdrawn : " << withdraw_money<<endl;
        remaining_balance = total_amount-withdraw_money;
        total_amount = remaining_balance;
    return remaining_balance;
}

void BankAcc ::getAccDetail(string acc_type, string acc_holder_name)
{
    cout << "###########################" << endl;
    cout << "Acc holder name : " << acc_holder_name << endl;
    cout << "Account type is :" << acc_type << endl;
    cout << "Account number is :" << acc_no << endl;
    cout << "Total balance : " << total_amount<<endl; // get total balance
}

int main()
{

    BankAcc BA("Ramesh", 1000);

    cout << "Enter account type :";
    cin >> BA.acc_type;
    

    BA.deposite(1000);
    BA.getAccDetail(BA.acc_type, BA.acc_holder_name);
    BA.withdraw(100);
    BA.getAccDetail(BA.acc_type, BA.acc_holder_name);

    return 0;
}