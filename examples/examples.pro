TEMPLATE = subdirs
SUBDIRS += \
    CommonWithSource

qtHaveModule(TaoCommon) {
    SUBDIRS += \
        CommonWithModule \
        ExampleLog
}
