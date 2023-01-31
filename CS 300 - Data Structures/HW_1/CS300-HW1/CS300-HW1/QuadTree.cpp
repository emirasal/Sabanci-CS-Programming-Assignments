#include "QuadTree.h"

QuadTree::QuadTree(string filename){

	root = NULL;

	// Reading cities.txt
	ifstream cities_file;
	cities_file.open(filename);

	cities_file >> max_x >> max_y;

	// Inserting data from cities.txt to our tree
	string name;
	int x_coordinate, y_coordinate;
	while (!cities_file.eof()){
		cities_file >> name >> x_coordinate >> y_coordinate;
		// We insert the city in to our tree if coordinates are in the area.
		insert(name, x_coordinate, y_coordinate);
	}
	cities_file.close();
}


void QuadTree::insert(string name, int x, int y){
	// if tree is empty
	if(root == NULL) {
		root = new city_node(name, x, y);
	} else {
		// node pointer & father pointer
		city_node *p = root;
		while (p != NULL){

			if (x < p->x){
				if(y < p->y) {
					if (p->SW != NULL) p = p->SW;
					else {
						p->SW = new city_node(name, x, y);
						break;
					}
				}
				else {
					if(p->NW != NULL) p = p->NW;
					else {
						p->NW = new city_node(name, x, y);
						break;
					}
				}
			} else {
				if(y < p->y) {
					if (p->SE != NULL) p = p->SE;
					else {
						p->SE = new city_node(name, x, y);
						break;
					}
				}
				else {
					if (p->NE != NULL) 	p = p->NE;
					else {
						p->NE = new city_node(name, x, y);
						break;
					}
				}
			}
		}
	}
}


void QuadTree::pretty_print(city_node *r){
	if (r != NULL) {
		cout << r->name << endl;
		pretty_print(r->SE);
		pretty_print(r->SW);
		pretty_print(r->NE);
		pretty_print(r->NW);
	}
}

void QuadTree::print(){
	pretty_print(root);
}

double QuadTree::distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Public search
void QuadTree::search(string filename){

	ifstream quaries_file;
	quaries_file.open(filename);

	
	string my_string; // This will be converted to integer below
	while(!quaries_file.eof()){
		// reading x
		quaries_file >> my_string;
		query_x = stoi(my_string.substr(0,my_string.size()-1)); // getting rid of the comma
		// reading y
		quaries_file >> my_string;
		query_y = stoi(my_string.substr(0,my_string.size()-1));
		// reading radius
		quaries_file >> query_radius;

		// Searching begins here for every row
		// First we need to reset our vectors for the new row.
		visited_cities.clear();
		searched_cities.clear();
		visit(root);
		
		if (visited_cities.size() == 0) cout << "<None>";
		else {
			// We left out the last element because it will not have a comma at the end
			for (unsigned int i = 0; i<visited_cities.size()-1; i++){
				cout << visited_cities[i] << ", ";
			}
			cout << visited_cities[visited_cities.size()-1];
		}
		cout << endl;
		for (unsigned int i = 0; i<searched_cities.size()-1; i++){
			cout << searched_cities[i] << ", ";
		}
		cout << searched_cities[searched_cities.size()-1] << endl << endl;

	}
	quaries_file.close();
}

//Private Search Function
void QuadTree::visit(city_node *r){
	searched_cities.push_back(r->name);
	if(distance(r->x, r->y, query_x, query_y) <= query_radius) {
		visited_cities.push_back(r->name);
	}
	
	if (r->SE != NULL && is_on_SE(r)) visit(r->SE);
	if (r->SW != NULL && is_on_SW(r)) visit(r->SW);
	if (r->NE != NULL && is_on_NE(r)) visit(r->NE);
	if (r->NW != NULL && is_on_NW(r)) visit(r->NW);
	
}

bool QuadTree::is_on_SE(city_node *city){
	int circle_right_x = query_x + query_radius;
	int circle_down_y = query_y - query_radius;

	// First we check if the right side of the circle is on east & down side of the circle is on south
	if (circle_right_x >= city->x && circle_down_y < city->y) {
		// One more special check: if center of the circle is on opposite side(NW) and distance from its center too far away we need to return false.
		if(query_x < city->x && query_y > city->y && distance(query_x, query_y, city->x, city->y) > query_radius){
			return false;
		}
		return true;
    }
	return false;
}
bool QuadTree::is_on_SW(city_node *city){
	int circle_left_x = query_x - query_radius;
	int circle_down_y = query_y - query_radius;

	// First we check if the left side of the circle is on west & down side of the circle is on south
	if (circle_left_x < city->x && circle_down_y < city->y){
		// One more special check: if center of the circle is on opposite side(NE) and distance from its center too far away we need to return false.
		if(query_x > city->x && query_y > city->y && distance(query_x, query_y, city->x, city->y) > query_radius){
			return false;
		}
		return true;
	}
	return false;
}
bool QuadTree::is_on_NE(city_node *city){
	int circle_right_x = query_x + query_radius;
	int circle_up_y = query_y + query_radius;

	// First we check if the right side of the circle is on east & up side of the circle is on north
	if (circle_right_x >= city->x && circle_up_y >= city->y){
		// One more special check: if center of the circle is on opposite side(SW) and distance from its center too far away we need to return false.
		if (query_x < city->x && query_y < city->y && distance(query_x, query_y, city->x, city->y) > query_radius){
			return false;
		}
		return true;
	}
	return false;
}
bool QuadTree::is_on_NW(city_node *city){
	int circle_left_x = query_x - query_radius;
	int circle_up_y = query_y + query_radius;

	// First we check if the left side of the circle is on west & up side of the circle is on north
	if (circle_left_x < city->x && circle_up_y >= city->y) {
		// One more special check: if center of the circle is on opposite side(SE) and distance from its center too far away we need to return false.
		if (query_x > city->x && query_y < city->y && distance(query_x, query_y, city->x, city->y) > query_radius){
			return false;
		}
		return true;
	}
	return false;
}
