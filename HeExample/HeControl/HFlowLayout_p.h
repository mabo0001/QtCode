#ifndef HFLOWLAYOUT_P_H
#define HFLOWLAYOUT_P_H

#include "HFlowLayout.h"

HE_CONTROL_BEGIN_NAMESPACE

class HFlowLayoutPrivate
{
public:
    HFlowLayoutPrivate(int hSpace = -1, int vSpacing = -1);

public:
    QList<QLayoutItem *> items;
    int hSpacing;
    int vSpacing;
};

HE_CONTROL_END_NAMESPACE

#endif // HFLOWLAYOUT_P_H
