#pragma once
#include "PropertyTable.h"

// Functions to do set arithmetic on Tables, separate file as it shouldn't be included in the table class itself

// Function to get a set Union for a given property, returns a map of <molecule, prop_value>
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

// Function to get a set Difference for a given property, returns a map of <molecule, prop_value>
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

// Function to get a set Intersection for a given property, returns a map of <molecule, prop_value>
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

