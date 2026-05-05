#pragma once

#include <vector>
#include "../tables/ProcessModelTable.h"

std::vector<int> getRunningPids();
void readStat(int pid, ProcessInfo &process);