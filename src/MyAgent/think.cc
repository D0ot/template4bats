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
    auto& cerebellum = SCerebellum::getInstance();
    auto& cochlea = SCochlea::getInstance();
    auto& worldmodel = SWorldModel::getInstance();
    auto& localizer = SLocalizer::getInstance();
    auto& debugger = SDebugger::getInstance();

    cerebellum.outputCommands(SAgentSocketComm::getInstance());
}