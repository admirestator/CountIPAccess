#! /usr/bin/perl 
#Filename: getip.pl
#Author:   admirestator <admirestator@gmail.com>
#Comment:  get ip from log files;

$file = $ARGV[0];

open( CURRENTFILE, "$file");
open( OUTFILE, "> ipdata" );

#$_ =~ /^.+(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}).+$/g;
#$_ =~ /^.+(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.(\d{1,2}|1\d\d|2[0-4]\d|25[0-5])\.(\d{1,2}|1\d\d|2[0-4]\d|25[0-5]).+$/g;
while ( <CURRENTFILE> ) {
	$_ =~ /^.+((?:(?:25[0-5]|2[0-4]\d|[01]?\d?\d)\.){3}(?:25[0-5]|2[0-4]\d|[01]?\d?\d)).+$/;
	if ($1 ne "113.106.79.193") {
		print OUTFILE $1 . "\n";
	}
}

close( CURRENTFILE );
close( OUTFILE );
