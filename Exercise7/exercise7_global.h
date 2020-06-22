#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(EXERCISE7_LIB)
#  define EXERCISE7_EXPORT Q_DECL_EXPORT
# else
#  define EXERCISE7_EXPORT Q_DECL_IMPORT
# endif
#else
# define EXERCISE7_EXPORT
#endif
