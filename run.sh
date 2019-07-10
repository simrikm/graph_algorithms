#!/bin/bash


#making the make file 
make

#cleaning generated object files 
make clean

echo -e "\ngenerating graph and graph algorithms are being runned...."

#running the executable file
graph

echo -e "RUNNING COMPLETE....\n"
