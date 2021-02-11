#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbus_client.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_userListComboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    dbus_client* clientkun;

    QString pathBase = "net.fascode.lightdm.greeter_dbus.";
    QString objBase = "/net/fascode/lightdm/greeter_dbus/";
    QString	senderName = "sender";
    QString receiverName = "recevier";
};
#endif // MAINWINDOW_H
