#! /bin/bash
#Filename: analysis.sh
#Author:   admirestator <admirestator@gmail.com>
#Comment:  run analysis process.


rm -rf result
if [ $# -ne 1 ]; then
	echo "Error Arguments"
	echo "Usage: $0 logfile"
	exit -1
fi

echo "start analysis..."
echo "get... ip collection from log file..."
./getip.pl $1

echo "analysis ip collection..."
make -j4 && ./count

iconv -c -f GB2312 -t UTF8 <rstdata> result
rm -rf rstdata
echo "finished analysis!"
echo "See 'result' file or the file you had specified!"
