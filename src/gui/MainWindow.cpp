#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    auto *centralWidget = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(centralWidget);

    auto *model = new ProcessModelTable;

    auto *proxyModel = new QSortFilterProxyModel;
    proxyModel->setSourceModel(model);

    auto *tableView = new QTableView;
    tableView->setModel(proxyModel);
    tableView->setSortingEnabled(true);
    tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    tableView->setColumnWidth(0, 60);
    tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    tableView->setColumnWidth(2, 80);
    tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    tableView->setColumnWidth(3, 80);

    mainLayout->addWidget(tableView);

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
}
