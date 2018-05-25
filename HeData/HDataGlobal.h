#ifndef HEDATA_GLOBAL_H
#define HEDATA_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HE_BUILD_DATA_LIB)
#  define HE_DATA_EXPORT Q_DECL_EXPORT
#else
#  define HE_DATA_EXPORT Q_DECL_IMPORT
#endif

#define HE_DATA_NAMESPACE HeData

#ifdef HE_DATA_NAMESPACE
#  define HE_DATA_BEGIN_NAMESPACE namespace HE_DATA_NAMESPACE {
#  define HE_DATA_END_NAMESPACE }
#  define HE_DATA_USE_NAMESPACE using namespace HE_DATA_NAMESPACE;
#else
#  define HE_DATA_BEGIN_NAMESPACE
#  define HE_DATA_END_NAMESPACE
#  define HE_DATA_USE_NAMESPACE
#endif

HE_DATA_BEGIN_NAMESPACE
HE_DATA_END_NAMESPACE

#endif // HEDATA_GLOBAL_H