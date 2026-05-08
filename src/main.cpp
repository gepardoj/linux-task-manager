#include <iostream>
#include "gui/MainWindow.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  qDebug() << "qt ver:" << qVersion();

  auto *mainWindow = new MainWindow;
  mainWindow->setWindowTitle("Linux Task Manager");
  mainWindow->resize(800, 600);
  mainWindow->show();

  return app.exec();
}
