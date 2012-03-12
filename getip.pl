#! /usr/bin/perl -w
#Filename: getip.pl
#Author:   admirestator <admirestator@gmail.com>
#Comment:  get ip from log files;

$file = $ARGV[0];

open( CURRENTFILE, "$file");
open( OUTFILE, "> ipdata" );

while ( <CURRENTFILE> ) {

#[08/Mar/2012:09:19:10 +0800] 
$_ =~ /(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})/g;
	if ($1 != "113.106.79.193") {
		print OUTFILE $1 . "\n";
	}
}

close( CURRENTFILE );
close( OUTFILE );
