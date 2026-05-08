#include "ProcessModelTable.h"

ProcessModelTable::ProcessModelTable(QObject *parent) : QAbstractTableModel(parent) {

}

int ProcessModelTable::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) return 0;
    return static_cast<int>(m_processes.size());
}

int ProcessModelTable::columnCount(const QModelIndex &parent) const {
    if (parent.isValid()) return 0;
    return 4;
}

QVariant ProcessModelTable::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal) return QVariant();
    switch (section) {
        case 0: return "PID";
        case 1: return "Name";
        case 2: return "CPU %";
        case 3: return "Mem, kb";
        default: return QVariant();
    }
}

QVariant ProcessModelTable::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) return QVariant();

    const auto &process = m_processes[index.row()];

    switch (index.column()) {
        case 0: return process.pid;
        case 1: return process.name;
        case 2: return QString::number(process.cpuUsage, 'f', 1);
        case 3: return process.memUsage;//::number(process.memUsage, 'f', 1);
        default: return QVariant();
    }
}

void ProcessModelTable::updateProcesses(const std::vector<ProcessInfo> &newProcesses) {
    beginResetModel();

    m_processes.clear();
    for (auto& process : newProcesses) {
        m_processes.push_back(process);
    }

    endResetModel();
}