#ifndef PORTBRIDGE_H
#define PORTBRIDGE_H

#include <QWidget>
#include <QProcess>

namespace Ui {
class PortBridge;
}

class PortBridge : public QWidget
{
    Q_OBJECT

public:
    explicit PortBridge(QWidget *parent = 0);
    ~PortBridge();

private slots:
    void on_start_stop_clicked();

    void on_remove_clicked();

private:
    Ui::PortBridge *ui;
    QProcess process;

};

#endif // PORTBRIDGE_H
