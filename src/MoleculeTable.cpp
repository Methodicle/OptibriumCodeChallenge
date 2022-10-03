#include <iostream>

#define Log(x) std::cout << x << std::endl;

int main()
{
    Log("hello");


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

