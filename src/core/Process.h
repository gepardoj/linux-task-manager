#pragma once

#include <string>

struct ProcessInfo
{
    int pid;
    std::string name;
    double cpuUsage;
    int memUsage;
    std::string iconName;
};