#QT -= gui
QT += gui
#CONFIG += static
CONFIG += c++11 console
CONFIG += app_bundle
QT += widgets
QT += core gui
TEMPLATE      = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
QMAKE_CXXFLAGS += -openmp
QMAKE_CXXFLAGS += -O2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += main.cpp \
    source/util/util.cpp \
    source/util/buffer2d.cpp \
    main.cpp \
    nutilapplication.cpp \
    mainwindow.cpp \
    node.cpp \
    source/ltiff.cpp \
    source/nauto.cpp \
    source/ProcessManager/nutilprocess.cpp \
    source/ProcessManager/processmanager.cpp \
    source/util/lmessage.cpp \
    source/util/limage.cpp \
    source/util/area.cpp \
    source/util/atlaslabel.cpp \
    source/util/flat2d.cpp \
    source/LBook/lbook.cpp \
    source/LBook/lbookxlnt.cpp \
    source/unittest.cpp \
    source/util/shape.cpp \
    source/ProcessManager/report.cpp \
    source/ProcessManager/processitem.cpp \
    source/ProcessManager/processmanagerpcounter.cpp \
    source/ProcessManager/processmanagerfactory.cpp \
    source/ProcessManager/processmanagertransform.cpp \
    source/ProcessManager/processmanagerautocontrast.cpp

HEADERS += \
    source/util/random.h \
    source/util/util.h \
    nutilapplication.h \
    source/util/buffer2d.h \
    source/util/counter.h \
    mainwindow.h \
    node.h \
    source/ltiff.h \
    source/util/cinifile.h \
    source/nauto.h \
    source/ProcessManager/nutilprocess.h \
    source/ProcessManager/processmanager.h \
    source/util/lmessage.h \
    source/util/limage.h \
    source/util/area.h \
    source/util/atlaslabel.h \
    source/util/flat2d.h \
    source/LBook/lbook.h \
    source/LBook/lbookxlnt.h \
    source/unittest.h \
    source/util/shape.h \
    source/ProcessManager/report.h \
    source/ProcessManager/processitem.h \
    source/ProcessManager/processmanagerpcounter.h \
    source/ProcessManager/processmanagerfactory.h \
    source/ProcessManager/processmanagertransform.h \
    source/ProcessManager/processmanagerautocontrast.h

FORMS    += mainwindow.ui

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../tiff-4.0.9/libtiff/ -llibtiff
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../tiff-4.0.9/libtiff/ -llibtiffd
#else:unix: LIBS += -L$$PWD/../tiff-4.0.9/libtiff/ -llibtiff

#INCLUDEPATH += $$PWD/../tiff-4.0.9/libtiff
#DEPENDPATH += $$PWD/../tiff-4.0.9/libtiff

unix|win32: LIBS += -L$$PWD/lib/ -llibtiff

INCLUDEPATH += $$PWD/lib/libtiff
INCLUDEPATH += C:\Users\leuat\Documents\GitHub\TestLibraries\xlnt-master\include
DEPENDPATH += $$PWD/lib/libtiff

LIBS += -L$$PWD/lib/ -lxlnt

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/libxl-3.8.1.0/lib64/ -llibxl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/libxl-3.8.1.0/lib64/ -llibxl
else:unix: LIBS += -L$$PWD/lib/libxl-3.8.1.0/lib64/ -llibxl

INCLUDEPATH += $$PWD/lib/libxl-3.8.1.0/include_cpp
DEPENDPATH += $$PWD/lib/libxl-3.8.1.0/include_cpp
