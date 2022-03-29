#!/bin/bash
i=0
j=0
k=4
m=0
counter=4
for((i=0;i<4;i++)) ;
do
	for((j=0;$j<=$i;j++));
	do
	  echo -n "*"
	done

echo -e "\n"
done
for((k=4;k>=0;k--)) ;
do
        for((m=0;$m<=$k;m++));
        do
          echo -n "*"
        done

echo -e "\n"
done

