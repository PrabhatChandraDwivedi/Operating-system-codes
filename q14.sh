#!/bin/bash

read -p "enter a number :" y
sum=0

while [ $y -gt 0 ]
do
let n=$y%10
let sum=$sum+$n
let y=$y/10
done
echo "$sum"
