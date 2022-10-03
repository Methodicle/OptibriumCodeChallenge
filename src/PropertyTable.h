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

	void AddMolecule(std::map<std::string, T> moleculeRow) {};

	/*
		Here the solution would be to either have an annoying amount of std::cin and allow user entry through the console.
		Or a more elegant solution would be allowing users to submit small csv files or xml files which could be read in and converted to a new column.
	*/
	void AddPropertyColumn() {};

	const std::map<std::string, std::map<std::string, T>> GetData()
	{
		return Data;
	}
	
private:
	std::map<std::string, std::map<std::string, T>> Data;


};

