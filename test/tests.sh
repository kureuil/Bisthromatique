#!/bin/bash
## tests.sh for Bistromathique in /home/person_l
## 
## Made by Louis Person
## Login   <person_l@epitech.net>
## 
## Started on  Mon Nov  3 11:45:34 2014 Louis Person
## Last update Mon Nov  3 14:32:36 2014 Louis Person
##

function test {
    local BASE="0123456789"
    local OP_BASE="()+-*/%"
    if [[ -z $4 ]]
    then
	BASE=$4
    fi
    if [[ -z $5 ]]
    then
	OP_BASE=$5
    fi
    echo -n $1
    echo -n " should return "
    echo $3
    echo $1 | ./calc 0123456789 "()+-*/%" $2
    echo ""
}

make re

echo ""
echo "========[ BEGIN TESTS ]========"
echo ""

# Addition tests
echo "--------[  ADDITION   ]--------"
echo ""
test "1+1" 3 2
test "1+9" 3 10
test "-1+11" 5 10
test "-15+10" 6 -5
test "-50+-50" 7 -100
test "50+-50" 6 0
test "-0+0" 4 0

# Subtraction tests
echo "-------[ SUBTRACTION  ]--------"
echo ""
test "1-1" 3 0
test "1-10" 4 -9
test "15-10" 5 5
test "-50-50" 6 -100
test "-50--50" 7 0
test "50--50" 6 100

# Syntax errors tests

echo "========[  END TESTS  ]========"
echo ""
