//====================================================================
// Filename:      main.cpp
// Version:       0.02
// Author:        吴旭 <admirestator@gmail.com>
// Created at:    Mon Mar 12 10:11:25 2012
// Description:   main file for log analysis.
//====================================================================

#include <iostream>
#include <cstring>
#include "loganalysis.h"

void about();
void usage();

int main(int argc, char *argv[])
{
    LogAnalysis *ans;
    
    if (argc < 1 || argc > 3) {
        throw runtime_error("Invaild argument!");
        usage();
    }
    else if (argc == 1) {
        ans = new LogAnalysis();
    }
    else if (argc == 2) {
        if (strcmp(argv[1], "help")) {
            throw runtime_error("Invaild argument!");
            usage();
        }
        else {
            about();
            usage();
            return 0;
        }
    }
    else if (argc == 3) {
        ans = new LogAnalysis(argv[1], argv[2]);
    }
        
    ans->getin_ip();
    ans->getout_rst();
    
	return 0;
}



void about() {
    cout << "about this program" << endl;
    cout << "version" << version << endl;
}


void usage() {
    cout << "Usage: \n";
    cout << "1 ./count\n";
    cout << "This use \"ipdata\" as default ipdata file and \"rstdata\" as default result output file\n"
         << endl;
    cout << "2 ./count ipdata resultfile\n";
    cout << "You MUST specify \"ipdata\" for ip collection and \"resultfile\" for result output file."
         << endl;
}
