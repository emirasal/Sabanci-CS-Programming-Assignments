#ifndef EMIRASAL_ASAL_EMIR_HW6_PLAYER_H
#define EMIRASAL_ASAL_EMIR_HW6_PLAYER_H

using namespace std;

template <class Type>
class Player {
private:
	Board<Type> &myBoard;
	int id;
	static int next_id;
public:
	Player (Board<Type> &B);
	bool updateCell (int r, int c, Type v);
	void updateMyCells (Type v);
	bool unclaimOwnership (int r, int c);
	void unclaimOwnerships ();
};
template <class Type>
int Player<Type>::next_id = 1;

#include "emirasal_Asal_Emir_hw6_Player.cpp"
#endif