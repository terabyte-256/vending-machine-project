// AdminFunctions.cpp
#include "AdminFunctions.h"
#include "PriceFunctions.h"
#include <iostream>
#include <string>

const std::string secret_key = "admin";

namespace AdminFunctions
{
	void admin_panel(const std::string& key) {
		using namespace std;
		if (PriceFunctions::toUpperCase(key) == PriceFunctions::toUpperCase(secret_key)) {
			PriceFunctions::print_current_prices();
			PriceFunctions::edit_prices();
		}
		else {
			cout << "Invalid login" << endl;
			return;
		}
	}
}