#!/bin/bash

echo "This script is: "
[[ $- == *i* ]] && echo 'Interactive' || echo 'Not-interactive'
echo "==========================================="
echo "cmd: ls"
ls
echo "==========================================="
echo "cmd: touch test.txt"
touch test.txt
echo "test file created"
echo "==========================================="
echo "cmd: sleep 5"
sleep 5
echo "==========================================="
echo "cmd: rm test.txt"
rm test.txt
echo "test file removed"
