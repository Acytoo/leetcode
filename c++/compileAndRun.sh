#!/bin/bash

# echo "Compile the single cc file and then run the result if exist"

fullpath=$1
filename=$(basename -- "$fullpath")
outputname=''$filename'.out'

g++ -std=c++17 ${fullpath} -o ${outputname}
'./'${outputname}''

# delete compiled file
rm ${outputname}

