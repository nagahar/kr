#!/bin/sh

a=0
while [ $a -lt 100 ];
do
	./foptest2
	a=`expr $a + 1`
done
