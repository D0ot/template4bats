#include <iostream>
#include <libbats/HumanoidAgent/humanoidagent.hh>

using namespace bats;

class MyAgent : public bats::HumanoidAgent
{
  public:
    MyAgent(std::string teamName, std::string confFile = "",
            std::string const host = "localhost", unsigned port = 3100,
            unsigned unum = 0) : HumanoidAgent(teamName, confFile, host, port, unum) {};
    virtual void init();
    virtual void think();
};
