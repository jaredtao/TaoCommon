INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/Logger/loggertemplate.h \
    $$PWD/Logger/logger.h \
    $$PWD/Thread/threadcommon.h \
    $$PWD/Thread/threadpool.h \
    $$PWD/Thread/threadworkercontroller.h \
    $$PWD/taocommonglobal.h

SOURCES += \
    $$PWD/Logger/logger.cpp \
    $$PWD/Thread/threadpool.cpp

