#include <iostream>
#include "MyAgent/myagent.h"
#include "CommandLine/commandline.h"
#include "Other/tools.h"

int main(int argc, char **argv) 
{
    std::cout << "Hello, Robocup 3D Simulation!\n";

    auto cmd = parseCommandLine(argc, argv);
    MyAgent agent(cmd.teamName, "", cmd.host, cmd.port, cmd.unum);
    agent.run();
    
}
