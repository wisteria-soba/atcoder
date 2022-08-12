#! /bin/bash
mkdir $1/$2
mkdir $1/$2/build
for i in {a..h}
do
cp templates/ss.cpp $1/$2/$i.cpp
done