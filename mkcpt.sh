#! /bin/bash
mkdir $1/$2
for i in {a..h}
do
cp templates/ss.cpp $1/$2/$i.cpp
done