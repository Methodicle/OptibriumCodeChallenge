###Notes for Improvment/Requested Feature Discussions

## Explanation of some implementation choices
 - When it came to combination of tables (using overloaded operator in this case), the table exercise requested a table with molecules and associated properties. 
 For the first implementation i took this to mean if two tables were added and had the same molecule and property then the program should throw an error as the properties for given molecules should remain constant. 
 This behaviour would be quite easy to deal with in future implementations, either giving user choice over which one to pick or adding a suffix/prefix to the values showing which table they came from.


## Considerations for adding new property columns at run-time

 - Simpliest but crude solution, have user console input that looks at each molecule for a property and requests a value or gives and option to skip.
 - Give a file path with xml/csv that has molecule types/properties which is read and adds to table, give option to add new molecules if there are ones don't exist in the table yet, but do in the file.
 - UI with visual representation of the table, where when edited it updates the table either when a button is pressed ("ok", "confirm" etc.) or as the context shifts on the UI to a new cell.
