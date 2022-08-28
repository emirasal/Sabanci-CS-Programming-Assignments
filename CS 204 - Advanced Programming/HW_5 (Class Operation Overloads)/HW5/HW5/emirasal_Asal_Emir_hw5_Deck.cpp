#include "emirasal_Asal_Emir_hw5_Deck.h"

Deck::Deck () {
	Cards = NULL;
	size = 0;
}

Deck::Deck (const Deck &copy) {
	Cards = new Card [copy.size];
	size = copy.size;
	for (int i = 0; i < size; i++) {
		Cards[i].name = copy.Cards[i].name;
		Cards[i].energy = copy.Cards[i].energy;
	}
}

Deck::~Deck () {
	delete [] Cards;
	Cards = NULL;
	size = 0;
}

ostream & operator << (ostream & os, const Deck & deck) {
	int size = deck.getSize();
	for (int i = 0; i < size; i++) {
		os << i+1 << ": " << deck.getName(i) << " - " << deck.getEnergy(i) << endl;
	}
	return os;
}

Deck Deck::operator + (const Card rhs) const {
	Deck new_deck;
	new_deck.Cards = new Card [size+1];
	for (int i = 0; i < size; i++) {
		new_deck.Cards[i].name = this->Cards[i].name;
		new_deck.Cards[i].energy = this->Cards[i].energy;
	}
	//At the bottom we add the new card (size = last index of dynamic array)
	new_deck.Cards[size].name = rhs.name;
	new_deck.Cards[size].energy = rhs.energy;

	new_deck.size = size+1;
	return new_deck;
}

Deck operator + (const Deck & lhs, const Deck & rhs) {
	Deck new_deck (lhs);
	new_deck += rhs;
	return new_deck;
}

const Deck & Deck::operator += (const Deck & rhs) {
	Card *new_cards;
	new_cards = new Card [size + rhs.size];
	//first we need to add the lhs and then rhs
	// int i will be used until the size of the summed cards.
	int i = 0;
	for (; i < size; i++) {
		new_cards[i].name = Cards[i].name;
		new_cards[i].energy = Cards[i].energy;
	}
	// int k will be used to track the the rhs cards.
	int k = 0;
	for (; i < size + rhs.size; i++) {
		new_cards[i].name = rhs.Cards[k].name;
		new_cards[i].energy = rhs.Cards[k].energy;
		k++;
	}
	Cards = new_cards;
	size = size + rhs.size;
	return *this;
}

Deck Deck::operator - (int num_to_be_removed) const {
	Deck new_deck;
	// First we need to determine the new size of the deck
	new_deck.size = size - num_to_be_removed;
	new_deck.Cards = new Card [new_deck.size];
	if (new_deck.size > 0) {
		// We will skip the first num_to_be_removed elements in lhs and then assign the remainings to our new deck.
		for (int i = 0; i < new_deck.size; i++) {
			new_deck.Cards[i].name = Cards[i+num_to_be_removed].name;
			new_deck.Cards[i].energy = Cards[i+num_to_be_removed].energy;
		}
	}
	else {
		// We need to fix the size of the new deck because it could be negative.
		new_deck.size = 0;
	}
	return new_deck;
}

const Deck & Deck::operator = (const Deck & rhs) {
	// We need to check for self assignment.
	if (this != &rhs) {
		// First we get rid of the old lhs and then assign the new Deck.
		delete [] this->Cards;
		size = 0;
		*this += rhs;
	}
	return *this;
}

Card & Deck::operator [] (int i) const {
	return this->Cards[i];
}

int Deck::totalEnergy () const {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += Cards[i].energy;
	}
	return sum;
}

bool operator == (const Deck & lhs, const Deck & rhs) {
	if (lhs.totalEnergy() == rhs.totalEnergy()) {
		return true;
	}
	return false;
}

bool operator < (const Deck & lhs, const Deck & rhs) {
	if (lhs.totalEnergy() < rhs.totalEnergy()) {
		return true;
	}
	return false;
}

bool operator > (const Deck & lhs, int rhs) {
	if (lhs.getSize() > rhs) {
		return true;
	}
	return false;
}

bool operator <= (const Card & lhs, const Deck & rhs) {
	int deck_size = rhs.getSize();
	for (int i = 0; i < deck_size; i++) {
		if (rhs.getName(i) == lhs.name && rhs.getEnergy(i) == lhs.energy) {
			return true;
		}
	}
	return false;
}

string Deck::getName (int i) const {
	return Cards[i].name;
}

int Deck::getEnergy (int i) const {
	return Cards[i].energy;
}

int Deck::getSize () const {
	return size;
}