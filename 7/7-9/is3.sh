#!/bin/sh

a=0
while [ $a -lt 100 ];
do
	./istrim <input
	a=`expr $a + 1`
done
