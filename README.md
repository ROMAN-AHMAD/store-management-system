Store Management System
Overview
The Store Management System is a C++ console application that allows dealers, customers, and employees to manage stock in a store. The application provides functionalities such as adding new products, displaying stock, refilling stock, withdrawing stock, and removing products. The system uses file handling to store and manage product data persistently.

Features
Dealer Menu:

Add new product
Display stock
Refill stock
Remove an item
Customer Menu:

Purchase product
Display stock
Employee Menu:

Display stock
Refill stock
Getting Started
Prerequisites
C++ compiler (e.g., g++)
C++ standard library
Usage
Dealer Menu
Access Dealer Menu:

Enter the dealer password: open.
Options:

Add New Product: Enter product name, price, and quantity.
Display Stock: View all available products and their quantities.
Refill Stock: Add more stock to an existing product.
Remove an Item: Remove a product from the stock.
Customer Menu
Access Customer Menu:

Options:

Purchase Product: Enter product name and quantity to purchase.
Display Stock: View all available products and their quantities.
Employee Menu
Access Employee Menu:

Enter the employee password: open.
Options:

Display Stock: View all available products and their quantities.
Refill Stock: Add more stock to an existing product.
Functions and Methods
Class Stock
Attributes:
char productName[20]: Name of the product.
float price: Price of the product.
int quantity: Quantity of the product.
Methods:
void getProductDetails(): Input product name, price, and quantity.
void getProductDetailsWithQuantity(): Input product name and quantity.
void showProductDetails(): Display product details.
int checkStock(char productName[30]): Check if a product exists.
void withdrawStock(int qty): Withdraw specified quantity of stock.
void refillStock(int qty): Refill specified quantity of stock.
Global Functions
void addNewProduct(): Add new products to the stock.
void withdrawProduct(): Withdraw products from the stock.
void displayStock(): Display all products in the stock.
void refillProduct(): Refill products in the stock.
void removeProduct(): Remove products from the stock.
Notes
Make sure to run the program in an environment that supports conio.h for input handling.
The stock data is stored in a binary file shop.dat for persistence.
