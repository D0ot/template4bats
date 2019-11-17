#include <iostream>
#include <libbats/HumanoidAgent/humanoidagent.hh>

using namespace bats;

class MyAgent : public bats::HumanoidAgent
{
  public:
    MyAgent() : HumanoidAgent("HfutEngine") {};
    virtual void init();
    virtual void think();
};
