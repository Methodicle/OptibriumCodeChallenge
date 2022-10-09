#pragma once
#include <map>
#include <variant>
#include <iostream>
#include <exception>
#include <format>

#include "Utilities.h"


// Table class where access is [row][col]
// 
//
//


template<typename T = std::variant<int, std::string, double>>
class PropertyTable
{
public:
	bool HasMolecule(const std::string& molecule)
	{
		return m_Data.find(molecule) != m_Data.end();
	}

	bool MoleculeHasProperty(const std::string& molecule, const std::string& prop)
	{
		return m_Data[molecule].find(prop) != m_Data[molecule].end();
	}

	std::map<std::string, T>  GetPropertyColumn(const std::string& propName)
	{

		// check if map is empty
		if (m_Data.empty());
			throw std::runtime_error("Supplied no data to table, but tried to get property column.");

		std::map<std::string, T> propCol;

		// remember to check the col even exists
		for (auto& [molecule, props] : m_Data)
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
		// check if map is empty - won't crash but user could wonder nothing prints.
		if (m_Data.empty());
			throw std::runtime_error("Supplied no data to table, but tried to print.");

		for (auto const& [drug, props] : m_Data)
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

	std::map<std::string, T>& operator[](std::string x)
	{
		return m_Data[x];
	}



	// function to add tables - overload operator, deal with different size tables here
	// if two tables have the same molecule and the same property but different values, 
	// I'd error as they're chemical properties and "Usually" constant like solubility and molecular weight
	PropertyTable operator+(PropertyTable& table)
	{
		PropertyTable sumTable; // think there's something wrong here

		for (const auto& [molecule, value] : m_Data)
		{
			sumTable[molecule] = value;
		}

		for (auto& [molecule, props] : table)
		{
			// if property just add the entire row
			if (!sumTable.HasMolecule(molecule))
				sumTable[molecule] = props;
			else
			{
				auto sumTableProps = &sumTable[molecule];

				for (auto& [prop, value] : props) 
				{
					if ( sumTableProps->find(prop) == sumTableProps->end())
					{
						sumTableProps->emplace(prop, value);
					}
					// assumption here is that properties are the same, can be changed or made specific to certain properties, add different handling if values are different in future.
					else if ((*sumTableProps)[prop] != value)
					{
						throw std::runtime_error(std::format("Value for {}'s {} in both tables are different", molecule, prop));
					}
				}
			}
		}

		return sumTable;
	}
	

	// Implemented to iterate through the table without having a method to access m_Data
	auto begin()
	{
		return m_Data.begin();
	}

	auto end()
	{
		return m_Data.end();
	}

	auto find(std::string& molecule)
	{
		return m_Data.find(molecule);
	}

	// --------------------------------------------------------------------------------------------------
	// TODO: 
	//void AddMoleculeRow(std::map<std::string, T> moleculeRow) {};

	/*
		Here the solution would be to either have an annoying amount of std::cin and allow user entry through the console.
		Or a more elegant solution would be allowing users to submit small csv files or xml files which could be read in and converted to a new column.
	*/
	//void AddPropertyColumn() {};

	
private:
	std::map<std::string, std::map<std::string, T>> m_Data;

};
