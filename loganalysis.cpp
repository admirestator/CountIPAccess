//====================================================================
// Filename:      loganalysis.cpp
// Version:       0.02
// Author:        吴旭 <admirestator@gmail.com>
// Created at:    Mon Mar 12 09:04:31 2012
// Description:   Impeletion of class LogAnalysis.
//====================================================================

#include <iomanip>
#include "loganalysis.h"

LogAnalysis::LogAnalysis()
{
    fip = new CIpFinder("QQWry.dat");

    if (!open_file (infile, "ipdata")) {
        throw runtime_error ("open ipdata fail!");
    }
    if (!open_file (outfile, "rstdata")) {
        throw runtime_error ("open rstdata fail!");
    }
}

LogAnalysis::LogAnalysis(char *ipdata, char *rstdata)
{
    fip = new CIpFinder("QQWry.dat");

    if (!open_file (infile, ipdata)) {
        throw runtime_error ("open ip data fail!");
    }
    if (!open_file (outfile, rstdata)) {
        throw runtime_error ("open result file fail!");
    }
}


LogAnalysis::~LogAnalysis()
{
    delete fip;
    infile.close();
    outfile.close();
}

void LogAnalysis::getin_ip() {
    register string tmpstr;
    while (!infile.eof()) {
        getline (infile, tmpstr);
        pair < map < string, long >::iterator, bool > ret =
            cnt.insert (make_pair (tmpstr, 1));
        if (!ret.second)
            ++ret.first->second;
    }

    /*
      for (cnt_cstidx = cnt.begin (); cnt_cstidx != cnt.end(); ++cnt_cstidx) {
      cout << cnt_cstidx->first.c_str() << "\t" << cnt_cstidx->second << endl;
      }
    */

}

void LogAnalysis::getout_rst() {
    for (cnt_cstidx = cnt.begin(); cnt_cstidx != cnt.end(); ++cnt_cstidx) {
        fip->GetAddressByIp(cnt_cstidx->first.c_str(), addr.country, addr.location);
        outfile << left << setw(15) << cnt_cstidx->first << "\t\t"
                << left <<  cnt_cstidx->second << "\t\t"
                << left << setw(36) << addr.country << "\t"
                << addr.location << endl;
	}
}

/////////interface above

ifstream& LogAnalysis::open_file (ifstream & in, const string & file)
{
    in.close ();
    in.clear ();
    in.open (file.c_str ());

    return in;
}

ofstream& LogAnalysis::open_file (ofstream & out, const string & file)
{
    out.close ();
    out.clear ();
    out.open (file.c_str ());

    return out;
}
