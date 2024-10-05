// PriceFunctions.cpp
#include "PriceFunctions.h"
#include "FileManager.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

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
		std::cout << std::endl;
		const int itemCount = items.size();
		std::cout << std::left << std::setw(19) << "Items"
	  << std::right << std::setw(7) << "Prices" << "\n";
		std::cout << std::string(30, '-') << "\n";
		if (itemCount > 0) {
			for (int i = 0; i < itemCount; ++i) {
				std::cout << std::left << std::setw(15) << items[i]
		<< std::right << std::setw(7) << "$" << std::fixed << std::setprecision(2) << prices[i] << std::endl;
			}
		}
		else {
			std::cout << "No items found." << std::endl;
		}
		std::cout << "\n" << std::endl;
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
				break;
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
			FileManager::writeItems(items);
			prices.push_back(new_price);
			FileManager::writePrices(prices);
			cout << "New item and price added successfully." << endl;
	}
}