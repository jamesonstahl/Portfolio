#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

class Account{
public:
    virtual void CloseAccount() = 0;
    virtual void OpenAccount(double x) = 0;
    virtual void ShowInfo() = 0;
    virtual bool ShowStatus() = 0;
protected:
    double balance;
    int number;
    bool status;
};

bool Account::ShowStatus(){
    return status;
}

class Checking : public Account{
public:
    Checking();
    void CloseAccount();
    void OpenAccount(double x);
    void ShowInfo();
    void Deposit(double x);
    void Withdraw(double x);
    void Order(int x);
    void Write(double x);
    bool ShowStatus();
protected:
    int numberChecks;
};

Checking::Checking(){
    srand(static_cast<unsigned int>(time(nullptr)));
    numberChecks = 10;
    number = (rand() % 5000) + 1;
    status = false;
}

void Checking::CloseAccount(){
    status = false;
    balance = 0;
}

void Checking::OpenAccount(double x){
    status = true;
    balance = x;
}

void Checking::ShowInfo(){
    cout << "Account number: " << number << endl;
    cout << "Balance: $" << balance << endl;
    if(status == true){
        cout << "Account Status: Open" << endl;
    }
    else if(status == false){
        cout << "Account Status: Closed" << endl;
    }
    
    cout << "Number of checks: " << numberChecks << endl;
}

void Checking::Deposit(double x){
    balance += x;
}

void Checking::Withdraw(double x){
    if((balance - x) >= 0){
        balance -= x;
    }
    else{
        cout << "Insufficient funds" << endl;
    }
}

void Checking::Order(int x){
    numberChecks += x;
}

void Checking::Write(double x){
    if((balance - x) >= 0){
        balance -= x;
        numberChecks -= 1;
    }
    else{
        cout << "Insufficient funds" << endl;
    }
}

bool Checking::ShowStatus(){
    return status;
}

class Savings : public Account{
public:
    Savings();
    void CloseAccount();
    void OpenAccount(double x);
    void ShowInfo();
    bool ShowStatus();
protected:
    double interestRate = 0.03;
    double matureBalance;
};

Savings::Savings(){
    srand(static_cast<unsigned int>(time(nullptr)));
    number = (rand() % 5000) + 5001;
    status = false;
}

void Savings::CloseAccount(){
    status = false;
    balance = 0;
}

void Savings::OpenAccount(double x){
    status = true;
    balance = x;
    matureBalance = balance + (balance * interestRate);
}

void Savings::ShowInfo(){
    cout << "Account number: " << number << endl;
    cout << "Balance: $" << balance << endl;
    if(status == true){
        cout << "Account Status: Open" << endl;
    }
    else if(status == false){
        cout << "Account Status: Closed" << endl;
    }
    
    cout << "Mature Balance: " << matureBalance << endl;
}

bool Savings::ShowStatus(){
    return status;
}

class Customer{
public:
    Customer();
    Customer(string name, string pin);
    void CheckSavings();
    void CheckChecking();
    void Show();
    string GetName();
    string GetPin();
    void CloseChecking();
    void OpenChecking(double x);
    void ShowCheckingInfo();
    void Deposit(double x);
    void Withdraw(double x);
    void Order(int x);
    void Write(double x);
    void CloseSavings();
    void OpenSavings(double x);
    void ShowSavingsInfo();
    bool ShowCheckingStatus();
    bool ShowSavingsStatus();
private:
    string name;
    string pin;
    Checking checkings;
    Savings savings;
};

Customer::Customer(){
    
}

Customer::Customer(string a, string b){
    name = a;
    pin = b;
}

void Customer::CheckSavings(){
    if(savings.ShowStatus() == true){
        cout << "Savings account is open" << endl;
    }
    else{
        cout << "Savings account is closed" << endl;
    }
}

void Customer::CheckChecking(){
    if(checkings.ShowStatus() == true){
            cout << "Checking account is open" << endl;
        }
        else{
            cout << "Checking account is closed" << endl;
        }
}

void Customer::Show(){
    cout << "Name: " << name << endl;
    cout << "Pin: " << pin << endl;
    if(savings.ShowStatus() == true){
        cout << "Savings:" << endl;
        savings.ShowInfo();
    }
    if(checkings.ShowStatus() == true){
        cout << "Checking:" << endl;
        checkings.ShowInfo();
    }
}

