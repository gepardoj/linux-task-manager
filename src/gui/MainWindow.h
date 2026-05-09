#pragma once

#include "ProcessModelTable.h"
#include "ProcessSummaryPanel.h"
#include <QMainWindow>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    ProcessModelTable *m_model = nullptr;
    ProcessSummaryPanel *m_summaryPanel = nullptr;
};