#!/bin/bash

for i in {1..30}
do
	x=1
	while [ $x -le $i ]
	do
		./f $x $i >>out &
	 	x=$(( $x + 1 ))
	done
done