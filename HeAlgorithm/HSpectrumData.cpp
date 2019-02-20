#include "HSpectrumData.h"

HE_ALGORITHM_BEGIN_NAMESPACE

HSpectrumData::HSpectrumData()
{
    clear();
}

void HSpectrumData::clear()
{
    Energy.clear();
    TotalEnergy = 0.0;
    MaxEnergy = 0.0;
    PeakWave = 0.0;
    Bandwidth = 0.0;
    EnergyRatio = 0.0;
    RedRatio = 0.0;
    GreenRadio = 0.0;
    BlueRatio = 0.0;
    VisionEnergy = 0.0;
    CoordinateXy = QPointF(0.0, 0.0);
    CoordinateUv = QPointF(0.0, 0.0);
    CoordinateUvp = QPointF(0.0, 0.0);
    ColorTemperature = 2300.0;
    Duv = 0.0;
    DominantWave = 0.0;
    ColorPurity = 0.0;
    RenderingIndex.fill(0, 14);
    RenderingIndexAvg = 0.0;
    Luminous = 0.0;
    SDCM = 0;
}

HE_ALGORITHM_END_NAMESPACE