#include <iostream>
#include <QtWidgets>
#include <QPushButton>
#include "tables/ProcessModelTable.h"

int main(int argc, char **argv) {
  QApplication app(argc, argv);
  
  // QPushButton button("Hello world!");
  // button.resize(200,100);
  // button.show();

  QTableView *view = new QTableView;
  ProcessModelTable *model = new ProcessModelTable;
  view->setModel(model);
  view->resize(800, 600);
  view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  view->show();

  return app.exec();
}

