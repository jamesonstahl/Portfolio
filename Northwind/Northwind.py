from sqlite3 import Error
from sqlite3 import Row
from sqlite3 import connect

# All query functions take in a connection to the database and prints the question.
# The runQuery function is called by passing in the connection and the SQL query.
def query1(conn):
    sql = 'SELECT COUNT(*) FROM Customers WHERE Customers.Country = "UK" OR Customers.Country = "USA" OR Customers.Country = "Spain"'
    print("How many customers are in the UK, USA, and Spain?")
    runQuery(conn, sql)


def query2(conn):
    sql = 'SELECT Suppliers.CompanyName, Suppliers.Phone FROM Suppliers WHERE Suppliers.Phone LIKE "(514)%"'
    print("What are the names and phone numbers of suppliers who are in the 514 area code?")
    runQuery(conn, sql)


def query3(conn):
    sql = 'SELECT COUNT(*) FROM Products WHERE (Products.UnitsInStock * Products.UnitPrice) > (Products.UnitsOnOrder  * Products.UnitPrice)'
    print("How many products have a greater value of in-stock items compared to the value of items on order?")
    runQuery(conn, sql)


def query4(conn):
    sql = 'SELECT Products.ProductName FROM "Order Details", Products WHERE "Order Details".OrderID = "10275" AND "Order Details".ProductID = Products.ProductID'
    print("What are the names of the products in order #10275?")
    runQuery(conn, sql)


def query5(conn):
    sql = 'WITH Manager(managerID, num) AS(SELECT Employees.ReportsTo, COUNT(*) FROM Employees GROUP BY(Employees.ReportsTo) HAVING COUNT(*) > 1 ) SELECT Employees.FirstName, Employees.LastName, Manager.num FROM Manager, Employees WHERE Manager.managerID = Employees.EmployeeID'
    print("Who are all the employees who manage others and how many people do they manage?")
    runQuery(conn, sql)


def query6(conn):
    sql = 'SELECT Products.ProductName FROM Products, "Order Details", Orders, Customers WHERE Products.ProductID = "Order Details".ProductID AND "Order Details".OrderID = Orders.OrderID AND Orders.CustomerID = Customers.CustomerID AND Customers.CompanyName = "The Big Cheese" AND "Order Details".Quantity >= 10'
    print(
        'What are the names of the products that were ever ordered by the customer "The Big Cheese" in quantities of 10 or more?')
    runQuery(conn, sql)


def query7(conn):
    sql = 'SELECT SUM(("Order Details".UnitPrice * "Order Details".Quantity) - (("Order Details".UnitPrice * "Order Details".Quantity))*"Order Details".Discount) FROM "Order Details", Orders, Customers WHERE "Order Details".OrderID = Orders.OrderID AND Orders.CustomerID = Customers.CustomerID AND Customers.CompanyName = "Simons bistro" AND Orders.OrderDate LIKE "1997-01-16%"'
    print('What was the final order price for all items ordered by the customer "Simons bistro" on January 16th 1997?')
    runQuery(conn, sql)


def query8(conn):
    sql = 'SELECT Products.ProductName, Products.UnitsInStock FROM Products, "Order Details" WHERE "Order Details".ProductID = Products.ProductID AND "Order Details".Discount >= "0.25" ORDER BY Products.UnitsInStock DESC LIMIT 1'
    print(
        "Which product that was ever sold at a discount of 25% or more has the most units in stock (and how many units are in stock)?")
    runQuery(conn, sql)


def query9(conn):
    sql = 'SELECT "Order Details".OrderID, Customers.CompanyName, SUM(("Order Details".UnitPrice * "Order Details".Quantity) * "Order Details".Discount), SUM(("Order Details".UnitPrice * "Order Details".Quantity) - (("Order Details".UnitPrice * "Order Details".Quantity))*"Order Details".Discount), SUM("Order Details".UnitPrice * "Order Details".Quantity) FROM "Order Details", Orders, Customers WHERE "Order Details".OrderID = Orders.OrderID AND Orders.CustomerID = Customers.CustomerID GROUP BY("Order Details".OrderID) ORDER BY(SUM(("Order Details".UnitPrice * "Order Details".Quantity)*"Order Details".Discount))DESC LIMIT 1'
    print(
        "What is the name of the company that had the largest discount on any order, how much was that discount, how much did the company pay minus the discount, and how much would they have paid without the discount?")
    runQuery(conn, sql)


def query10(conn):
    sql = 'SELECT Suppliers.SupplierID, Suppliers.CompanyName, SUM(Products.UnitsOnOrder) FROM Suppliers, Products WHERE Suppliers.SupplierID = Products.SupplierID GROUP BY (Suppliers.SupplierID) HAVING SUM(Products.UnitsOnOrder) >= 100'
    print("Who are the suppliers whose products have 100 units or more on order?")
    runQuery(conn, sql)


# Prints out menu with list of queries
def menu():
    menu = """
        1. Query 1 
        2. Query 2 
        3. Query 3 
        4. Query 4 
        5. Query 5 
        6. Query 6 
        7. Query 7 
        8. Query 8 
        9. Query 9 
        10. Query 10
    """
    print(menu)


# Function takes in the user inputted query selection and a connection to the database and
# calls the desired query function
def selection(query, conn):
    if (query == "1"):
        query1(conn)
    elif (query == "2"):
        query2(conn)
    elif (query == "3"):
        query3(conn)
    elif (query == "4"):
        query4(conn)
    elif (query == "5"):
        query5(conn)
    elif (query == "6"):
        query6(conn)
    elif (query == "7"):
        query7(conn)
    elif (query == "8"):
        query8(conn)
    elif (query == "9"):
        query9(conn)
    elif (query == "10"):
        query10(conn)
    else:
        print("Please enter a valid input")


# Function takes in the connection to the database and the SQL query to be executed.
# Prints out all resulting rows of the desired query and also prints out the SQL query
def runQuery(conn, sql):
    cursor = conn.cursor()
    cursor.execute(sql)
    rows = cursor.fetchall()
    for row in rows:
        print(*row)
    print(sql)
    print()

# Attempts to establish a connection to the database. If successful, calls the menu function and
# Prompts the user to input a query number until '-1' is inputted to end the program.
# Passes the query number to the selection function for the query to be executed.
# Outputs an error if needed. Closes the connection at the end of the program
def main():
    conn = None
    pathToDB = "full path to downloaded database file"
    try:
        conn = connect(pathToDB)
        conn.row_factory = Row
        menu()
        query = input("Choose a query to execute (-1 to quit): ")
        while (query != "-1"):
            selection(query, conn)
            query = input("Choose a query to execute (-1 to quit): ")
    except Error as e:
        print(f"Error opening database {e}")
    finally:
        if conn:
            conn.close()


main()
