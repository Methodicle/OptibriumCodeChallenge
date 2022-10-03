#include <iostream>
#include "PropertyTable.h"

#define LogVariant(x) std::visit([](const auto& v){ std::cout << v << " "; }, x);;

int main()
{
    PropertyTable table;
    PropertyTable table2;

    table["Test_Drug1"]["property_1"] = std::string("hello1");
    table["Test_Drug1"]["property_2"] = std::string("hello2");
    table["Test_Drug1"]["property_3"] = std::string("hello3");

    table["Test_Drug2"]["property_1"] = 2;
    table["Test_Drug2"]["property_2"] = std::string("hello5");
    table["Test_Drug2"]["property_3"] = std::string("hello6");

    PropertyTable newTable = table + table2;

    LogVariant(table["Test_Drug2"]["property_1"]);

    std::cin.get();
}




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

