// main.cpp
#include <iostream>
#include <string>
#include <vector>
#include "CustomerFunctions.h"
#include "AdminFunctions.h"
#include "PriceFunctions.h"
#include "FileManager.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

std::vector<double> prices = FileManager::readPrices();
std::vector<string> items = FileManager::readItems();

void print_vending_machine() {
	cout << "Welcome to the vending machine program!" << endl;
	PriceFunctions::print_current_prices();
}
void main_panel() {
	using namespace PriceFunctions;
	using namespace CustomerFunctions;
	using namespace AdminFunctions;

	cout << "Are you an admin or a customer? (admin/customer): ";
	string role;
	cin >> role;

	if (PriceFunctions::toUpperCase(role) == "ADMIN") {
		cout << "Enter the admin key: ";
		string key;
		cin >> key;
		AdminFunctions::admin_panel(key);
		cout << "Here are the updated prices:\n";
		PriceFunctions::print_current_prices();
	}
	else if (PriceFunctions::toUpperCase(role) == "CUSTOMER") {
		cout << "Welcome, customer! Here are the available items and prices:\n";
		PriceFunctions::print_current_prices();
		CustomerFunctions::customer_panel();
	}
	else {
		cout << "Invalid role. Please enter 'admin' or 'customer'." << endl;
	}
}

int main(int argc, char const* argv[])
{
	print_vending_machine();
	main_panel();
	cout << "Thank you for using the vending machine program!" << endl;
	return 0;
}

