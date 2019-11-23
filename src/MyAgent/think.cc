#include "MyAgent/myagent.h"
#include <libbats/AgentModel/agentmodel.hh>
#include <libbats/Cochlea/cochlea.hh>
#include <libbats/WorldModel/worldmodel.hh>
#include <libbats/Cerebellum/cerebellum.hh>
#include <libbats/SocketComm/AgentSocketComm/agentsocketcomm.hh>
#include <libbats/Action/RC3DAction/rc3daction.hh>
#include <libbats/Debugger/debugger.hh>
#include <libbats/Shape/shape.hh>
#include <Eigen/Dense>

void MyAgent::think()
{
    // we can add action to cerebellum
    // Actions will be encode to message which will be sent to server.
    auto& cerebellum = SCerebellum::getInstance();


    // we can get raw data from cochlea
    auto& cochlea = SCochlea::getInstance();

    // Basic infomation such as filed size, play mode, etc
    auto& worldmodel = SWorldModel::getInstance();

    // All location infomation which needs algrithm can be get from localizer
    auto& localizer = SLocalizer::getInstance();

    auto& debugger = SDebugger::getInstance();


    // commit the actions
    cerebellum.outputCommands(SAgentSocketComm::getInstance());
}