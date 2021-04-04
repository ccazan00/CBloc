QT += quick

CONFIG += c++11

contains(QT_ARCH, i386) {
    message("32-bit build ...")

    LIBS += -L$$PWD/Libraries/OpenSSL/ -llibcrypto-1_1 -llibssl-1_1
} else {
    message("64-bit build ...")

    LIBS += -L$$PWD/Libraries/OpenSSL/ -llibcrypto-1_1-x64 -llibssl-1_1-x64
}


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        BlockApp.cpp \
        HttpService/APIs/BaseResquestAPI.cpp \
        HttpService/APIs/HomeDataRequestAPI.cpp \
        HttpService/Entities/HomeDataRequestEntity.cpp \
        HttpService/RESTService.cpp \
        HttpService/RequestManager.cpp \
        HttpService/Entities/HomeDataEntity.cpp \
        HttpService/ResponseManager.cpp \
        DataModels/HomeDataModel.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
        BlockApp.h \
        HttpService/APIs/APIDefinitions.h \
        HttpService/APIs/BaseRequestAPI.h \
        HttpService/APIs/HomeDataRequestAPI.h \
        HttpService/Entities/HomeDataRequestEntity.h \
        HttpService/RESTService.h \
        HttpService/RequestManager.h \
        HttpService/Entities/BaseEntity.h \
        HttpService/Entities/HomeDataEntity.h \
        HttpService/ResponseManager.h \
        DataModels/HomeDataModel.h \
        singleton.h
