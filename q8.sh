#!/bin/bash
echo enter a number
read n
i=1
while [ $i -le $n ]
do
echo the number is $i
let i=$i+1
done
