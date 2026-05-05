#include <iostream>
#include <QtWidgets>
#include <QPushButton>
#include "tables/ProcessModelTable.h"
#include "filesystem/filesystem.h"


int main(int argc, char **argv) {
  QApplication app(argc, argv);
  
  // QPushButton button("Hello world!");
  // button.resize(200,100);
  // button.show();

  QTableView *view = new QTableView;
  ProcessModelTable *model = new ProcessModelTable;

  
  auto pids = getRunningPids();

  std::vector<ProcessInfo> processes;
  for (auto pid : pids) {
    ProcessInfo process = {};
    readStat(pid, process);
    processes.push_back(process);
  }


  model->updateProcesses(processes);

  view->setWindowTitle("Linux Task Manager");
  view->resize(800, 600);
  view->setModel(model);
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

