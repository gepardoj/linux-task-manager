#include <iostream>
#include "gui/MainWindow.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  qDebug() << "qt ver:" << qVersion();

  MainWindow mainWindow;

  return app.exec();
}
