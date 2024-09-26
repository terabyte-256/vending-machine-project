// PriceFunctions.cpp
#include "PriceFunctions.h"
#include <iostream>
#include <vector>
#include <algorithm>

extern std::vector<double> prices;
extern std::vector<std::string> items;

namespace PriceFunctions
{
	std::string toUpperCase(const std::string& str) {
		std::string result = str;
		std::transform(result.begin(), result.end(), result.begin(), ::toupper);
		return result;
	}

	void print_current_prices() {
		using namespace std;
		cout << "Current items and prices\n";
		cout << "items: ";
		for (const auto& item : items) {
			cout << item << " ";
		}
		cout << "\nprices: ";
		for (const auto& price : prices) {
			cout << price << " ";
		}
		cout << endl;
	}

	void edit_prices() {
		using namespace std;
		cout << "What item would you like to change/add: " << endl;
		string request;
		cin >> request;
		bool existing = false;
		for (const auto& item : items) {
			if (toUpperCase(request) == toUpperCase(item)) {
				existing = true;
			}
		}
		if (existing) {
			cout << "Would you like to replace the price of " << request <<
				" or create a new item and price? (modify/new) ";
			string answer;
			cin >> answer;
			if (toUpperCase(answer) == "MODIFY") {
				cout << "Enter the new price for " << request << ": " << endl;
				double new_price;
				cin >> new_price;
				for (size_t i = 0; i < items.size(); ++i) {
					if (toUpperCase(items[i]) == toUpperCase(request)) {
						prices[i] = new_price;
						cout << "Price updated successfully." << endl;
						return;
					}
				}
			}
			else if (toUpperCase(answer) == "NEW") {
				cout << "Enter the new price for " << request << ": " << endl;
				double new_price;
				cin >> new_price;
				items.push_back(request);
				prices.push_back(new_price);
				cout << "New item and price added successfully." << endl;
				return;
			}
			else {
				cout << "Invalid option" << endl;
				return;
			}
		}
		cout << "Enter the new price for " << request << ": " << endl;
		double new_price;
		cin >> new_price;
		items.push_back(request);
		prices.push_back(new_price);
		cout << "New item and price added successfully." << endl;
		return;
	}
}