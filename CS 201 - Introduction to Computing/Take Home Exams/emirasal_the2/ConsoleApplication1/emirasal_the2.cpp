#include <iostream>
#include <string>

using namespace std;

bool budget_check(int budget) {
	if (budget < 0) {
		return false;
	}
	else {
		return true;
	}
}

bool quantity_check (int num1, int num2, int num3) {
	if (num1 < 1 || num2 < 1 || num3 < 1) {
		return false;
	}
	else {
		return true;
	}
}

int sum_price (int num1, int num2, int num3) {
	int total_price = (num1*5) + (num2*10) + (num3*15);
	return total_price;
}

int price_control (int previous_max_price, int current_price, int budget) {
	if (previous_max_price > current_price || current_price > budget) {
		return previous_max_price;
	}
	else {
		return current_price;
	}
}

void maxprice_update (int num1, int num2, int num3, int budget, int & max_price) {
	int current_price = sum_price(num1, num2, num3);
	max_price = price_control(max_price, current_price, budget);
}

int permutations (int num1, int num2, int num3, int budget) {
	int max_price = 0;
	maxprice_update(num1, num2, num3, budget, max_price);
	maxprice_update(num1, num3, num2, budget, max_price);
	maxprice_update(num2, num1, num3, budget, max_price);
	maxprice_update(num2, num3, num1, budget, max_price);
	maxprice_update(num3, num2, num1, budget, max_price);
	maxprice_update(num3, num1, num2, budget, max_price);
	return max_price;
}

void repeat() {
	int budget;
	cout << "Please enter your budget: ";
	cin >> budget;
	if (budget_check(budget)) {
		int num1, num2, num3;
		cout << "Please enter three quantities: ";
		cin >> num1 >> num2 >> num3;
		if (quantity_check(num1, num2, num3)) {
			int result = 0;
			result = permutations(num1, num2, num3, budget);
			if (result == 0) {
				cout << "You cannot afford any of the permutations with these quantities and budget." << endl << endl;
			}
			else {
				int remaining_money = budget - result;
				cout << "You have " << remaining_money << " liras left." << endl << endl;
			}
		}
		else {
			cout << "All quantities must be positive." << endl << endl;
		}
	}
	else {
		cout << "Budget cannot be negative." << endl << endl;
	}
}

int main () {

	repeat();
	repeat();
	cout << "Goodbye!" << endl;
	return 0;
}