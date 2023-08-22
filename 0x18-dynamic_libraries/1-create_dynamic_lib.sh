#!/bin/bash

# Compile all .c files into object files
gcc -Wall -Werror -Wextra -pedantic -c *.c

# Create the dynamic library liball.so
gcc -shared -o liball.so *.o

# Clean up object files
rm *.o
