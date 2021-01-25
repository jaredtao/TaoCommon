TEMPLATE = app

QT += TaoCommon
INCLUDEPATH += $$[QT_INSTALL_HEADERS]/TaoCommon

SOURCES += main.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/ExampleLog
INSTALLS += target
