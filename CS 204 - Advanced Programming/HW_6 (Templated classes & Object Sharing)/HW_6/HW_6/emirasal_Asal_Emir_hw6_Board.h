#ifndef EMIRASAL_ASAL_EMIR_HW6_BOARD_H
#define EMIRASAL_ASAL_EMIR_HW6_BOARD_H

using namespace std;

template <class Type>
struct cell {
	Type value;
	int owner;

	cell () {
		owner = 0;
	}
};

// r means row, c means column, v means value
template <class Type>
class Board {
private:
	cell<Type> **matrix;
	int rows;
	int columns;
public:
	Board (int r, int c);
	Board (const Board<Type> &copy);
	~Board ();
	void displayBoard();
	void updateBoardCells(int PlayerID, Type v);
	int getPlayerCellsCount(int PlayerID);
	int knowTheOwner(int r, int c);
	// helper member functions:
	void change_cell(int r, int c, int id, Type v);
	int getRows();
	int getColumns();
	void clear_owner(int r, int c);
};

#include "emirasal_Asal_Emir_hw6_Board.cpp"
#endif