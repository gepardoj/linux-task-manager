#pragma once

#include "ProcessModelTable.h"
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
};