#pragma once

#include <vector>
#include <string>
#include <QAbstractTableModel>
#include <QTimer>
#include "../core/Process.h"

class ProcessModelTable : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ProcessModelTable(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void updateProcesses(const std::vector<ProcessInfo> &newProcesses);

    void refresh();

signals:
    void summaryUpdated(size_t total);

private:
    std::vector<ProcessInfo> m_processes;
    // std::map<std::string, QIcon> m_map_icons;
    QTimer *m_refreshTimer = nullptr;

    void loadAllProcesses();
};