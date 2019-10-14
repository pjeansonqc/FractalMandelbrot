#include "stdafx.h"
#include "FractalMandelbrotQt.h"
#include <QtWidgets/QApplication>
#include <QImage>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FractalMandelbrotQt w;
    w.show();
    return a.exec();
}
