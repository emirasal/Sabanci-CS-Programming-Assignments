// Emir Asal 27933   CS 300 HOMEWORK 1 

#include <iostream>
#include <string>
#include "Quadtree.h"

using namespace std;


int main(){

	QuadTree *my_tree = new QuadTree("test_cases/cities.txt");

	my_tree->print();
	cout << endl;

	cout << "Processing queries.txt" << endl << endl;
	my_tree->search("test_cases/queries1.txt");

	return 0;
}