#ifndef UNIQ_GLOBAL_H
#define UNIQ_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UNIQLIB_LIBRARY)
#  define UNIQLIB_EXPORT Q_DECL_EXPORT
#else
#  define UNIQLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // UNIQ_GLOBAL_H
