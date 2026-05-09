#include "ProcessSummaryPanel.h"
#include <QHBoxLayout>
#include <QFrame>

ProcessSummaryPanel::ProcessSummaryPanel(QWidget *parent) : QWidget(parent)
{
    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(8, 8, 8, 8);
    layout->setSpacing(4);

    m_totalProcesses = new QLabel(this);

    for (auto *label : {m_totalProcesses})
    {
        label->setStyleSheet("font-weight: bold;");
    }

    layout->addWidget(new QLabel("Total Processes: ", this));
    layout->addWidget(m_totalProcesses);
    layout->addStretch(1);
}

void ProcessSummaryPanel::updateSummary(size_t total)
{
    m_totalProcesses->setText(QString::number(total));
}