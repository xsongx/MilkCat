#-*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(MilkCat, 0.4.1, ling032x@gmail.com)
AC_CONFIG_AUX_DIR([scripts])

AC_PROG_CC
AC_PROG_CXX
AC_PROG_RANLIB
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_MACRO_DIR([m4])
LT_INIT

# Set the model dir
pkgdatadir=${datadir}/${PACKAGE}

AC_CHECK_HEADER(iconv.h, [], AC_MSG_ERROR([the iconv header is missing!]))
AC_CHECK_LIB(iconv, iconv, [LIBICONV="-liconv"])
AC_SUBST([LIBICONV])

AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
