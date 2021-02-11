#include "dbus_client.h"

dbus_client::dbus_client(const QString &pathName,
                         const QString &objName,
                         const QString &senderName,
                         const QString &receiverName,QObject *parent) : QObject(parent),m_pathNameBase(pathName),m_objNameBase(objName)
  ,m_senderName(senderName),m_receiverName(receiverName),objkun(this)
{
    initDbus();
    initinterface();
}
void dbus_client::initDbus(){
    QDBusConnection sessionkun=QDBusConnection::connectToBus(QDBusConnection::SessionBus,m_senderName);
    if(!sessionkun.isConnected()){
        return;
    }
    if(!sessionkun.registerService(m_pathNameBase + m_senderName)){

    }
    if(!sessionkun.registerObject(m_objNameBase + m_senderName,this)){

    }
    new Greeter_dbusAdaptor(&objkun);
}
void dbus_client::initinterface(){
    QDBusConnection sessionkun=QDBusConnection::connectToBus(QDBusConnection::SessionBus,m_receiverName);
    if(!sessionkun.isConnected()){
        return;
    }
    iface=new net::fascode::lightdm::greeter_dbus(m_pathNameBase + m_receiverName,m_objNameBase+m_receiverName,sessionkun,&objkun);

}
QString dbus_client::get_icon(QString username){
    return iface->get_icon(username.toLocal8Bit()).value();
}
QStringList dbus_client::get_user_list(){
    return iface->get_user_list().value();
}
QStringList dbus_client::get_session_list(){
    return iface->get_session_list().value();
}
QString dbus_client::select_user(QString username){
    return iface->select_user(username).value();
}
bool dbus_client::authorize(QString password){
    return iface->authorize(password).value();
}
QString dbus_client::set_session(QString session){
    return iface->set_session(session);
}
void dbus_client::sleep(){
    iface->sleep();
}
void dbus_client::shutdown(){
    iface->shutdown();
}
void dbus_client::hibernate(){
    iface->hibernate();
}
void dbus_client::reboot(){
    iface->reboot();
}
