TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

SOURCES += main.cpp \
    core/database.cpp \
    core/entry.cpp \
    core/property.cpp \
    core/table.cpp \
    core/value.cpp \
    plugins/CSVImporter/csv.cpp \
    plugins/CSVImporter/csvimporter.cpp

HEADERS += \
    core/database.h \
    core/entry.h \
    core/property.h \
    core/table.h \
    core/utils.h \
    core/value.h \
    plugins/CSVImporter/csv.h \
    plugins/CSVImporter/csvimporter.h \
    common/utils.h
