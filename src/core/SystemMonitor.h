#pragma once

#include <vector>
#include "../gui/ProcessModelTable.h"

namespace SystemMonitor
{
    std::vector<ProcessInfo> getAllProcesses();
    std::vector<int> getRunningPids();
    std::string getIconNameByProcess(std::string name);
    void readStat(int pid, ProcessInfo &process);
}