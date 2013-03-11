include(../../../qtcreator.pri)
include(../../rpath.pri)
include(../../libs/ssh/ssh.pri)

CONFIG += console
CONFIG -= app_bundle

QT -= gui test
QT += network

SOURCES = \
    main.cpp \
    merssh.cpp

HEADERS += \
    merssh.h

DESTDIR = $$IDE_LIBEXEC_PATH

target.path  = $$QTC_PREFIX/bin # FIXME: libexec, more or less
INSTALLS += target
