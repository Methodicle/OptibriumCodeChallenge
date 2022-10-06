#pragma once
#include <map>
#include <variant>
#include <iostream>
#include <algorithm>


#define LogVariant(x) std::visit([](const auto& v){ std::cout << v ;}, x);
#define Log(x) std::cout << x;

template<typename T = std::variant<int, std::string, double>>
class PropertyTable
{
public:
	// class with table where it's accessed by row -> column [row][column]
	std::map<std::string, T>& operator[](std::string x) 
	{
		return Data[x];
	}

	// function to add tables - overload operator, deal with different size tables here
	// consider molecules with same name, skip or append a suffix....
	PropertyTable& operator+(PropertyTable& table)
	{
		
		
		return table;
	}


	void AddMolecule(std::map<std::string, T> moleculeRow) {};

	/*
		Here the solution would be to either have an annoying amount of std::cin and allow user entry through the console.
		Or a more elegant solution would be allowing users to submit small csv files or xml files which could be read in and converted to a new column.
	*/
	void AddPropertyColumn() {};


	bool HasMolecule(const std::string& molecule)
	{
		return Data.find(molecule) != Data.end();
	}

	bool MoleculeHasProperty(const std::string& molecule, const std::string& prop)
	{
		return Data[molecule].find(prop) != Data[molecule].end();
	}

	std::map<std::string, T>  GetPropertyColumn(const std::string& propName)
	{
		std::map<std::string, T> propCol;

		// remember to check the col even exists
		for (auto& [molecule, props] : Data)
		{
			for (auto& [prop, value] : props)
			{
				if (prop == propName)
					propCol.emplace(static_cast<std::string>(molecule), value); 
			}
		}

		return propCol;
	}

	void PrintTable()
	{
		for (auto const& [drug, props] : Data)
		{
			Log("Molecule: " + drug + "\t");
			for (auto const& [prop, value] : props)
			{
				Log(prop + ": ");
				LogVariant(value);
				Log("\t");
			}
			Log("\n");
		}
	};
	

	const std::map<std::string, std::map<std::string, T>> GetData()
	{
		return Data;
	}
private:
	std::map<std::string, std::map<std::string, T>> Data;


};

												 
// seperate this into another class/file as I'd say its separete functionality to the above class

// thinking of this incorrectly, I acutally need to get sets for eeither molecule or property. and compare the row/column
												 
template<typename T = std::variant<int, std::string, double>>
std::map<std::string, T> SetUnion(PropertyTable<T> table1, PropertyTable<T> table2, std::string& propName)
{
	auto tab1Col = table1.GetPropertyColumn(propName);
	auto tab2Col = table2.GetPropertyColumn(propName);

	std::map<std::string, T> unionSet = tab1Col;
	for (const auto& [key, value] : tab2Col) 
	{
		// if it exists from tab1 skip if not emplace to map
		if (unionSet.find(key) == unionSet.end())
		{
			unionSet.emplace(key, value);
		}
	}
	
												 
	return unionSet;
};												 
												 
template<typename T = std::variant<int, std::string, double>>
std::map<std::string, T> SetDifference(PropertyTable<T>& table1, PropertyTable<T>& table2, std::string& propName)
{												 
	auto tab1Col = table1.GetPropertyColumn(propName);
	auto tab2Col = table2.GetPropertyColumn(propName);

	std::map<std::string, T> diffSet;
	for (const auto& [key, value] : tab1Col)
	{
		
		if (tab2Col.find(key) == tab2Col.end())
		{
			diffSet.emplace(key, value);
		}
	}

	// do same for any that exist here that don't in tab1
	for (const auto& [key, value] : tab2Col)
	{
		
		if (tab1Col.find(key) == tab1Col.end())
		{
			diffSet.emplace(key, value);
		}
	}


	return diffSet;
};												 
												 
template<typename T = std::variant<int, std::string, double>>
std::map<std::string, T>SetIntersection(PropertyTable<T>& table1, PropertyTable<T>& table2, std::string& propName)
{		
	auto tab1Col = table1.GetPropertyColumn(propName);
	auto tab2Col = table2.GetPropertyColumn(propName);

	std::map<std::string, T> interSet;
	for (const auto& [key, value] : tab1Col)
	{
		// if it exists from tab1 skip if not emplace to map
		if (tab2Col.find(key) != tab2Col.end())
		{
			interSet.emplace(key, value);
		}
	}

	return interSet;
};
