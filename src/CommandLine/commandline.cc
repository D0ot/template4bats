#include "CommandLine/commandline.h"


CMDInfomation parseCommandLine(int argc, char **argv)
{
    CMDInfomation info;
    cxxopts::Options options(argv[0]);
    options.add_options()
    ("h,host", "Hostname or IP address of server", cxxopts::value(info.host)->default_value("localhost"))
    ("p,port", "Port of server", cxxopts::value(info.port)->default_value("3100"))
    ("n,team", "Team name", cxxopts::value(info.teamName)->default_value("NoTeamName"))
    ("u,unum", "Unum, uniform number of the agent", cxxopts::value(info.unum)->default_value("1"))
    ("t,type", "Type of the agent", cxxopts::value(info.type)->default_value("1"))
    ("mhost", "Hostname or IP of monitor", cxxopts::value(info.mhost)->default_value("localhost"))
    ("mport", "Port of monitor", cxxopts::value(info.mport)->default_value("32769"));
    options.parse(argc, argv);
    return info;
}