#! /bin/bash
mkdir $1 
for i in `seq 1 $2`
do
cp templates/ss.cpp $1/$i.cpp
done