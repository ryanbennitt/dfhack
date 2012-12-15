
#include "Console.h"
#include "Core.h"
#include "Export.h"
#include "PluginManager.h"
#include "modules/EventManager.h"
#include "DataDefs.h"

using namespace DFHack;

DFHACK_PLUGIN("eventExample");

void jobInitiated(color_ostream& out, void* job);
void jobCompleted(color_ostream& out, void* job);

DFhackCExport command_result plugin_init(color_ostream &out, std::vector<PluginCommand> &commands) {
    EventManager::EventHandler initiateHandler(jobInitiated);
    EventManager::EventHandler completeHandler(jobCompleted);
    Plugin* me = Core::getInstance().getPluginManager()->getPluginByName("eventExample");

    EventManager::registerListener(EventManager::EventType::JOB_INITIATED, initiateHandler, me);
    EventManager::registerListener(EventManager::EventType::JOB_COMPLETED, completeHandler, me);
    
    return CR_OK;
}

void jobInitiated(color_ostream& out, void* job) {
    out.print("Job initiated! 0x%X\n", job);
}

void jobCompleted(color_ostream& out, void* job) {
    out.print("Job completed! 0x%X\n", job);
}

