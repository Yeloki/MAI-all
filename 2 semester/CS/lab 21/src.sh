#!/bin/bash

function full_path {

	for line in $(ls $1)
	do
	if [ -d "$1/$line" ]
	then
		full_path "$1/$line"
	fi
	done

	echo "$1/"
}

need_help=0

if [[ "$1" == "?" ]]
then
	need_help=1
	shift
fi

if [ $need_help -eq 0 ]
then
	if [ -n "$1" ]
	then
		if [ -d "$1" ]
		then
			full_path "$(realpath $1)"
		else
			echo "Error: No such directory"
			need_help=1
		fi
	else
		full_path "$(pwd)"
	fi
fi

if [ $need_help -eq 1 ]
then
	echo "Using: src.sh {?} {optional: path to existing dir}"
fi
