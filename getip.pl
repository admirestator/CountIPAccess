#! /usr/bin/perl -w

$file = $ARGV[0];

open( CURRENTFILE, "$file");
open( OUTFILE, ">outfile" );

while ( <CURRENTFILE> ) {

#[08/Mar/2012:09:19:10 +0800] 
#$_ =~ /(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}.*([.*]))/g;
$_ =~ /(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})/g;

	if ($1 != "113.106.79.193") {
		print OUTFILE $1 . "\n";
	}
}

close( CURRENTFILE );
close( OUTFILE );
