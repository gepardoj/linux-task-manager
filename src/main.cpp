#include <iostream>
#include <QtWidgets>
#include <QPushButton>
#include "gui/ProcessModelTable.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  qDebug() << "qt ver:" << qVersion();

  QTableView *view = new QTableView;
  ProcessModelTable *model = new ProcessModelTable;
  auto *proxyModel = new QSortFilterProxyModel;
  proxyModel->setSourceModel(model);

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
