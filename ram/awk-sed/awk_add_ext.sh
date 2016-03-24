#!/bin/bash
dir=$1
echo "directory - $1"

if [ -d $dir ];
then
    echo "directory exists.."
    touch "/tmp/temp_cmds.sh"
    chmod +x "/tmp/temp_cmds.sh" 
    #for i in `ls`; do echo "mv $i $i.txt" ; done
    find  $dir -type f | awk '{print "mv " $0 " " $0".txt"}' >> "/tmp/temp_cmds.sh"
    /tmp/temp_cmds.sh
    cat /tmp/temp_cmds.sh
    rm "/tmp/temp_cmds.sh"
else
    echo "dir $1 does not exists.."
fi

