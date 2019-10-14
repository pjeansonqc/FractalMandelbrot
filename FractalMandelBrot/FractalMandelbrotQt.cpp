#include "stdafx.h"
#include "FractalMandelbrotQt.h"
#include "FractalCreator.h"
#include "RGB.h"
using namespace FractalMandelbrot;
FractalMandelbrotQt::FractalMandelbrotQt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    FractalCreator lfrac(800, 600, 10000);
    lfrac.addColorRange(0.0, 0.10, FM_RGB(0, 0, 255));
    lfrac.addColorRange(0.10, 0.25, FM_RGB(0, 128, 255));
    lfrac.addColorRange(0.25, 0.75, FM_RGB(0, 255, 255));
    lfrac.addColorRange(0.75, 1.0, FM_RGB(255, 255, 255));
    lfrac.addZoom(Zoom(295, 600 - 202, 0.1));
    lfrac.addZoom(Zoom(288, 600 - 304, 0.01));
    lfrac.run();
    QImage image(lfrac.getBitmap().getData(), 800, 600, QImage::Format_RGB888);
    
    ui.label->setPixmap(QPixmap::fromImage(image));
}
