#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    auto *centralWidget = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(centralWidget);

    m_model = new ProcessModelTable;

    auto *proxyModel = new QSortFilterProxyModel;
    proxyModel->setSourceModel(m_model);

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

    m_summaryPanel = new ProcessSummaryPanel(this);
    mainLayout->addWidget(m_summaryPanel);

    setCentralWidget(centralWidget);

    connect(m_model, &ProcessModelTable::summaryUpdated, m_summaryPanel, &ProcessSummaryPanel::updateSummary);
}

MainWindow::~MainWindow()
{
}
