Qt/MFC Migration Framework v2.8

The Qt/MFC Migration Framework tool assists in the migration of
existing Win32 or MFC applications to the Qt toolkit.

The project provides a set of classes that allow using Qt and
MFC/Win32 windows in the same application. User interface elements
developed with Qt can be embedded into an existing MFC or Win32
based user interface, and existing custom controls developed with
MFC or Win32 can be integrated into Qt widgets.

Notes:

When building this component as a library ("configure.bat
-library"), the default configuration includes MFC support. That
is, the MFC SDK must be present, otherwise compilation will fail.
To avoid this dependency (e.g. for usage with Visual Studio
Express editions, which do not include MFC), edit the
src/qtwinmigrate.pri file as explained in its comments before
building this component.

