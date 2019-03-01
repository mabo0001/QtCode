/***************************************************************************************************
**      2018-06-19  ITestSpec 测试光谱数据接口。
***************************************************************************************************/

#ifndef ITESTSPEC_H
#define ITESTSPEC_H

#include "ITestData.h"
#include "HeData/HDataGlobal.h"

HE_DATA_BEGIN_NAMESPACE
class ISpecCalibrate;
HE_DATA_END_NAMESPACE
HE_DATA_USE_NAMESPACE

HE_CONTROLLER_BEGIN_NAMESPACE

class ITestSpec : virtual public ITestData
{
public:
    // 设置校准数据
    virtual void setCalibrate(ISpecCalibrate *) = 0;
    // 设置积分时间
    virtual void setIntegralTime(double value) = 0;
    // 设置采样数据
    virtual bool setSample(QVector<double> value, bool avg = false) = 0;
};

HE_CONTROLLER_END_NAMESPACE

#endif // ITESTSPECTRUM_H
