#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "strutils.h"
using namespace std;

string get_the_name (string qr, ifstream &in) {
	string s, current_qr, word;
	string name = "";
	while (getline(in, s)) {
		istringstream input(s);
		input >> current_qr;
		if (current_qr == qr) {
			while (input >> word) {
				name += word;
				name += " ";
			}
			in.clear();
			in.seekg(0);
			return name.substr(0,name.length()-1);
		}
	}
	in.clear();
	in.seekg(0);
	return "boylebiseYYok";
}

double get_the_price (string qr, ifstream &in) {
	double price;
	string s, current_qr;
	while (getline(in, s)) {
		istringstream input(s);
		input >> current_qr;
		if (current_qr == qr) {
			input >> price;
		}
	}
	in.clear();
	in.seekg(0);
	return price;
}

void print_and_sum (string name, int amount, double price, double &price_sum) {
	int length = name.length() + 5;
	double price_multiplied = price * amount;
	cout << name << " * " << setw(2) <<amount << setw(36-length) << price_multiplied << endl; 
	price_sum += price_multiplied;
}

int main () {
	string filename1, filename2, filename3;
	ifstream namelist, pricelist, shoplist;

	cout << "Please enter a filename for QR database: ";
	cin >> filename1;
	cout << endl;
	namelist.open(filename1.c_str());
	while (namelist.fail()) {
		namelist.close();
		cout << "The QR file does not exists";
		cout << endl;
		cout << "Please enter a filename for QR database: ";
		cin >> filename1;
		cout << endl;
		namelist.open(filename1.c_str());
	}
	
	cout << "Please enter a filename for Price database: ";
	cin >> filename2;
	cout << endl;
	pricelist.open(filename2.c_str());
	while (pricelist.fail()) {
		pricelist.close();
		cout << "The Price file does not exists";
		cout << endl;
		cout << "Please enter a filename for Price database: ";
		cin >> filename2;
		cout << endl;
		pricelist.open(filename2.c_str());
	}

	cout << "Please enter a filename for your shopping list: ";
	cin >> filename3;
	shoplist.open(filename3.c_str());
	cout << endl;
	
	string qr, shopliststring, name; 
	double price, price_sum = 0;
	int amount;
	while (getline(shoplist, shopliststring)) {
		istringstream shopinput(shopliststring);
		shopinput >> qr >> amount;
		ToUpper(qr);
		name = get_the_name(qr, namelist);
		if (name != "boylebiseYYok") {
			price = get_the_price(qr, pricelist);
			print_and_sum(name, amount, price, price_sum);
		}
	}
	cout << endl;
	double VAT = price_sum * 0.18;
	cout << "VAT(18%):" << setw(27) << VAT << endl;
	cout << "_______________________________________" << endl;
	cout << "Total:" << setw(30) << price_sum + VAT << endl;
	return 0;
}