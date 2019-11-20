#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include <string>
#include "cxxopts.hpp"

struct CMDInfomation
{
    // Humanoidagent needed args
    std::string host;
    std::string teamName;
    unsigned port;
    unsigned unum;

    // extra args
    
    unsigned type;
    std::string mhost;
    unsigned mport;
};


CMDInfomation parseCommandLine(int argc, char **argv);



#endif // COMMANDLINE_H_