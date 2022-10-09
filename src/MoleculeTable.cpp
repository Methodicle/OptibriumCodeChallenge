#include <iostream>
#include <exception>

#include "PropertyTable.h"
#include "SetArithmetic.h"
#include "Utilities.h"


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

    PropertyTable defaultTable2;

    defaultTable2["Paracetamol"]["Solubility"] = 4.97;
    defaultTable2["Paracetamol"]["Molecular Weight"] = 151;
    defaultTable2["Paracetamol"]["Chemical Formula"] = "C8H9NO2";

    defaultTable2["Caffeine2"]["Solubility"] = 5.05;
    defaultTable2["Caffeine2"]["Molecular Weight"] = 194;

    defaultTable2["Indomethacin"]["Solubility"] = 0.4;
    defaultTable2["Indomethacin"]["Molecular Weight"] = 358;

    defaultTable2["Trimethoprim2"]["Solubility"] = 3.14;
    defaultTable2["Trimethoprim2"]["Molecular Weight"] = 290;

    try {
        auto sumTab = defaultTable + defaultTable2;
        sumTab.PrintTable();
    }
    catch (std::runtime_error& e)
    {
        Log(e.what());
    }
    
    // just quick test for some errors
    try {
        PropertyTable defaultTable3;
        defaultTable3.PrintTable();
    }
    catch (std::runtime_error& e)
    {
        Log(e.what());
    }
    

    // test the arithmetic
    try {
        std::string propName = "Solubility";
        auto unionTab = SetUnion(defaultTable, defaultTable2, propName);

        auto intersectTab = SetIntersection(defaultTable, defaultTable2, propName);

        auto diffTab = SetDifference(defaultTable, defaultTable2, propName);
    }
    catch (std::runtime_error& e)
    {
        Log(e.what());
    }
    
    
    std::cin.get();
}




/*
    TODO:
      - for adding new property columns at run time, have a add function that takes a column name and asks if its text /  numeric then run through all the current rows and ask if you'd like to a set a value.
      - Possibly read in an intial data structre and create coloumns based form that - check when read in if the data read is tect or numeric.

    Explain that I ideally wanted to create templated property columns that would allow bools and other data types to be used as long as they have the right operators.
    

 */

