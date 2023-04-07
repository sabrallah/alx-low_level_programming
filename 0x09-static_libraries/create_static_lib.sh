#!/bin/bash
#Compile all .c files into .o files
gcc -c *.c
#Create the static library liball.a without index
ar rc liball.a *.o
#Create the index with ranlib
ranlib liball.a
