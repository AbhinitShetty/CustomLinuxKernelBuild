#!/bin/sh
filesdir=$1
searchstr=$2
if [ $# -lt 2 ]
then 
	echo Not enough parameters specified
	exit 1
fi 

if [ -d "$filesdir" ]
then 
	X=$( ls "$filesdir" | wc -l )
	Y=$( grep -R "$searchstr" "$filesdir" | wc -l )
	echo The number of files are "$X" and the number of matching lines are "$Y"
else 
	echo "$filesdir" does not represent a directory on the filesystem
	exit 1 
fi
 
