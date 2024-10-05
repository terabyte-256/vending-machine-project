// CustomerFunctions.cpp
#include "CustomerFunctions.h"
#include <iostream>
#include <vector>
#include <string>

extern std::vector<double> prices;
extern std::vector<std::string> items;

namespace CustomerFunctions
{
	void customer_panel() {
		using namespace std;
		cout << "Enter the number of the item you wish to purchase: " << endl;
		int index;
		cin >> index;
		if (items.size() < index) {
			cout << "Invalid selection";
			customer_panel();
		}
		double amount_entered = 0.0;
		double coin_prices[5] = { 0.01, 0.05, 0.10, 0.25, 1.00 };
		while (amount_entered < prices[index-1]) {
			cout << "Enter coin amount to put in machine (0.01, 0.05, 0.10, 0.25, or 1.00): " << endl;
			double temp;
			cin >> temp;
			bool valid_coin = false;
			for (double coin : coin_prices) {
				if (temp == coin) {
					amount_entered += temp;
					valid_coin = true;
				}
			}
			if (!valid_coin) {
				cout << "Invalid coin amount" << endl;
			}
			else {
				cout << "Total amount entered " << amount_entered << endl;
			}
		}
		cout << "Enjoy your " << items[index - 1] << endl;
	}
}

