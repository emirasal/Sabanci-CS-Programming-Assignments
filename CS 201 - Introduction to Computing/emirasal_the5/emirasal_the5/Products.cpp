#include "Products.h"


Products::Products(){

}

vector<Product> Products::get_item_list()const{
    return item_list;
}
vector<Product> Products::get_shop_list()const{
    return shop_list;
}

Products::Products(const Products & p){
    item_list = p.get_item_list();
    shop_list = p.get_shop_list();
}

void Products::read_files(ifstream & qr, ifstream & price) {
	string line1, line2, qr_code, word, name, correct_qr;
	Product p;
	double dprice;
	while (getline(qr, line1)) {
		istringstream input(line1);
		input >> correct_qr;
		ToUpper(correct_qr);
		p.qr = correct_qr;
		while (input >> word) {
			name += word;
			name += " ";
		}
		p.name = name.substr(0,name.length()-1);
		while (getline(price, line2)) {
			istringstream input(line2);
			input >> qr_code;
			ToUpper(qr_code);
			input >> dprice;
			if (qr_code == correct_qr) {
				p.price = dprice;
				break;
			}
		}
		price.seekg(0);
		item_list.push_back(p);
		name = "";
	}
	qr.seekg(0);
}

bool Products::find(string qr_code) {
	for (int i = 0; i < item_list.size(); i++) {
		if (qr_code == item_list[i].qr) {
			return true;
		}
	}
	return false;
}

bool Products::findInShopList (string qr_code) {
	for (int i = 0; i < shop_list.size(); i++) {
		if (qr_code == shop_list[i].qr) {
			return true;
		}
	}
	return false;
}

void Products::add_item (string qr, int amount) {
	Product new_item;
	new_item.qr = qr;
	new_item.amount = amount;
	for (int i = 0; i < item_list.size(); i++) {
		if (qr == item_list[i].qr) {
			new_item.name = item_list[i].name;
			new_item.price = item_list[i].price;
		}
	}
	shop_list.push_back(new_item);
}

void Products::edit_item (string qr, int amount) {
	for (int i = 0; i < shop_list.size(); i++) {
		if (qr == shop_list[i].qr) {
			shop_list[i].amount = amount;
		}
	}
}

void Products::remove_item (string qr) {
	for (int i = 0; i < shop_list.size(); i++) {
		if (qr == shop_list[i].qr) {
			int last_index = shop_list.size()-1;
			shop_list[i] = shop_list[last_index];
			shop_list.pop_back();
		}
	}
}

void print_vector (vector <Product> v) {
	int length, amount;
	string name;
	double price, price_multiplied, price_sum = 0, VAT;
	for (int i = 0; i < v.size(); i++) {
		name = v[i].name;
		length = name.length();
		amount = v[i].amount;
		price = v[i].price;
		price_multiplied = price * amount;
		cout << name << " * " << setw(2) <<amount << setw(31-length) << price_multiplied << endl;
		price_sum += price_multiplied;
	}
	VAT = price_sum * 0.18;
	cout << endl;
	cout << "VAT(18%):" << setw(27) << VAT << endl;
	cout << "_______________________________________" << endl;
	cout << "Total:" << setw(30) << price_sum + VAT << endl;
}


void Products::printCurrentReceipt() {
	print_vector(shop_list);
}


void Products::printCurrentReceiptAscending() {
	vector <Product> ascending = shop_list;
	Product temp;
	int min_index, min_price_multiplied;
	int size = ascending.size();
	double price_multiplied;
	for (int k = 0; k < size-1; k++) {
		min_index = k;
		min_price_multiplied = ascending[k].price * ascending[k].amount;
		for (int i = k+1; i < size; i++) {
			price_multiplied = ascending[i].price * ascending[i].amount;
			if (price_multiplied < min_price_multiplied) {
				min_index = i;
				min_price_multiplied = price_multiplied;
			}
			else if (price_multiplied == min_price_multiplied && ascending[i].name < ascending[min_index].name) {
				min_index = i;
			}
		}
		temp = ascending[k];
		ascending[k] = ascending[min_index];
		ascending[min_index] = temp;
	}
	print_vector(ascending);
}


void Products::printCurrentReceiptDescending() {
	vector <Product> descending = shop_list;
	Product temp;
	int max_index, max_price_multiplied;
	int size = descending.size();
	double price_multiplied;
	for (int k = 0; k < size-1; k++) {
		max_index = k;
		max_price_multiplied = descending[k].price * descending[k].amount;
		for (int i = k+1; i < size; i++) {
			price_multiplied = descending[i].price * descending[i].amount;
			if (price_multiplied > max_price_multiplied) {
				max_index = i;
				max_price_multiplied = price_multiplied;
			}
			else if (price_multiplied == max_price_multiplied && descending[i].name > descending[max_index].name) {
				max_index = i;
			}
		}
		temp = descending[k];
		descending[k] = descending[max_index];
		descending[max_index] = temp;
	}
	print_vector(descending);
}