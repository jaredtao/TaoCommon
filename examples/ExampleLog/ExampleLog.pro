TEMPLATE = app
CONFIG += install_ok  # Do not cargo-cult this!
QT += TaoCommon

SOURCES += main.cpp \
    main.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/taoCommon/ExampleLog
INSTALLS += target
