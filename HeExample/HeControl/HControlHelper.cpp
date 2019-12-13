#include "HControlHelper.h"
#include <QtCore/QTranslator>
#include <QtCore/QTime>
#include <QtGui/QScreen>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

HE_CONTROL_BEGIN_NAMESPACE

void HControlHelper::initTranslator()
{
    // 加载鼠标右键菜单翻译文件
    auto t1 = new QTranslator(qApp);
    t1->load(":/translator/qt_zh_CN.qm");
    qApp->installTranslator(t1);

    // 加载富文本框鼠标右键菜单翻译文件
    auto t2 = new QTranslator(qApp);
    t2->load(":/translator/textEdit.qm");
    qApp->installTranslator(t2);
}

void HControlHelper::centerWidget(QWidget *widget)
{
    auto size = QApplication::primaryScreen()->availableSize();
    widget->move((size.width() - widget->width()) / 2, (size.height() - widget->height()) / 2);
    widget->setFixedSize(widget->width(), widget->height());
}

QString HControlHelper::runTime(QDateTime start, QDateTime end)
{
    qint64 sec = start.secsTo(end);
    int day = 0;
    int hour = 0;
    int minute = 0;
    int second = 0;
    while (sec > 0)
    {
        second++;
        if (second == 60)
        {
            minute++;
            second = 0;
        }
        if (minute == 60)
        {
            hour++;
            minute = 0;
        }
        if (hour == 24)
        {
            day++;
            hour = 0;
        }
        sec--;
    }
    return QString("%1天 %2时 %3分 %4秒").arg(day).arg(hour).arg(minute).arg(second);
}

HE_CONTROL_END_NAMESPACE
