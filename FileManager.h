#pragma once
#include <string>
#include <vector>

namespace FileManager
{
	std::vector<double> readPrices();
	std::vector<std::string> readItems();
	void writePrices(const std::vector<double>& prices);
	void writeItems(const std::vector<std::string>& items);
}
