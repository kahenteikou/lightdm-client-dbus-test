#include "lightdmobject.h"

lightdmobject::lightdmobject(QObject *parent) : QObject(parent){

}
QStringList lightdmobject::get_user_list(){

}

QStringList lightdmobject::get_session_list(){
}

QString lightdmobject::select_user(QString user){
}
QString lightdmobject::get_icon(QString user){
    return nullptr;
}
void lightdmobject::auth(QString password){
}
QString lightdmobject::set_session(QString sess){
}
void lightdmobject::authenticationComplete(){
}
void lightdmobject::shutdown(){
}
void lightdmobject::reboot(){
}
void lightdmobject::hibernate(){

}
void lightdmobject::sleep(){
}
bool lightdmobject::authorize(QString pass){
}
