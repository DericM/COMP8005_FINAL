#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "portbridge.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scrollArea->setWidgetResizable(true);

    layout = new QVBoxLayout( ui->scrollAreaWidgetContents);
    layout->setMargin(0);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    ui->scrollAreaWidgetContents->setLayout( layout);

    on_add_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_clicked()
{
    PortBridge *pb = new PortBridge(this);
    pb->setMinimumHeight(85);
    pb->setMaximumHeight(85);
    layout->addWidget(pb);

    layout->setAlignment(Qt::AlignTop);
}
