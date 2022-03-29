#!/bin/bash
check=$1
if [ -e $check ];
then
echo file is there
else
echo file is not there
fi


