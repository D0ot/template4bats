#include "MyAgent/myagent.h"
#include <libbats/Conf/conf.hh>
#include <libbats/Localizer/KalmanLocalizer/kalmanlocalizer.hh>
#include <libbats/Debugger/RoboVizDebugger/robovizdebugger.hh>


// things to initialize here
// 1. parse conf file
// 2. Localizer
// 3. Debugger
// 4. "Motions" things

void MyAgent::init()
{
    SConf::getInstance().parseFile("./conf.xml");
    
    SLocalizer::initialize<KalmanLocalizer>();

    SDebugger::initialize<RoboVizDebugger>(); 

}