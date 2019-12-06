#!/bin/bash

# echo "Compile the single cc file and then run the result if exist"

filename=$1
pos=`expr index "$filename" .`
classname=${filename:0:$pos-1}

javac ${filename}
java ${classname}
