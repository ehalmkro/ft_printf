# ft_printf

My rendition of C standard library's [printf](http://www.cplusplus.com/reference/cstdio/printf/). Written in accordance with École 42's strict norm, no more than 25 lines in a function block, no more than 5 functions in a .c file, no more than 4 parameters in a function call using only system library functions:
* `malloc `
* `free`
* `exit` 
* and those included in `stdarg.h`

Handles the following specifiers
* `diuUoxX` for integers
* `fF` for decimal floating points
* `csp%` for chars, char strings, pointer addresses and percent 
* `n` for getting the number of characters written so far to a pointed integer

Using the following sub-specifiers
* `-+ #0` for padding
* `*0-9+.*0-9+` for width and precision
* `h hh l ll L` for variable length 

# Grade

**109/100**
