#include <iostream>
#include <string>

using namespace std;

struct node {
	char data;
	node *right;
	node *down;

	node () {
		right = NULL;
		down = NULL;
	}
	node (char ch) {
		data = ch;
		right = NULL;
		down = NULL;
	}
	node (char ch, node *r, node *d) {
		data = ch;
		right = r;
		down = d;
	}
};

class TwoDLinkedList {
private:
	node *head;
	void display_row (int pos);
	void delete_row (int pos);
	void delete_column (int pos);
public:
	TwoDLinkedList ();
	void add_row_sorted (string line);
	void displayFullMatrix ();
	void displayFullMatrixReversed ();
	void display_rows_starting_with (char ch);
	void display_cols_starting_with (char ch);
	int delete_rows_starting_with (char ch);
	int delete_cols_starting_with (char ch);
	void clear ();
};