#include <filesystem>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include "../gui/ProcessModelTable.h"

namespace fs = std::filesystem;

namespace ProcessReader 
{
std::vector<int> getRunningPids() {
    std::vector<int> pids;
    const std::string procPath = "/proc";

    try {
        for (const auto& entry : fs::directory_iterator(procPath)) {
            if (entry.is_directory()) {
                std::string folderName = entry.path().filename().string();

                // folder is digitial (it's a process)
                if (std::all_of(folderName.begin(), folderName.end(), ::isdigit)) {
                    pids.push_back(std::stoi(folderName));

                }
            }
        }
    } catch (const fs::filesystem_error& e) {
        //
    }

    return pids;
}

void readStat(int pid, ProcessInfo &process) {
    std::string path = "/proc/" + std::to_string(pid) + "/status";
    std::ifstream file(path);
    if (!file.is_open()) return;

    process.pid = pid;

    std::string line;
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        if (line.substr(0, 5) == "Name:") {
            process.name = QString::fromStdString(line.substr(6)).trimmed();
        }
        else if (line.substr(0, 6) == "VmRSS:") {
            std::string label;
            int value;
            std::string unit;

            ss >> label >> value >> unit;

            process.memUsage = value;
        }
    }
}
}