//====================================================================
// Filename:      loganalysis.h
// Version:       0.10
// Author:        吴旭 <admirestator@gmail.com>
// Created at:    Mon Mar 12 08:59:50 2012
// Description:   Defination of class LogAnalysis.Count the
//                accessed ip and the address of ip with QQWry.
//====================================================================

#ifndef _LOGANALYSIS_H_
#define _LOGANALYSIS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <utility>

#include "ip.h"

using namespace std;
const string version = "0.10";

typedef struct address {
    string country;
    string location;
} Address;

class LogAnalysis
{
public:
    LogAnalysis();
    LogAnalysis(char *ipdata, char *rstdata);
    virtual ~LogAnalysis();

    void getin_ip();
    void sortBytimes();
    void getout_rst();

private:
    //a class lookup ip with QQWry.dat from Internet.
    CIpFinder *fip;

    //address data structor
    Address addr;
    
    //store orginal ip data from files;
    vector <string> ogn_ip;
    vector <string>::iterator ogn_ip_idx;

    //store counted data from ogn_ip;
    map <string, long>cnt;
    
    map <string, long>::iterator cnt_idx;
    map <string, long>::const_iterator cnt_cstidx;
    map <long, string> cnt_reverse;     // for sort by value;
    map <long, string>::const_reverse_iterator cnt_reverseidx;

    //I/O operation for data files;
    ifstream infile;
    ofstream outfile;
    ifstream &open_file (ifstream &in, const string &file);
    ofstream &open_file (ofstream &out, const string &file);
};

#endif /* _LOGANALYSIS_H_ */
