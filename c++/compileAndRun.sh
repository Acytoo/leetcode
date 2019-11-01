#!/bin/bash

# echo "Compile the single cc file and then run the result if exist"

filename=$1
pos=`expr index "$filename" .`
outputname=''${filename:0:$pos-1}'.out'

g++ ${filename} -o ${outputname}
'./'${outputname}''
