/***************************************************************************************************
**      2019-07-31  HColorButton
***************************************************************************************************/

#ifndef HCOLORBUTTON_H
#define HCOLORBUTTON_H

#include "HControlGlobal.h"
#include <QtWidgets/QPushButton>

HE_CONTROL_BEGIN_NAMESPACE

class HColorButtonPrivate;

class HColorButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(QStringList colors READ colors WRITE setColors)
    Q_PROPERTY(QColor currentColor READ currentColor WRITE setCurrentColor)
    Q_PROPERTY(bool dragEnabled READ isDragEnabled WRITE setDragEnabled)
    Q_PROPERTY(bool showName READ isShowName WRITE setShowName)

public:
    explicit HColorButton(QWidget *parent = nullptr);
    ~HColorButton() override;

signals:
    void colorPicked(const QColor &);

public:
    QStringList colors() const;
    QColor currentColor() const;
    bool isDragEnabled() const;
    bool isShowName() const;

public slots:
    void setStandardColors();
    void addColor(const QColor &color, const QString &name);
    void clear();
    void setColors(const QStringList &);
    void setCurrentColor(const QColor &);
    void setDragEnabled(bool b);
    void setShowName(bool showName);

protected:
    HColorButton(HColorButtonPrivate &p, QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;
    void dragEnterEvent(QDragEnterEvent *) override;
    void dropEvent(QDropEvent *) override;
    void setCurrentIndex(const QModelIndex &);
    QString findStandardColorName(const QColor &color);
    QSize calcSize();
    void showPopup();

protected:
    QScopedPointer<HColorButtonPrivate> d_ptr;

private:
    void init();
};

HE_CONTROL_END_NAMESPACE

#endif // HCOLORBUTTON_H