#include <iostream>
#include <libbats/HumanoidAgent/humanoidagent.hh>

class MyAgent : public bats::HumanoidAgent
{
  public:
    MyAgent() {};
    virtual void init();
    virtual void think();
};
