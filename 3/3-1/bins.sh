#!/bin/sh

a=0
while [ $a -lt 100 ];
do
	./2binsearch
	a=`expr $a + 1`
done
