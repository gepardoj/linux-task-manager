#pragma once

#include <QWidget>
#include <QLabel>

class ProcessSummaryPanel : public QWidget
{
    Q_OBJECT

public:
    explicit ProcessSummaryPanel(QWidget *parent = nullptr);

public slots:
    void updateSummary(size_t totalProcesses);

private:
    QLabel *m_totalProcesses = nullptr;
};