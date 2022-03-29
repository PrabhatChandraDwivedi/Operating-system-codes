#!/bin/bash
let m=1
count=10
var=0
while [ $m -le $count ]
do
k=$m
	while [ $k -gt $var ]
	do
	 let  k=$k-1
	  echo -n  $k
	done
echo -e "\n"
let m=$m+1
done
