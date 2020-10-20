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

//Returns the account status
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

//Checking constructor assigns a random account number and sets default values for the other variables
Checking::Checking(){
    srand(static_cast<unsigned int>(time(nullptr)));
    numberChecks = 10;
    number = (rand() % 5000) + 1;
    status = false;
}

//Closes account by setting status to false and balance to 0
void Checking::CloseAccount(){
    status = false;
    balance = 0;
}

//Opens account with the balance being the parameter
void Checking::OpenAccount(double x){
    status = true;
    balance = x;
}

//Prints out the users checking account information
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

//Deposits amount passed in to the checking account balance
void Checking::Deposit(double x){
    balance += x;
}

//Withdraws amount passed in from the checking account balance if the balace is not negative
void Checking::Withdraw(double x){
    if((balance - x) >= 0){
        balance -= x;
    }
    else{
        cout << "Insufficient funds" << endl;
    }
}

//Increases number of check by the passed in value
void Checking::Order(int x){
    numberChecks += x;
}

//Writes a check by subtracting the amount from the balance and decreases number of checks
void Checking::Write(double x){
    if((balance - x) >= 0){
        balance -= x;
        numberChecks -= 1;
    }
    else{
        cout << "Insufficient funds" << endl;
    }
}

//Returns the status of the checking account
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

//Savings constructor assigns a random account number and sets default values for the other variables
Savings::Savings(){
    srand(static_cast<unsigned int>(time(nullptr)));
    number = (rand() % 5000) + 5001;
    status = false;
}

//Closes account by setting status to false and balance to 0

void Savings::CloseAccount(){
    status = false;
    balance = 0;
}

//Opens account with the balance being the parameter
void Savings::OpenAccount(double x){
    status = true;
    balance = x;
    matureBalance = balance + (balance * interestRate);
}

//Prints out the users checking account information
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

//Returns the status of the checking account
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
//Default constructor is empty
Customer::Customer(){
    
}

//Contructor assigns name and pin
Customer::Customer(string a, string b){
    name = a;
    pin = b;
}

//Calls ShowStatus function from the savings class to determine if the account is open or closed
void Customer::CheckSavings(){
    if(savings.ShowStatus() == true){
        cout << "Savings account is open" << endl;
    }
    else{
        cout << "Savings account is closed" << endl;
    }
}

//Calls ShowStatus function from the checking class to determine if the account is open or closed
void Customer::CheckChecking(){
    if(checkings.ShowStatus() == true){
            cout << "Checking account is open" << endl;
        }
        else{
            cout << "Checking account is closed" << endl;
        }
}

//Prints out users info and the info of their accounts if they are open
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

//Returns customer name
string Customer::GetName(){
    return name;
}

//Returns customer pin number
string Customer::GetPin(){
    return pin;
}

//Closes the customers checking account by calling CloseAccount function from the checking class
void Customer::CloseChecking(){
    checkings.CloseAccount();
}

//Opens the customers checking account by calling OpenAccount function from the checking class
void Customer::OpenChecking(double x){
    checkings.OpenAccount(x);
}

//Calls the ShowInfo function from the checking class to print out the customers checking account info
void Customer::ShowCheckingInfo(){
    checkings.ShowInfo();
}

//Calls the Deposit function from the checking class to deposit an amount specified by the customer
void Customer::Deposit(double x){
    checkings.Deposit(x);
}

//Calls the Withdraw function from the checking class to withdraw an amount specified by the customer
void Customer::Withdraw(double x){
    checkings.Withdraw(x);
}

//Calls the Order function from the checking class to order an amount of checks specified by the customer
void Customer::Order(int x){
    checkings.Order(x);
}

//Calls the Write function from the checking class to write a check with the amount specified by the customer
void Customer::Write(double x){
    checkings.Write(x);
}

//Closes the customers savings account by calling CloseAccount function from the savings class
void Customer::CloseSavings(){
    savings.CloseAccount();
}

//Opens the customers savings account by calling OpenAccount function from the savings class
void Customer::OpenSavings(double x){
    savings.OpenAccount(x);
}

//Calls the ShowInfo function from the savings class to print out the customers savings account info
void Customer::ShowSavingsInfo(){
    savings.ShowInfo();
}

//Returns the status of a customers checking account by calling the ShowStatus function from the checking class
bool Customer::ShowCheckingStatus(){
    return checkings.ShowStatus();
}

//Returns the status of a customers savings account by calling the ShowStatus function from the savings class
bool Customer::ShowSavingsStatus(){
    return savings.ShowStatus();
}

int main(int argc, const char * argv[]) {
    string choice1;
    vector <Customer> customers;
    Customer activeCustomer;
    string input1;
    string input2;
    
    //Creates bank menu that can be traversed by the user
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
            //User inputs name and pin to determine if they have an existing account
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
            //User inputs name and pin to create a new account
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
        //Creates customer bank interface that is determined by what accounts the customer has open
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
                //Checking account menu
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
                //Savings account menu
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

