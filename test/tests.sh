#!/bin/sh
## tests.sh for Bistromathique in /home/person_l
## 
## Made by Louis Person
## Login   <person_l@epitech.net>
## 
## Started on  Mon Nov  3 11:45:34 2014 Louis Person
## Last update Mon Nov  3 11:45:48 2014 Louis Person
##

function test {
    echo $1
    echo $1 | ./calc 0123456789 "()+-*/%" $2
    echo ""
}

make re

echo ""
echo "========[ BEGIN TESTS ]========"
echo ""

test "999+1" 5
test "1000-1" 6

echo "========[  END TESTS  ]========"
echo ""
