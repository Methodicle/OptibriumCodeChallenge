# Notes for Improvement/Requested Feature Discussions

## Explanation of some implementation choices
 - When it came to the combination of tables, the table exercise requested a table with molecules and associated properties. 
 For the first implementation I took this to mean if two tables were added and had the same molecule and property then the program should throw an error as the properties for given molecules should remain constant. 
 This behavior would be quite easy to deal with in future implementations.


## Considerations for adding new property columns at run-time

 - Simplest but crude solution, have user console input that looks at each molecule for a property and requests a value or gives and option to skip.
 - Give a file path with xml/csv that has molecule types/properties which is read and adds to table, give option to add new molecules if there are ones that don't exist in the table yet, but do in the file.
 - UI with visual representation of the table, where when edited it updates the table either when a button is pressed ("ok", "confirm" etc.) or as the context shifts on the UI to a new cell.
