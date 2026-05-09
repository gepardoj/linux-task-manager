#include "ProcessModelTable.h"
#include "../core/SystemMonitor.h"
#include <QIcon>

ProcessModelTable::ProcessModelTable(QObject *parent) : QAbstractTableModel(parent)
{
    m_refreshTimer = new QTimer(this);
    connect(m_refreshTimer, &QTimer::timeout, this, &ProcessModelTable::refresh);
    m_refreshTimer->start(1000);
    refresh();
}

void ProcessModelTable::refresh()
{
    beginResetModel();
    loadAllProcesses();
    endResetModel();
}

void ProcessModelTable::loadAllProcesses()
{
    m_processes.clear();
    auto newProcesses = SystemMonitor::getAllProcesses();
    auto total = newProcesses.size();
    emit summaryUpdated(total);
    m_processes = std::move(newProcesses);
}

int ProcessModelTable::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return static_cast<int>(m_processes.size());
}

int ProcessModelTable::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 4;
}

QVariant ProcessModelTable::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant();
    switch (section)
    {
    case 0:
        return "PID";
    case 1:
        return "Name";
    case 2:
        return "CPU %";
    case 3:
        return "Mem, kb";
    default:
        return QVariant();
    }
}

QVariant ProcessModelTable::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const auto &process = m_processes[index.row()];

    if (role == Qt::DecorationRole && index.column() == 1)
    {
        auto icon = QIcon::fromTheme(QString::fromStdString(process.iconName));
        return icon;
    }
    else if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    switch (index.column())
    {
    case 0:
        return process.pid;
    case 1:
        return QString::fromStdString(process.name);
    case 2:
        return QString::number(process.cpuUsage, 'f', 1);
    case 3:
        return process.memUsage; //::number(process.memUsage, 'f', 1);
    default:
        return QVariant();
    }
}

void ProcessModelTable::updateProcesses(const std::vector<ProcessInfo> &newProcesses)
{
    beginResetModel();

    m_processes.clear();
    for (auto &process : newProcesses)
    {
        m_processes.push_back(process);
    }

    endResetModel();
}