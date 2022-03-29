#!/bin/bash
echo enter a number
read y
revnum=0
while [ $y -gt 0 ]
do
let n=$y%10
revnum=$(($revnum*10+$n))
let y=y/10
done
echo $revnum
