#ifndef LIGHTDMOBJECT_H
#define LIGHTDMOBJECT_H

#include <QObject>
class lightdmobject : public QObject
{
    Q_OBJECT
public:
    explicit lightdmobject(QObject *parent = nullptr);
    QStringList get_user_list();
    QStringList get_session_list();
    QString select_user(QString);
    QString get_icon(QString);
    void auth(QString);
    bool authorize(QString);
    QString set_session(QString);
    void sleep();
    void shutdown();
    void reboot();
    void hibernate();
private:
signals:
    void error_login();
public slots:

    void authenticationComplete();
};

#endif // LIGHTDMOBJECT_H
