#!/bin/bash

# Compile each .c file into an object file
gcc -c *.c

# Create the static library
ar rcs liball.a *.o
