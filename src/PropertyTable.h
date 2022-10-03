#pragma once
#include <map>
#include <variant>
#include <iostream>


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
	PropertyTable& operator+(PropertyTable& table)
	{
		
		
		return table;
	}

	void AddPropertyColumn() {};

	void AddMolecule(std::map<std::string, T> moleculeRow) 
	{
		// add the row here
	};
	
private:
	std::map<std::string, std::map<std::string, T>> Data;


};

