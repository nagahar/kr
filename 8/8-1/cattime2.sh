#!/bin/sh

a=0
while [ $a -lt 100 ];
do
	./cat2 <input
	a=`expr $a + 1`
done
