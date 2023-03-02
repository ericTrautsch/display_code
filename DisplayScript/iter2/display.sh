#!/bin/bash
export TTEST="doesthiswork?"

gcc -o allocate allocate.c
# https://stackoverflow.com/questions/27941013/how-to-call-a-c-program-inside-bash-script-and-store-its-return-value-to-a-varia
output=`./allocate`

echo
echo $TTEST
echo
echo $output

python display.py $output

gcc -o deallocate deallocate.c
./deallocate $output