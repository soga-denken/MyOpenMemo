#ifndef MYDIALOG_GLOBAL_H
#define MYDIALOG_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MYDIALOG_LIBRARY)
#  define MYDIALOG_EXPORT Q_DECL_EXPORT
#else
#  define MYDIALOG_EXPORT Q_DECL_IMPORT
#endif

#endif // MYDIALOG_GLOBAL_H
