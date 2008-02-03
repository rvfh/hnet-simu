#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)

# This contains version information
AC_INIT([NULL],[0.0],[herve@lucidia.net])
AC_SUBST(LIB_VERSION, [0:0:0])

AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADER([config.h])
AC_LANG([C++])

# Compiler options
AC_ARG_ENABLE(debug,
    AC_HELP_STRING(--enable-debug, [Compile with symbols (Default = no)]),
    enable_debug=$enableval, enable_debug=no)
CXXWARN="-Wall -Wundef -Wno-trigraphs -fno-strict-aliasing -fno-common"
CWARN="$CXXWARN -Wstrict-prototypes"
if test "$enable_debug" = "yes" ; then
    CFLAGS="$CFLAGS $CWARN -g -D_DEBUG"
    CXXFLAGS="$CXXFLAGS $CXXWARN -g -D_DEBUG"
else
    CFLAGS="$CFLAGS $CWARN -O2"
    CXXFLAGS="$CXXFLAGS $CXXWARN -O2"
fi

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST

# Checks for library functions.

# Use colormake if available
AC_PATH_PROG(MAKE, hmake, make)

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
