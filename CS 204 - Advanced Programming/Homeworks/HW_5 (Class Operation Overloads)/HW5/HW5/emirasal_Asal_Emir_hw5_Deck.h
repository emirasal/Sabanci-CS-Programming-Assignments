#include <string>

using namespace std;

struct Card {
	string name;
	int energy;
};

class Deck {
private:
	Card *Cards;
	int size;
public:
	Deck();
	Deck(const Deck &copy);
	~Deck();

	Deck operator + (const Card rhs) const; // Deck + Card
	const Deck & operator += (const Deck & rhs);
	Deck operator - (int num_to_be_removed) const;
	const Deck & operator = (const Deck & rhs);
	Card & operator [] (int i) const;
	//helper functions:
	string getName (int i) const;
	int getEnergy (int i) const;
	int totalEnergy () const;
	int getSize () const;
};

//free functions:
ostream & operator << (ostream & os, const Deck & deck);
Deck operator + (const Deck & lhs, const Deck & rhs); // Deck + Deck
bool operator == (const Deck & lhs, const Deck & rhs);
bool operator < (const Deck & lhs, const Deck & rhs);
bool operator > (const Deck & lhs, int rhs);
bool operator <= (const Card & lhs, const Deck & rhs);