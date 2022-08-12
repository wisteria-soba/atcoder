#! /bin/bash
mkdir $1 
mkdir $1/build
for i in `seq 1 $2`
do
cp templates/ss.cpp $1/$i.cpp
done