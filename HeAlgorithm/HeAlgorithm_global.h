#ifndef HEALGORITHM_GLOBAL_H
#define HEALGORITHM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HEALGORITHM)
#  define HEALGORITHM_EXPORT Q_DECL_EXPORT
#else
#  define HEALGORITHM_EXPORT Q_DECL_IMPORT
#endif

#endif // HEALGORITHM_GLOBAL_H
