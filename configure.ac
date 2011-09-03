dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.

AC_INIT(adventure_sphinx, 0.1)
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AM_MAINTAINER_MODE

AC_PROG_CXX
AC_PROG_CC
AC_LANG([C++]) 

AC_PROG_RANLIB

PKG_CHECK_MODULES(ADVENTURE_SPHINX, [sphinxbase pocketsphinx portaudio-2.0])

# Get ESTools library and include locations
AC_ARG_WITH([estools-include-path],
  [AS_HELP_STRING([--with-estools-include-path],
    [location of the estools headers, defaults to /usr/include/estools])],
  [ESTOOLS_CPPFLAGS="-I$withval"],
  [ESTOOLS_CPPFLAGS='-I/usr/include/estools'])
AC_SUBST([ESTOOLS_CPPFLAGS])

CPPFLAGS="$CPPFLAGS $ESTOOLS_CPPFLAGS"

AC_CHECK_HEADER(EST.h,[],AC_MSG_ERROR([Could not find estools headers.  Please specify the include directory with --with-estools-include-path=...]))

AC_ARG_WITH([estools-lib-path],
  [AS_HELP_STRING([--with-estools-lib-path],[location of the estools libraries])],
  [ESTOOLS_LIBS="-L$withval -lestools -lestbase -leststring"],
  [ESTOOLS_LIBS='-lestools -lestbase -leststring'])
AC_SUBST([ESTOOLS_LIBS])

LIBS="$ESTOOLS_LIBS $LIBS"
AC_MSG_CHECKING([estools libraries])
AC_LINK_IFELSE(AC_LANG_PROGRAM([#include <EST.h>],[EST_String dummy])
	,AC_MSG_RESULT([yes]),
	AC_MSG_RESULT([no])
	AC_MSG_ERROR([Could not find estools library.  Please specify the library path with --with-estools-lib-path=...]))

# Get Festival library and include locations
AC_ARG_WITH([festival-include-path],
  [AS_HELP_STRING([--with-festival-include-path],
    [location of the festival headers, defaults to /usr/include/festival])],
  [FESTIVAL_CPPFLAGS="-I$withval"],
  [FESTIVAL_CPPFLAGS='-I/usr/include/festival'])
AC_SUBST([FESTIVAL_CPPFLAGS])

CPPFLAGS="$CPPFLAGS $FESTIVAL_CPPFLAGS"

AC_CHECK_HEADER(festival.h,[] ,AC_MSG_ERROR([Could not find festival headers.  Please specify the include directory with --with-festival-include-path=...]))

AC_ARG_WITH([festival-lib-path],
  [AS_HELP_STRING([--with-festival-lib-path], [location of the festival libraries])],
  [FESTIVAL_LIBS="-L$withval -lFestival"],
  [FESTIVAL_LIBS='-lFestival'])
AC_SUBST([FESTIVAL_LIBS])

LIBS="$FESTIVAL_LIBS $LIBS"
AC_MSG_CHECKING([festival libraries])
AC_LINK_IFELSE(AC_LANG_PROGRAM([#include <festival.h>],[festival_initialize(TRUE,10000)])
	,AC_MSG_RESULT([yes]),
	AC_MSG_RESULT([no])
	AC_MSG_ERROR([Could not find estools library.  Please specify the library path with --with-estools-lib-path=...]))

AC_OUTPUT([
Makefile
src/Makefile
])

