#!/bin/bash
touch file1 file2
mkdir dir1
cp file1 file2 dir1
echo hello
echo "the files are copied to dir1 and files are removed from `pwd`" 
rm file1 file2