string Customer::GetName(){
    return name;
}

string Customer::GetPin(){
    return pin;
}

void Customer::CloseChecking(){
    checkings.CloseAccount();
}

void Customer::OpenChecking(double x){
    checkings.OpenAccount(x);
}

void Customer::ShowCheckingInfo(){
    checkings.ShowInfo();
}

void Customer::Deposit(double x){
    checkings.Deposit(x);
}

void Customer::Withdraw(double x){
    checkings.Withdraw(x);
}

void Customer::Order(int x){
    checkings.Order(x);
}

void Customer::Write(double x){
    checkings.Write(x);
}

void Customer::CloseSavings(){
    savings.CloseAccount();
}

void Customer::OpenSavings(double x){
    savings.OpenAccount(x);
}

void Customer::ShowSavingsInfo(){
    savings.ShowInfo();
}

bool Customer::ShowCheckingStatus(){
    return checkings.ShowStatus();
}

bool Customer::ShowSavingsStatus(){
    return savings.ShowStatus();
}

int main(int argc, const char * argv[]) {
    string choice1;
    vector <Customer> customers;
    Customer activeCustomer;
    string input1;
    string input2;
    
    while(choice1 != "3"){
        bool choice2 = false;
        bool choice3 = false;
        bool choice4 = false;
        bool choice5 = false;
        bool choice6 = false;
        bool choice7 = false;
        cout << "Welcome to the banking program" << endl;
        cout << "Press 1 to log in" << endl;
        cout << "Press 2 to create a new customer" << endl;
        cout << "Press 3 to quit" << endl;
        cin >> choice1;
        while(choice2 == false){
            if(choice1 == "1"){
                string name;
                string pin;
                cout << "Welcome back" << endl;
                cout << "Please enter your name: ";
                cin >> name;
                while(choice7 == false){
                    cout << "Please enter your 4 digit pin: ";
                    cin >> pin;
                    if(pin.length() == 4){
                        if(customers.size() > 0){
                            for(int i = 0; i < customers.size(); i++){
                                if(customers[i].GetName() == name && customers[i].GetPin() == pin && pin.length() == 4){
                                    activeCustomer = customers[i];
                                    choice2 = true;
                                    break;
                                }
                                if(customers[i].GetName() != name && customers[i].GetPin() != pin && i == customers.size() - 1){
                                    cout << "Account not found" << endl;
                                    choice2 = true;
                                    choice3 = true;
                                }
                            }
                            break;
                        }
                        else{
                            cout << "No accounts found" << endl;
                            choice2 = true;
                            choice3 = true;
                            choice7 = true;
                        }
                    }
                    else{
                        cout << "Pin must be 4 digits" << endl;
                    }
                }
            }
            else if(choice1 == "2"){
                string name;
                string pin;
                cout << "Welcome" << endl;
                cout << "Please enter your name: ";
                cin >> name;
                while(choice6 == false){
                    cout << "Please enter your 4 digit pin: ";
                    cin >> pin;
                    if(pin.length() == 4){
                        activeCustomer = Customer(name, pin);
                        choice2 = true;
                        choice6 = true;
                        break;
                    }
                    else{
                        cout << "Pin must be 4 digits" << endl;
                    }
                }
            }
            else if(choice1 == "3"){
            return 0;
            }
        }
        while(choice3 == false){
            cout << "Customer menu for " << activeCustomer.GetName() << ":" << endl;
            if(activeCustomer.ShowCheckingStatus() == false){
                cout << left << setfill('-')<< setw(30);
                cout << "Open checking";
                cout << "oc" << endl;;
            }
            if(activeCustomer.ShowSavingsStatus() == false){
                cout << left << setfill('-')<< setw(30);
                cout << "Open savings";
                cout << "os" << endl;
            }
            if(activeCustomer.ShowCheckingStatus() == true){
                cout << left << setfill('-')<< setw(30);
                cout << "Close checking";
                cout << "cc" << endl;
            }
            if(activeCustomer.ShowSavingsStatus() == true){
                cout << left << setfill('-')<< setw(30);
                cout << "Close savings";
                cout << "cs" << endl;
            }
            if(activeCustomer.ShowCheckingStatus() == true){
                cout << left << setfill('-')<< setw(30);
                cout << "View checking";
                cout << "vc" << endl;
            }
            if(activeCustomer.ShowSavingsStatus() == true){
                cout << left << setfill('-')<< setw(30);
                cout << "View savings";
                cout << "vs" << endl;
            }
            cout << left << setfill('-')<< setw(30);
            cout << "View info";
            cout << "vi" << endl;
            cout << left << setfill('-')<< setw(30);
            cout << "Log out";
            cout << "lo" << endl;
            cin >> input1;
            transform(input1.begin(), input1.end(), input1.begin(), ::tolower);
            if(input1 == "oc"){
                double x;
                cout << "Enter starting balance: " << endl;
                cin >> x;
                activeCustomer.OpenChecking(x);
            }
            else if(input1 == "os"){
                double x;
                cout << "Enter starting balance: " << endl;
                cin >> x;
                activeCustomer.OpenSavings(x);
            }
            else if(input1 == "cc"){
                activeCustomer.CloseChecking();
                cout << "Checking account closed" << endl;
            }
            else if(input1 == "cs"){
                activeCustomer.CloseSavings();
                cout << "Savings account closed" << endl;
            }
            else if(input1 == "vc"){
                while(choice4 == false){
                    cout << "Checking menu for " << activeCustomer.GetName() << ":" << endl;
                    cout << left << setfill('-')<< setw(30);
                    cout << "Deposit";
                    cout << "d" << endl;
                    cout << left << setfill('-')<< setw(30);
                    cout << "Withdraw";
                    cout << "w" << endl;
                    cout << left << setfill('-')<< setw(30);
                    cout << "Write a check";
                    cout << "wc" << endl;
                    cout << left << setfill('-')<< setw(30);
                    cout << "Order more checks";
                    cout << "o" << endl;
                    cout << left << setfill('-')<< setw(30);
                    cout << "Checking info";
                    cout << "ci" << endl;
                    cout << left << setfill('-')<< setw(30);
                    cout << "Return to menu";
                    cout << "r" << endl;
                    cin >> input2;
                    transform(input2.begin(), input2.end(), input2.begin(), ::tolower);
                    if(input2 == "d"){
                        double x;
                        cout << "Enter amount to deposit: " << endl;
                        cin >> x;
                        activeCustomer.Deposit(x);
                    }
                    else if(input2 == "w"){
                        double x;
                        cout << "Enter amount to withdraw: " << endl;
                        cin >> x;
                        activeCustomer.Withdraw(x);
                    }
                    else if(input2 == "wc"){
                        double x;
                        cout << "Enter amount to write check for: " << endl;
                        cin >> x;
                        activeCustomer.Write(x);
                    }
                    else if(input2 == "o"){
                        int x;
                        cout << "Enter amount of checks to order: " << endl;
                        cin >> x;
                        activeCustomer.Order(x);
                    }
                    else if(input2 == "ci"){
                        cout << "Checking info" << endl;
                        activeCustomer.ShowCheckingInfo();
                    }
                    else if(input2 == "r"){
                        choice4 = true;
                        continue;
                    }
                    else{
                        cout << "Invalid selection" << endl;
                    }
                }
            }
            else if(input1 == "vs"){
                while(choice5 == false){
                    cout << "Savings menu for " << activeCustomer.GetName() << ":" << endl;
                    cout << left << setfill('-')<< setw(30);
                    cout << "Savings info";
                    cout << "si" << endl;
                    cout << left << setfill('-')<< setw(30);
                    cout << "Return to menu";
                    cout << "r" << endl;
                    cin >> input2;
                    transform(input2.begin(), input2.end(), input2.begin(), ::tolower);
                    if(input2 == "si"){
                        cout << "Savings info" << endl;
                        activeCustomer.ShowSavingsInfo();
                    }
                    else if(input2 == "r"){
                        choice5 = true;
                        continue;
                    }
                    else{
                        cout << "Invalid selection" << endl;
                    }
                }
            }
            else if(input1 == "vi"){
                activeCustomer.Show();
            }
            else if(input1 == "lo"){
                choice3 = true;
                customers.push_back(activeCustomer);
            }
            else{
                cout << "Invalid selection" << endl;
            }
        }
    }
}
