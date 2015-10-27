infile(config.pri, SOLUTIONS_LIBRARY, yes): CONFIG += qtwinmigrate-uselib
TEMPLATE += fakelib
QTWINMIGRATE_LIBNAME = $$qtLibraryTarget(QtSolutions_MFCMigrationFramework-2.8)
TEMPLATE -= fakelib
QTWINMIGRATE_LIBDIR = $$PWD/lib
unix:qtwinmigrate-uselib:!qtwinmigrate-buildlib:QMAKE_RPATHDIR += $$QTWINMIGRATE_LIBDIR
