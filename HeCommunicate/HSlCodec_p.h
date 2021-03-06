#ifndef HSLCODEC_P_H
#define HSLCODEC_P_H

#include "HAbstractCodec_p.h"
#include "HSlCodec.h"
#include <QtCore/QVector>

HE_COMMUNICATE_BEGIN_NAMESPACE

class HSlCodecPrivate : public HAbstractCodecPrivate
{
public:
    HSlCodecPrivate();

public:
    QVector<bool> encrypts;
    QVector<bool> checkCodes;
};

HE_COMMUNICATE_END_NAMESPACE

#endif // HSLCODEC_P_H
