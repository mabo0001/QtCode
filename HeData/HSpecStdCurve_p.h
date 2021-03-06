#ifndef HSPECSTDCURVE_P_H
#define HSPECSTDCURVE_P_H

#include "HSpecStdCurve.h"
#include "HAbstractDataItem_p.h"
#include <QtCore/QVector>

HE_DATA_BEGIN_NAMESPACE

class HSpecStdCurvePrivate : public HAbstractDataItemPrivate
{
public:
    QVector<double> curve;
};

HE_DATA_END_NAMESPACE

#endif // HSPECSTDCURVE_P_H
