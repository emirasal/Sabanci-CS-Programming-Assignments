#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct city_node {

	string name;
	int x, y;
	city_node * NW;
	city_node * NE;
	city_node * SW;
	city_node * SE;

	city_node(string N, int X, int Y){
		name = N;
		x = X;
		y = Y;
		NW = NULL;
		NE = NULL;
		SW = NULL;
		SE = NULL;
	}

};

class QuadTree {
private:
	city_node * root;
	int max_x, max_y;
	vector<string> visited_cities; // For storing the visited cities during the search
	vector<string> searched_cities;
	int query_x, query_y, query_radius; // storing the data taken from queries.txt
	void insert(string name, int x, int y);
	double distance(int x1, int y1, int x2, int y2);
	void pretty_print(city_node *r);
	void visit(city_node *r);
	// Functions for finding our way during search
	bool is_on_SE(city_node *city);
	bool is_on_SW(city_node *city);
	bool is_on_NE(city_node *city);
	bool is_on_NW(city_node *city);
public:
	QuadTree(string filename);
	void print();
	void search(string filename);
};