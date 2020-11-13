# Banking Program
This banking program consists of 3 main parts. A Customer class which contains all of the customers information, account classes which 
hold the banking info, and main which runs the menu’s needed to manipulate the customer’s accounts. 

Account is an abstract base class. It has 3 data
members: the account balance, the account number, and the account status which is either “open” or “closed”. Every account has a function to close the account, to
open the account, and to show the account information. 

A Checking account derives from Account. It has an additional data member, numberChecks. The initial number 
of checks is 10. A checking account number is a random number between 1-5000. A checking account has functions to depositmoney, withdraw money, order more checks, 
and to write a check. The show function shows the account number, the account balance, the account status, and the number of checks.

A savings account derives from Account. It has two additional data members,interestRate and matureBalance. The interest rate is 3%. The mature balance is how
much money will be in the Savings account after a year of interest has accrued. A checking account number is a random number between 5001-10000. The show
function shows the account number, the account balance, the account status, and the Mature Balance.

A customer has a name and a pin (4 digit code). The customer has a savings account object and a checking account object. 
The Customer also has a function to check if they have an open checking account and a function to check if they have an open savings account. 

This program is menu driven. The initial menu allows the user to either create a new customer, “log in” as an existing
customer, or quit option. To log in the user needs to enter the name or pin of an existing customer.
When logged in to the customer, the customer menu shows a log out option, open
checking (if not open), open savings(if not open), close checking (if not closed), close savings (if
not closed), View Checking (if open), View Savings (if open), and a Print Customer Info item.
The checking account menu allows you to deposit, withdraw, write a check, order more
checks, and print checking account info. The savings account menu allows you to print the Savings information and return to the
customer menu.
