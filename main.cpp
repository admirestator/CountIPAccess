//====================================================================
// Filename:      main.cpp
// Version:       0.02
// Author:        吴旭 <admirestator@gmail.com>
// Created at:    Mon Mar 12 10:11:25 2012
// Description:   main file for log analysis.
//====================================================================

#include <iostream>
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
        if (argv[1] != "help") {
            throw runtime_error("Invaild argument!");
            usage();
        }
        else {
            about();
            usage();
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
    cout << "Usage: " << endl;
    cout << "1. ./count " << endl;
    cout << "This use \"\" as default ipdata file and \"\" as default result output file"
         << endl;
    cout << "2. ./count ipdata resultfile" << endl;
    cout << "You MUST specify \"ipdata\" for ip collection and \"resultfile\" for result output file"
         << endl;
}
