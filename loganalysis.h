//====================================================================
// Filename:      loganalysis.h
// Version:       0.02
// Author:        吴旭 <admirestator@gmail.com>
// Created at:    Mon Mar 12 08:59:50 2012
// Description:   Defination of class LogAnalysis.Count the
//                accessed ip and the address of ip with QQWry.
//====================================================================

#ifndef _LOGANALYSIS_H_
#define _LOGANALYSIS_H_

#include <iostream>
#include <fstream>
//#include <cstdlib>

#include <string>
#include <vector>
#include <map>

#include <algorithm>
#include <stdexcept>
#include <utility>

#include "ip.h"

using namespace std;
const string version = "0.02";

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
    void getout_rst();

private:
    //help
//    void help();
    //about
//    void about();
    
    //usage
    //  void usage();
        
    //a class search QQWry.dat file from Internet.
    CIpFinder *fip;

    //address data structor
    Address addr;
    
    //store orginal ip data from files;
    vector < string > ogn_ip;
    vector < string >::iterator ogn_ip_idx;

    //store counted data from ogn_ip;
    map < string, long >cnt;
    map < string, long >::iterator cnt_idx;
    map < string, long >::const_iterator cnt_cstidx;

    //I/O operation for data files;
    ifstream infile;
    ofstream outfile;
    ifstream &open_file (ifstream & in, const string & file);
    ofstream &open_file (ofstream & out, const string & file);

};

#endif /* _LOGANALYSIS_H_ */
