#include <string>
using namespace std;

// Parametric Constructor to allocate the memory for the board
template <class Type>
Board<Type>::Board (int r, int c) {
	rows = r;
	columns = c;
	matrix = new cell<Type>*[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new cell<Type>[columns];
	}
}

template <class Type>
Board<Type>::Board (const Board<Type> &copy) {
	// First we need to create the memory location for the new board
	rows = copy.rows;
	columns = copy.columns;
	matrix = new cell<Type>*[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new cell<Type>[columns];
	}
	// And then we assign the cells one by one
	for (int i = 0 ; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = copy.matrix[i][j];
		}
	}
}

template <class Type>
Board<Type>::~Board() {
	for (int i = 0; i < rows; i++) {
		delete [] matrix[i];
		matrix[i] = NULL;
	}
	delete [] matrix;
	matrix = NULL;
}


template <class Type>
void Board<Type>::displayBoard () {
	cout << "Displaying the board: Each cell is shown as tuple (CURRENT OWNER ID, VALUE): " << endl;
	for (int i = 0; i < columns; i++) {
		cout << "\t" << i;
	}
	cout << endl;
	for (int k = 0; k < rows; k++) {
		cout << k << "\t";
		for (int m = 0; m < columns; m++) {
			cout << "(" << matrix[k][m].owner << "," << matrix[k][m].value << ")" << "\t";
		}
		cout << endl;
	}
}

template <class Type>
void Board<Type>::updateBoardCells(int PlayerID, Type v) {
	// We go over every cell with two for loops
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j].owner == PlayerID) {
				matrix[i][j].value = v;
			}
		}
	}
}

template <class Type>
int Board<Type>::getPlayerCellsCount(int PlayerID) {
	int count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j].owner == PlayerID) {
				count++;
			}
		}
	}
	return count;
}

template <class Type>
int Board<Type>::knowTheOwner(int r, int c) {
	return (matrix[r][c].owner);
}

// additional helper functions:
// this function changes the single cell in the given row and column
template <class Type>
void Board<Type>::change_cell(int r, int c, int id, Type v) {
	matrix[r][c].owner = id;
	matrix[r][c].value = v;
}

template <class Type>
int Board<Type>::getRows(){
	return rows;
}

template <class Type>
int Board<Type>::getColumns(){
	return columns;
}

template <class Type>
void Board<Type>::clear_owner(int r, int c) {
	matrix[r][c].owner = 0;
}