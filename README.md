# Minicell

Minicell is a mini csv engine that transforms .csv files with unresolved equations into a .csv file with resolved equations.

## Type support

Minicell supports strings and integers only.

For equation purposes:

- int + int | int - int | int \* int | int / int => int or divide by zero error
- string + int | int + string | string + string => string
- any -/\* string | string -/\* any => error

## Equations

Equations support operators +-/\* and begin with =, they can refer to cells in the form (CellCol A-ZZ)(CellRow 0-(INT_MAX - 1)). They can also point to other equations resulting in possible cycles which should correctly error.

## Errors

Error handling should not impede on the output, instead when an error occurs inside a cell, replace the contents with ###ERROR### where "ERROR" is the error type.
