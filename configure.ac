AC_INIT([MIPSSimulator],[1.0.0],[jcmjohnmatty@me.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_CONFIG_MACRO_DIRS([m4])
AC_PROG_CXX
AM_PROG_AR
LT_INIT
LT_INIT([enable-static])
LT_INIT([enable-shared])
AX_CXX_COMPILE_STDCXX_11([noext], [mandatory])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
	Makefile
	lib/Makefile
 	src/Makefile
	test/Makefile
])
AC_OUTPUT
