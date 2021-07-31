#!/bin/bash

echo 
echo "10 chars"
echo "======================================================================="
time ./client $(pidof server) "`cat texts/10.txt`"

echo 
echo "100 chars"
echo "======================================================================="
time ./client $(pidof server) "`cat texts/100.txt`"
echo

echo 
echo "1000 chars"
echo "======================================================================="
time ./client $(pidof server) "`cat texts/1k.txt`"
echo

# echo 
# echo "10000 chars"
# echo "======================================================================="
# time ./client $(pidof server) "`cat texts/10k.txt`"
# echo

# echo ""
# echo "99999 chars"
# echo "======================================================================="
# time ./client $(pidof server) "`cat texts/99999.txt`"
# echo
