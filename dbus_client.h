#ifndef DBUS_CLIENT_H
#define DBUS_CLIENT_H

#include <QObject>
#include "lightdm_greeter_dbus_ifce.h"
#include "greeter_dbusadaptor.h"
class dbus_client : public QObject
{
    Q_OBJECT
public:
    explicit dbus_client(const QString &pathName,
                         const QString &objName,
                         const QString &senderName,
                         const QString &receiverName,QObject *parent = nullptr);
    QStringList get_user_list();
    QStringList get_session_list();
    QString select_user(QString);
    QString get_icon(QString);
    bool authorize(QString);
    QString set_session(QString);
    void sleep();
    void shutdown();
    void reboot();
    void hibernate();
private:
    void initDbus();
    QString	m_pathNameBase;
    QString	m_objNameBase;
    QString m_senderName;
    QString m_receiverName;
    lightdmobject objkun;
    void initinterface();
    net::fascode::lightdm::greeter_dbus* iface;
signals:

};

#endif // DBUS_CLIENT_H
