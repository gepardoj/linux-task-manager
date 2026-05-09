#include "SystemMonitor.h"
#include <filesystem>
#include <fstream>
#include <algorithm>
#include <string>
#include "../utils/StringUtils.h"

namespace fs = std::filesystem;

std::vector<int> SystemMonitor::getRunningPids()
{
    std::vector<int> pids;
    const std::string procPath = "/proc";

    try
    {
        for (const auto &entry : fs::directory_iterator(procPath))
        {
            if (entry.is_directory())
            {
                std::string folderName = entry.path().filename().string();

                // folder is digitial (it's a process)
                if (std::all_of(folderName.begin(), folderName.end(), ::isdigit))
                {
                    pids.push_back(std::stoi(folderName));
                }
            }
        }
    }
    catch (const fs::filesystem_error &e)
    {
        //
    }

    return pids;
}

std::string SystemMonitor::getIconNameByProcess(std::string name)
{
    if (name == "")
        return "";
    auto lowerName = StringUtils::toLower(name);

    std::vector<std::string> desktopDirs = {
        "/usr/share/icons/hicolor/128x128/apps/",
        "/usr/share/icons/hicolor/96x96/apps/",
        "/usr/share/icons/hicolor/72x72/apps/",
        "/usr/share/icons/hicolor/64x64/apps/",
        "/usr/share/icons/hicolor/48x48/apps/",
        "/usr/share/pixmaps/",
        "~/.local/share/icons/",
        "/usr/share/code/resources/app/resources/linux",
    };

    for (const auto &dirPath : desktopDirs)
    {
        if (!fs::exists(dirPath) || !fs::is_directory(dirPath))
            continue;
        try
        {
            for (const auto &entry : fs::directory_iterator(dirPath))
            {
                if (entry.is_regular_file())
                {
                    auto filename = entry.path().filename().string();
                    auto lowerFilename = StringUtils::toLower(filename);
                    if (lowerFilename.ends_with(".png") && lowerFilename.find(lowerName) != std::string::npos)
                    {
                        return entry.path().string();
                    }
                }
            }
        }
        catch (...)
        {
        }
    }
    return "";
}

void SystemMonitor::readStat(int pid, ProcessInfo &process)
{
    std::string path = "/proc/" + std::to_string(pid) + "/status";
    std::ifstream file(path);
    if (!file.is_open())
        return;

    process.pid = pid;

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        if (line.substr(0, 5) == "Name:")
        {
            process.name = line.substr(6);
        }
        else if (line.substr(0, 6) == "VmRSS:")
        {
            std::string label;
            int value;
            std::string unit;

            ss >> label >> value >> unit;

            process.memUsage = value;
        }
    }
}

std::vector<ProcessInfo> SystemMonitor::getAllProcesses()
{
    auto pids = getRunningPids();

    std::vector<ProcessInfo> processes;
    for (auto pid : pids)
    {
        ProcessInfo process = {};
        readStat(pid, process);
        process.iconName = getIconNameByProcess(process.name);
        processes.push_back(process);
    }
    return processes;
}
