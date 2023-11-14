#include <iostream> 
using namespace std;

//declaration of varibale
class BankAccount {
    private:
        static int accountNumber;
        string accountHolderName;
        double accountBalance;
    public:
        BankAccount();
        BankAccount(string accountHolderName, double AccountBalance);
        double getBalance();
        void displayaccountInfo();
        void deposit(double amount);
        void withdraw(double amount);
//default constructor
};
BankAccount :: BankAccount (){
    accountBalance = 0.00;
    accountHolderName = "John Doe";
    accountNumber++;
}
//overloaded constructor
BankAccount :: BankAccount (string holderName, double balance){
    accountBalance = balance;
    accountHolderName =  holderName;
    accountNumber++;
}
//returns balance
double BankAccount :: getBalance(){
    return accountBalance;
}
//prints account information
void BankAccount :: displayaccountInfo(){
    cout << "---------- ACCOUNT INFO ----------" << endl;
    cout << "Account number: " << accountNumber << endl;
    cout << "Account Holder's Name: " << accountHolderName << endl;
    cout << "Account Balance: " << accountBalance << endl;
    cout << "----------------------------------" << endl;
}
//allows deposit of funds
void BankAccount :: deposit(double amount){
    accountBalance += amount;
}
//allows withdrawl of funds
void BankAccount :: withdraw(double amount){
    if (accountBalance >= amount){
        accountBalance -= amount;
    }else{
        cout << "Unable to withdraw, try again." << endl;
    }
}

int BankAccount :: accountNumber = 0;

int main(){
    //variable decleration
    string name;
    double balance;
    int input = 0; 

    //allows user to create an account
    cout << "---- Create a bank account ----" << endl;
    cout << "Account Name: " << endl;
    getline(cin, name);
    cout << "Account Balance: " << endl;
    cin >> balance;

    //creates a bank acc object
    BankAccount one(name, balance);

    while(input != 4){
        //displays menu
        cout << "-------------- MENU --------------" << endl;
        cout << "1. Display account information" << endl;
        cout << "2. Deposit funds" << endl;
        cout << "3. Withdraw funds" << endl;
        cout << "4. EXIT" << endl;
        cout << "----------------------------------" << endl;
        //user input
        cout << "INPUT: ";
        cin >> input; 
        //verifies input is from 1 - 4
        if (input == 1 || input == 2 || input == 3 || input == 4){
            switch (input){
                case 1:
                    one.displayaccountInfo();
                    break;
                case 2:
                    cout << "DEPOSIT AMOUNT: " << endl;
                    cin >> balance;
                    one.deposit(balance);
                    break;
                case 3:
                    cout << "WITHDRAW AMOUNT:" << endl;
                    cin >> balance;
                    one.withdraw(balance);
                    break;
                case 4:
                    cout << "EXITING .. Thanks for choosing Carolina's bank!" << endl;
                    break;
            }
        }
    }

}