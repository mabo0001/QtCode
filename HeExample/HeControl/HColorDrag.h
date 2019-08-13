/***************************************************************************************************
**      2019-07-31  HColorDrag
***************************************************************************************************/

#ifndef HCOLORDRAG_H
#define HCOLORDRAG_H

#include "HControlGlobal.h"
#include <QtGui/QDrag>

HE_CONTROL_BEGIN_NAMESPACE

class HColorDrag : public QDrag
{
    Q_OBJECT

public:
    HColorDrag(QWidget *source, const QColor &color, const QString &name);
};

HE_CONTROL_END_NAMESPACE

#endif // HCOLORDRAG_H
