#include "portbridge.h"
#include "ui_portbridge.h"
#include <QDebug>

PortBridge::PortBridge(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PortBridge)
{
    ui->setupUi(this);
}

PortBridge::~PortBridge()
{
    delete ui;
}


void PortBridge::on_start_stop_clicked()
{
    int src_port = ui->src_port->value();
    QString dst_ip = ui->dst_ip->text();
    int dst_port = ui->dst_port->value();

    qDebug() << src_port << ":" << dst_ip << ":" << dst_port;

    QString args1 = "TCP-LISTEN:" + QString::number(src_port) + ",fork";
    QString args2 = "TCP:" + dst_ip + ":" + QString::number(dst_port);

    qDebug() << args1 << " " << args2;

    process.start("socat", QStringList()<<args1<<args2);

    QString output(process.readAllStandardOutput());
    qDebug()<<output;

    QString err(process.readAllStandardError());
    qDebug()<<err;

    qDebug() << "After";

    ui->src_port->setEnabled(false);
    ui->dst_ip->setEnabled(false);
    ui->dst_port->setEnabled(false);
    ui->start_stop->setEnabled(false);
}

void PortBridge::on_remove_clicked()
{
    process.close();
    process.kill();
    close();
}
