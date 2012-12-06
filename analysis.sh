#! /bin/bash
#Filename: analysis.sh
#Author:   admirestator <admirestator@gmail.com>
#Comment:  run analysis process.

rm -rf rstdata

if [ $# -ne 2 ]; then
	echo "Error Arguments"
	echo "Usage: $0 logfile"
	exit -1
fi

echo "start analysis..."
echo "get... ip collection from log file..."
./getip.pl $1

echo "analysis ip collection..."
make && ./count

echo "finished analysis!"
echo "See 'rstdata' file or the file you had specified!"
