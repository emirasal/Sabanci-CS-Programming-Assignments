#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Products.h"
using namespace std;

int menu () {
	int choice;
	cout << "MENU" << endl;
	cout << "1. Add item to the shopping list" << endl;
	cout << "2. Delete item from the shopping list" << endl;
	cout << "3. Edit the amount of existing item" << endl;
	cout << "4. Print current receipt" << endl;
	cout << "5. Print current receipt in order" << endl;
	cout << "6. Print current receipt in reverse order" << endl;
	cout << "7. Exit" << endl;
	cout << "---" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}

int main () {
	string qr_filename, price_filename;
	ifstream qr, price;
	cout << "Please enter a filename for QR database: ";
	cin >> qr_filename;
	cout << endl;
	qr.open(qr_filename.c_str());
	while (qr.fail()) {
		qr.close();
		cout << "The QR file does not exists";
		cout << endl;
		cout << "Please enter a filename for QR database: ";
		cin >> qr_filename;
		cout << endl;
		qr.open(qr_filename.c_str());
	}

	cout << "Please enter a filename for Price database: ";
	cin >> price_filename;
	price.open(price_filename.c_str());
	while (price.fail()) {
		price.close();
		cout << endl;
		cout << "The Price file does not exists";
		cout << endl;
		cout << "Please enter a filename for Price database: ";
		cin >> price_filename;
		price.open(price_filename.c_str());
	}
	Products myProducts;
	myProducts.read_files(qr, price);

	int choice = menu();
	string qr_code;
	int amount;
	while (choice!= 7) {
		if (choice == 1) {
			cout << "Please enter the QR code to add: ";
			cin >> qr_code;
			ToUpper(qr_code);
			if (myProducts.find(qr_code)) {
				if (!myProducts.findInShopList(qr_code)) {
					cout << "Please enter the amount to add: ";
					cin >> amount;
					if (amount >= 1 && amount <= 25) {
						myProducts.add_item(qr_code, amount);
					}
					else {
						cout << "Invalid amount, try again" << endl;
					}
				}
				else {
					cout << "Item is already in the shoplist, if you want to edit the amount please choose option 3" << endl;
				}
			}
			else {
				cout << "Invalid QR code, try again" << endl;
			}
		}
		else if (choice == 2) {
			cout << "Please enter the QR code to delete: ";
			cin >> qr_code;
			ToUpper(qr_code);
			if (myProducts.findInShopList(qr_code)) {
				myProducts.remove_item(qr_code);
			}
			else {
				cout << "Shoplist does not contain given QR code" << endl;
			}
		}
		else if (choice == 3) {
			cout << "Please enter the QR code to edit: ";
			cin >> qr_code;
			ToUpper(qr_code);
			if (myProducts.findInShopList(qr_code)) {
				cout << "Please enter the amount to edit: ";
				cin >> amount;
				if (amount >= 1 && amount <= 25) {
					myProducts.edit_item(qr_code, amount);
				}
				else {
					cout << "Invalid amount, try again" << endl;
				}
			}
			else {
				cout << "Shoplist does not contain the given QR code." << endl;
			}
		}
		else if (choice == 4) {
			myProducts.printCurrentReceipt();
			cout << endl;
		}
		else if (choice == 5) {
			myProducts.printCurrentReceiptAscending();
			cout << endl;
		}
		else if (choice == 6) {
			myProducts.printCurrentReceiptDescending();
			cout << endl;
		}
		choice = menu();
	}
	cout << "Goodbye!" << endl;
	return 0;
}