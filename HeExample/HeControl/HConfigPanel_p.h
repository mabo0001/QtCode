#ifndef HCONFIGPANEL_P_H
#define HCONFIGPANEL_P_H

#include "HConfigPanel.h"
#include "HAbstractMultiPanel_p.h"
#include <QtWidgets/QAbstractItemDelegate>

class QListWidget;
class QLabel;
class QStackedWidget;

HE_CONTROL_BEGIN_NAMESPACE

class HConfigPanelPrivate : public HAbstractMultiPanelPrivate
{
public:
    bool discarding = false;
    bool saving = false;
    bool applying = false;
    QLabel *title;
    QListWidget *view;
    QStackedWidget *stack;
};

class HConfigPanelDelegate : public QAbstractItemDelegate
{
    Q_OBJECT

public:
    explicit HConfigPanelDelegate(QObject *parent = nullptr);

public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

HE_CONTROL_END_NAMESPACE

#endif // HCONFIGPANEL_P_H