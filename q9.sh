#!/bin/bash
a=$1
b=$2
echo "Enter 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division operation"
read x
case $x in
	1) echo `expr $1 + $2`;;
	2) echo `expr $1 - $2`;;
	3) echo `expr $1 \* $2`;;
	4) echo `expr $1 \/ $2`;;
	*) echo "you entered wrong option";;
esac


