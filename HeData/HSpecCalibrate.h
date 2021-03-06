/***************************************************************************************************
**      2018-06-19  HSpecCalibrate 光谱校准数据类。
***************************************************************************************************/

#ifndef HSPECCALIBRATE_H
#define HSPECCALIBRATE_H

#include "ISpecCalibrate.h"

HE_DATA_BEGIN_NAMESPACE

class HSpecCalibratePrivate;

class HSpecCalibrate : public ISpecCalibrate
{
public:
    explicit HSpecCalibrate();
    virtual ~HSpecCalibrate();

public:
    void initialize(QVariantMap param) override;
    QString typeName() override;

public:
    void readContent(QDataStream &) override;
    void writeContent(QDataStream &) override;
    QVector<uchar> toBinaryData() override;
    bool fromBinaryData(QVector<uchar> data) override;

public:
    IDataItem *item(SpecType type) override;
    QVariantMap testParam() override;

public:
    QVector<double> preprocess(QVector<double> value, bool fitting = true) override;
    QPolygonF calcEnergy(QVector<double> value) override;
    double calcLuminous(double value) override;
    int calcCommWaitTime(double &value) override;
    int checkIntegralTime(double value) override;
    int checkFrameOverflow(int size) override;
    int checkSampleOverflow(double value) override;
    double pelsToWave(double value) override;
    QVector<double> stdCurve() override;
    void setStdCurve(QVector<double> value) override;

protected:
    HSpecCalibrate(HSpecCalibratePrivate &p);

protected:
    QScopedPointer<HSpecCalibratePrivate> d_ptr;
};

HE_DATA_END_NAMESPACE

#endif // HSPECCALIBRATE_H
