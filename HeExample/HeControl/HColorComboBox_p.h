#ifndef HCOLORCOMBOBOX_P_H
#define HCOLORCOMBOBOX_P_H

#include "HColorComboBox.h"

HE_CONTROL_BEGIN_NAMESPACE

class HColorModel;

class HColorComboBoxPrivate
{
public:
    HColorModel *model = nullptr;
    bool colorDialogEnabled = false;
};

HE_CONTROL_END_NAMESPACE

#endif // HCOLORCOMBOBOX_P_H