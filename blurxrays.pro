include(../../plugins.pri)
include(common/common.pri)

TARGET = $$PLUGINS_PREFIX/Visual/blurxrays

HEADERS += blurxrays.h \
           visualblurxraysfactory.h
    
SOURCES += blurxrays.cpp \
           visualblurxraysfactory.cpp

unix{
    target.path = $$PLUGIN_DIR/Visual
    INSTALLS += target
}
