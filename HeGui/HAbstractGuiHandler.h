#ifndef HABSTRACTGUIHANDLER_H
#define HABSTRACTGUIHANDLER_H

#include "IGuiHandler.h"

HE_GUI_BEGIN_NAMESPACE

class HAbstractGuiHandlerPrivate;

class HAbstractGuiHandler : public IGuiHandler
{
public:
    explicit HAbstractGuiHandler(QObject *parent = nullptr);
    ~HAbstractGuiHandler();

public:
    virtual void initialize(QVariantMap param) override;

protected:
    HAbstractGuiHandler(HAbstractGuiHandlerPrivate &p, QObject *parent = nullptr);

protected:
    QScopedPointer<HAbstractGuiHandlerPrivate> d_ptr;
};

HE_GUI_END_NAMESPACE

#endif // HABSTRACTGUIHANDLER_H