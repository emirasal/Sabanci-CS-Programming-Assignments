#include "emirasal_Asal_Emir_hw3_TwoDLinkedList.h"

TwoDLinkedList::TwoDLinkedList () {
	head = NULL;
}

void TwoDLinkedList::add_row_sorted (string word) {
	node *ptr = head, *previous = NULL;
	// First we need to find the find the corrrect location to add the word.
	while (ptr != NULL && word[0] > ptr->data) {
		previous = ptr;
		ptr = ptr->down;
	}
	// Then we need to check if we have to add the word to the first row.
	if (previous == NULL) {
		// And we need to check if there is a head or the list is empty.
		if (head == NULL) {
			head = new node (word[0]);
			ptr = head;
			for (unsigned int i = 1; i < word.length(); i++) {
				ptr->right = new node (word[i]);
				ptr = ptr->right;
			}
		}
		else {
			// If there exist a head we need to replace the current head.
			node *ex_head = head;
			head = new node (word[0], NULL, ex_head);
			ptr = head;
			for (unsigned int i = 1; i < word.length(); i++) {
				ptr->right = new node (word[i], NULL, ex_head->right);
				ptr = ptr->right;
				ex_head = ex_head->right;
			}
		}
	}
	else {
		// If we are here that means that we need to add the word to the middle or end of the list.
		node *temp = NULL, *prev_column = NULL;
		temp = previous->down;
		previous->down = new node (word[0], NULL, temp);
		prev_column = previous->down;
		previous = previous->right;
		for (unsigned int i = 1; i < word.length(); i++) {
			temp = previous->down;
			previous->down = new node (word[i], NULL, temp);
			prev_column->right = previous->down;
			prev_column = previous->down;
			previous = previous->right;
		}
	}
}

void TwoDLinkedList::displayFullMatrix () {
	node *row = head, *column = NULL;
	while (row != NULL) {
		column = row;
		while (column != NULL) {
			cout << column->data;
			column = column->right;
		}
		cout << endl;
		row = row->down;
	}
}

void TwoDLinkedList::display_row (int pos) {
	// This function displays the row in the given position.
	node *ptr = head;
	// First we need to get to the given row.
	for (int i = 0; i < pos; i++) {
		ptr = ptr->down;
	}
	while (ptr != NULL) {
		cout << ptr->data;
		ptr = ptr->right;
	}
	cout << endl;
}

void TwoDLinkedList::displayFullMatrixReversed () {
	node *ptr = head;
	// First we need to know the number of rows in the 2D List and store it inside row_position variable.
	// So we can start displaying from the last row.
	int row_position = 0;
	while (ptr != NULL) {
		row_position++;
		ptr = ptr->down;
	}
	// i = row_position-1 because the first index is 0.
	for (int i = row_position-1; i >= 0; i--) {
		display_row(i);
	}
}

void TwoDLinkedList::display_rows_starting_with (char ch) {
	node *row = head, *ptr = NULL;
	// With the outer loop we visit the starting point of every row.
	while (row != NULL) {
		if (row->data == ch) {
			ptr = row;
			while (ptr != NULL) {
				cout << ptr->data;
				ptr = ptr->right;
			}
			cout << endl;
		}
		row = row->down;
	}
}

void TwoDLinkedList::display_cols_starting_with(char ch) {
	node *column = head, *ptr = NULL;
	//With the outer loop we visit the starting point of every column.
	while (column != NULL) {
		if (column->data == ch) {
			ptr = column;
			while (ptr != NULL) {
				cout << ptr->data;
				ptr = ptr->down;
				cout << endl;
			}
			cout << endl;
		}
		column = column->right;
	}
}

void TwoDLinkedList::delete_row (int pos) {
	node *ptr = NULL, *temp = head; 
	// If pos is 0 it means that we need to delete the head row and determine the new head.
	if (pos == 0) {
		// First we change the head and then delete the headless row.
		head = head->down;
		ptr = temp->right;
		delete temp;
		while (ptr != NULL) {
			temp = ptr;
			ptr = ptr->right;
			delete temp;
		}
	}
	else {
		node *erasing_pointer;
		ptr = head;
		// This loop will run until we get to the upper row of row to be deleted.
		for (int i = 1; i < pos; i++) {
			ptr = ptr->down;
		}
		// ptr points to the upper row of row to be deleted
		// erasing_pointer points to the row to be deleted.
		erasing_pointer = ptr->down;
		while (ptr != NULL) {
			temp = erasing_pointer;
			erasing_pointer = erasing_pointer->right;
			ptr->down = temp->down;
			delete temp;
			ptr = ptr->right;
		}
	}
}

int TwoDLinkedList::delete_rows_starting_with (char ch) {
	node *ptr = head;
	// pos variable is used to locate the position of the row to be deleted. (Distance from the head node)
	int count = 0, pos = 0;
	while (ptr != NULL) {
		if (ptr->data == ch) {
			ptr = ptr->down;
			delete_row(pos);
			count++;
			// We do not increment the pos here because we are going to delete this row so the distance will not change.
		}
		else {
			// When the character does not match we move to the lower row.
			ptr = ptr->down;
			pos++;
		}
	}
	return count;
}

void TwoDLinkedList::delete_column (int pos) {
	node *ptr = NULL, *temp = head; 
	// If pos is 0 it means that we need to delete the head column and determine the new head.
	if (pos == 0) {
		// First we change the head and then delete the headless column.
		head = head->right;
		ptr = temp->down;
		delete temp;
		while (ptr != NULL) {
			temp = ptr;
			ptr = ptr->down;
			delete temp;
		}
	}
	else {
		node *erasing_pointer;
		ptr = head;
		// This loop will run until we get to the left side of the column to be deleted.
		for (int i = 1; i < pos; i++) {
			ptr = ptr->right;
		}
		// ptr points to the left side of the column to be deleted.
		// erasing_pointer points to the column to be deleted.
		erasing_pointer = ptr->right;
		while (ptr != NULL) {
			temp = erasing_pointer;
			erasing_pointer = erasing_pointer->down;
			ptr->right = temp->right;
			delete temp;
			ptr = ptr->down;
		}
	}
}

int TwoDLinkedList::delete_cols_starting_with (char ch) {
	node *ptr = head;
	// pos variable will be used to locate the position of the column to be deleted. (Distance from the head node)
	int count = 0, pos = 0;
	while (ptr != NULL) {
		if (ptr->data == ch) {
			ptr = ptr->right;
			delete_column(pos);
			count++;
			// We do not increment the pos here because we are going to delete this row so the distance will not change.
		}
		else {
			// When the character does not match we move to the right column.
			ptr = ptr->right;
			pos++;
		}
	}
	return count;
}

void TwoDLinkedList::clear () {
	node *row = head, *temp = NULL, *eraser = NULL;
	while (row != NULL) {
		eraser = row;
		row = row->down;
		while (eraser != NULL) {
			temp = eraser;
			eraser = eraser->right;
			delete temp;
		}
	}
}