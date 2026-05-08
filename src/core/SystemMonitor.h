#pragma once

#include <vector>
#include "../gui/ProcessModelTable.h"

namespace SystemMonitor
{
    std::vector<ProcessInfo> getAllProcesses();
    std::vector<int> getRunningPids();
    void readStat(int pid, ProcessInfo &process);
}