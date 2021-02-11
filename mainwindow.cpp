#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "lightdm_greeter_dbus_ifce.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    clientkun=new dbus_client(pathBase,objBase,senderName,receiverName,this);
    ui->userListComboBox->addItems(clientkun->get_user_list());
    ui->SessionCombo->addItems(clientkun->get_session_list());
    clientkun->select_user(ui->userListComboBox->itemText(0));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_userListComboBox_currentIndexChanged(const QString &arg1)
{
    clientkun->select_user(arg1);
}

void MainWindow::on_pushButton_clicked()
{
    clientkun->set_session(ui->SessionCombo->currentText());
    if(clientkun->authorize(ui->passwordedit->text()) == false){
        clientkun->select_user(ui->userListComboBox->itemText(0));
    }
}
