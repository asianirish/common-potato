#ifndef HI_GLOBAL_H
#define HI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HILIB_LIBRARY)
#  define HILIB_EXPORT Q_DECL_EXPORT
#else
#  define HILIB_EXPORT Q_DECL_IMPORT
#endif

#endif // HI_GLOBAL_H
