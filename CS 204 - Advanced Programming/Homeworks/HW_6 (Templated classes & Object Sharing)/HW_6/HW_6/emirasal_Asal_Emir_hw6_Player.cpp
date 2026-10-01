#include <string>
using namespace std;

// Constructor
template <class Type>
Player<Type>::Player(Board<Type> & B) : myBoard(B) {
	id = next_id;
	next_id++;
}

// change_cell board member function updates the cell in the given row and column
template <class Type>
bool Player<Type>::updateCell(int r, int c, Type v) {
	if (myBoard.knowTheOwner(r, c) == id || myBoard.knowTheOwner(r, c) == 0) {
		myBoard.change_cell(r, c, id, v);
		return true;
	}
	return false;
}

template <class Type>
void Player<Type>::updateMyCells(Type v) {
	int rows = myBoard.getRows();
	int columns = myBoard.getColumns();
	// We go over every cells and if the id matches value of that cell is updated.
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (myBoard.knowTheOwner(i, j) == id) {
				myBoard.change_cell(i, j, id, v);
			}
		}
	}
}

// clear_owner board member function sets the owner to 0 in the given row and column.
template <class Type>
bool Player<Type>::unclaimOwnership(int r, int c) {
	if (myBoard.knowTheOwner(r, c) == id) {
		myBoard.clear_owner(r, c);
		return true;
	}
	return false;
}

template <class Type>
void Player<Type>::unclaimOwnerships() {
	int rows = myBoard.getRows();
	int columns = myBoard.getColumns();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (myBoard.knowTheOwner(i, j) == id) {
				myBoard.clear_owner(i, j);
			}
		}
	}
}