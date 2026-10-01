#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include "strutils.h"

using namespace std;

struct Product{
    string qr, name;
	double price;
	int amount;
};


class Products{

private:
    vector<Product> item_list;
    vector<Product> shop_list;

public:
    Products();
    Products(const Products & p);
    vector<Product> get_item_list() const;
    vector<Product> get_shop_list() const;


    // you are going to implement these member functions
    void read_files(ifstream & qr, ifstream & price);
    bool find(string qr_code);
    bool findInShopList(string qr_code);
    void add_item(string qr, int amount);
    void edit_item(string qr, int amount);
    void remove_item(string qr);
    void printCurrentReceipt();
    void printCurrentReceiptAscending();
    void printCurrentReceiptDescending();

};