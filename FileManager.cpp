#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

namespace FileManager
{
	void checkFile(std::string name)
	{
		std::fstream file(name);
		if (!file.is_open())
		{
			std::cout << "File not found. Creating file..." << std::endl;
			file.open(name, std::ios::out);
			file.close();
		}
	}

	std::vector<double> readPrices()
	{
		std::fstream file("prices.txt");
		if (!file.is_open())
		{
			std::cout << "error reading file" << std::endl;
			checkFile("prices.txt");
			return std::vector<double>();
		}
		std::vector<double> prices;
		double price;
		while (file >> price)
		{
			prices.push_back(price);
		}
		return prices;
	}
	std::vector<std::string> readItems()
	{
		std::fstream file("items.txt");
		if (!file.is_open())
		{
			std::cout << "error reading file" << std::endl;
			checkFile("items.txt");
			return std::vector<std::string>();
		}
		std::vector<std::string> items;
		std::string item;
		while (std::getline(file, item))
		{
			items.push_back(item);
		}
		return items;
	}
	void writePrices(const std::vector<double>& prices)
	{
		std::fstream file("prices.txt", std::ios::out);
		if (!file.is_open())
		{
			std::cout << "error writing file" << std::endl;
			checkFile("prices.txt");
			return;
		}
		for (const auto& price : prices)
		{
			file << price << std::endl;
		}
	}
	void writeItems(const std::vector<std::string>& items)
	{
		std::fstream file("items.txt", std::ios::out);
		if (!file.is_open())
		{
			std::cout << "error writing file" << std::endl;
			checkFile("items.txt");
			return;
		}
		for (const auto& item : items)
		{
			file << item << std::endl;
		}
	}
}