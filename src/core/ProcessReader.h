#pragma once

#include <vector>
#include "../gui/ProcessModelTable.h"

namespace ProcessReader
{
    std::vector<ProcessInfo> getAllProcesses();
    std::vector<int> getRunningPids();
    void readStat(int pid, ProcessInfo &process);
}