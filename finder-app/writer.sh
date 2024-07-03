#!/bin/bash 

writefile=$1	# Full path (incl. file name)
writestr=$2	# String to be written in the file

if [ $# -ne 2 ]
then
	echo Not enough parameters specified
	exit 1
fi 


FILE=$( basename "$writefile" )
DIR=$( dirname "${writefile}")
if [ -d $DIR ]
then 
	echo $DIR created
	touch $writefile
	echo $writestr > $writefile
else 
	mkdir -p $DIR
	touch $writefile
        echo $writestr > $writefile
fi


if [ ! -f $filename ]
then 
	echo No file created
	exit 1
fi
