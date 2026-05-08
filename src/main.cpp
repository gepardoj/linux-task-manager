#include <iostream>
#include <QtWidgets>
#include <QPushButton>
#include "gui/ProcessModelTable.h"
#include "core/ProcessReader.h"


int main(int argc, char **argv) {
  QApplication app(argc, argv);
  
  // QPushButton button("Hello world!");
  // button.resize(200,100);
  // button.show();

  qDebug() << "qt ver:" << qVersion();

  QTableView *view = new QTableView;
  ProcessModelTable *model = new ProcessModelTable;
  auto *proxyModel = new QSortFilterProxyModel;
  proxyModel->setSourceModel(model);

  
  auto pids = ProcessReader::getRunningPids();

  std::vector<ProcessInfo> processes;
  for (auto pid : pids) {
    ProcessInfo process = {};
     ProcessReader::readStat(pid, process);
    processes.push_back(process);
  }


  model->updateProcesses(processes);

  view->setWindowTitle("Linux Task Manager");
  view->resize(800, 600);
  view->setModel(proxyModel);
  view->setSortingEnabled(true);
  view->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
  view->setColumnWidth(0, 60);
  view->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
  view->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
  view->setColumnWidth(2, 80);
  view->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
  view->setColumnWidth(3, 80);
  view->show();

  return app.exec();
}

