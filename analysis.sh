#! /bin/bash
#Filename: analysis.sh
#Author:   admirestator <admirestator@gmail.com>
#Comment:  run analysis process.

rm -rf rstdata

echo "start analysis..."
echo "get... ip collection from log file..."
./getip.pl access.log

echo "analysis ip collection..."
make
./count

echo "finished analysis!"
echo "See 'rstdata' file or the file you had specified!"
