#! /bin/bash
#Filename: analysis.sh
#Author:   admirestator <admirestator@gmail.com>
#Comment:  run analysis process.


echo "start analysis..."
echo "get... ip collection from log file..."
./getip.pl

echo "analysis ip collection..."
./count

echo "finished analysis!"
echo "See 'rstdata' file or the file you had specified!"
