cmake_minimum_required(VERSION 3.5)

project(lightdm-client-dbus-test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS DBus Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS DBus Widgets REQUIRED)

set(dbus_xml net.fascode.lightdm.greeter_dbus.xml)
set(SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    dbus_client.cpp
    dbus_client.h
    lightdmobject.cpp
    lightdmobject.h
    )
qt5_add_dbus_interface(SOURCES ${dbus_xml} lightdm_greeter_dbus_ifce)
qt5_add_dbus_adaptor(SOURCES ${dbus_xml} lightdmobject.h lightdmobject)
add_executable(lightdm-client-dbus-test
    ${SOURCES}
)

target_link_libraries(lightdm-client-dbus-test PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::DBus)
