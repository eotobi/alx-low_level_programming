#!/bin/bash

# Compile .c files into object files
gcc -c *.c

# Create static library using ar
ar rcs liball.a *.o

# Cleanup - remove the object files
rm *.o

echo "Static library liball.a created successfully."
