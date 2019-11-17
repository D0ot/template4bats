#include <iostream>
#include <libbats/HumanoidAgent/humanoidagent.hh>

class MyAgent : public bats::HumanoidAgent
{
  public:
    MyAgent() :HumanoidAgent("HfutEngine") {};
    virtual void init();
    virtual void think();
};
