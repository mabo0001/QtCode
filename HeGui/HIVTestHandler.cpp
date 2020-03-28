#include "HIVTestHandler_p.h"
#include "IMainWindow.h"
#include "HIVTestWidget.h"
#include "HGuiHelper.h"
#include <QtCore/QDebug>

HE_GUI_BEGIN_NAMESPACE

HIVTestHandler::HIVTestHandler(QObject *parent) :
    HAbstractGuiHandler(*new HIVTestHandlerPrivate, parent)
{
}

HIVTestHandler::~HIVTestHandler()
{
    qDebug() << __func__;
}

void HIVTestHandler::initialize(QVariantMap /*param*/)
{

}

QString HIVTestHandler::typeName()
{
    return "HIVTestHandler";
}

void HIVTestHandler::execute(QObject */*sender*/, QVariantMap /*param*/)
{
    Q_D(HIVTestHandler);
    auto w = HGuiHelper::decoratorInMainWindow(new HIVTestWidget, d->mainWindow);
    d->mainWindow->openWidget(w);
}

HE_GUI_END_NAMESPACE
