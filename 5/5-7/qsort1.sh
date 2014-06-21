#!/bin/sh

a=0
while [ $a -lt 1000 ];
do
	./qsort1 <input
	a=`expr $a + 1`
done
