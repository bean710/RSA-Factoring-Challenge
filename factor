#!/usr/bin/env bash
#Calculate factors from file

while read NUMBER
do
	FACS=($( factor "$NUMBER" ))
	echo "$NUMBER=$(( NUMBER / ${FACS[1]} )) * ${FACS[1]}"
done < $1
