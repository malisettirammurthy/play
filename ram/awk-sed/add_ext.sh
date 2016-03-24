#!/bin/bash
dir=$1
echo "directory - $1"

if [ -d $1 ];
then
    echo "directory exists.."
    for i in `ls`; do echo "mv $i $i.txt" ; done
else
    echo "dir $1 does not exists.."
fi

