#!/bin/bash

if [ ! -f $1 ]
then
    echo "Binary not found. Aborted."
    exit 42
fi

if [ $? -ne 0 ]
then
    echo "No tests found. Aborted."
    exit 42
fi

for i in `ls $2/*.cmd`; do
    res=${i/.cmd/.res}
    if [ ! -f $res ]
    then
	echo "Result file not found. Aborted."
	exit 42
    fi
    base=$(sed '1q;d' $i)
    size=$(sed '2q;d' $i)
    ops=$(sed '3q;d' $i)
    calc=$(sed -n '4,$ p' $i)
    tmp=$(mktemp --suffix '_bistro')
    echo $calc | $1 $base $ops $size > $tmp
    diff=$(diff -y $res $tmp)
    if [ $? -ne 0 ]
    then
	echo -e "-----\n\e[91mFAILED\e[0m\n"
	echo -e "calc\t->\t$calc\n"
	echo -e $diff
	exit 42
    else
	echo -e "\e[92mOK\e[0m"
    fi
done
exit 0
