headersTargetPath=$$[QT_INSTALL_HEADERS]/$$MODULE_INCNAME
message("QMAKE_INSTALL_DIR $$headersTargetPath")

gHeader.files=$$PWD/TaoCommonGlobal.h
gHeader.path=$$headersTargetPath

commonHeader.files=$$PWD/Common/*.h
commonHeader.path=$$headersTargetPath/Common

framelessHeader.files=$$PWD/Frameless/*.h
framelessHeader.path=$$headersTargetPath/Frameless

loggerHeader.files=$$PWD/Logger/*.h
loggerHeader.path=$$headersTargetPath/Logger

quickToolHeader.files=$$PWD/QuickTool/*.h
quickToolHeader.path=$$headersTargetPath/QuickTool

taoModelHeader.files=$$PWD/TaoModel/*.h $$PWD/TaoModel/*.hpp
taoModelHeader.path=$$headersTargetPath/TaoModel

threadHeader.files=$$PWD/Thread/*.h
threadHeader.path=$$headersTargetPath/Thread

transHeader.files=$$PWD/Trans/*.h
transHeader.path=$$headersTargetPath/Trans


INSTALLS += \
    gHeader commonHeader framelessHeader loggerHeader quickToolHeader \
    taoModelHeader threadHeader transHeader
