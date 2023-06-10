#!/bin/bash

# Compile each .c file into an object file
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

# Create the static library
ar rcs liball.a *.o
