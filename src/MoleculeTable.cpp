#include <iostream>
#include "PropertyTable.h"

#define LogVariant(x) std::visit([](const auto& v){ std::cout << v ;}, x);
#define Log(x) std::cout << x;

void PrintTable(PropertyTable<std::variant<int, std::string, double>>& table);

int main()
{
    PropertyTable defaultTable;

    defaultTable["Paracetamol"]["Solubility"]               = 4.97;
    defaultTable["Paracetamol"]["Molecular Weight"]         = 151;

    defaultTable["Caffeine"]["Solubility"]                  = 5.05;
    defaultTable["Caffeine"]["Molecular Weight"]            = 194;

    defaultTable["Indomethacin"]["Solubility"]              = 0.4;
    defaultTable["Indomethacin"]["Molecular Weight"]        = 358;

    defaultTable["Trimethoprim"]["Solubility"]              = 3.14;
    defaultTable["Trimethoprim"]["Molecular Weight"]        = 290;


    PrintTable(defaultTable);

    std::cin.get();
}

void PrintTable(PropertyTable<std::variant<int, std::string, double>>& table)
{   
    for (auto const& [drug, props] : table.GetData())
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




/*
    TODO:
      -  use templates to allow different types of property tables to be added the class, can only be numeric or text type.
      - class for a property column
      - class for full table
      - think about memory optimisations when allocating the table, its needs to be able to have varying sizes
      - if two tables are added with different columns merge and have empty entires for the missing values
      - Set unions, set differences and intersections


      - for adding enw property columns at run time, have a add function that takes a column name and asks if its text /  numeric then run through all the current rows and ask if you'd like to a set a value.
      - Possibly read in an intial data structre and create coloumns based form that - check when read in if the data read is tect or numeric.

    Explain that I ideally wanted to create templated property columns that would allow bools and other data types to be used as long as they have the right operators.
    

 */

