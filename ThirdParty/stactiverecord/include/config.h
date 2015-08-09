#pragma once

#define HAVE_SQLITE3
#define HAVE_MYSQL
//#define HAVE_POSTGRESQL

#if defined(_MSC_VER)

// Warning about: identifier was truncated to '255' characters in the debug information
#  pragma warning( disable : 4786 )
// Warning about: <type1> needs to have dll-interface to be used by clients of class <type2>
#  pragma warning( disable : 4251 )

#endif