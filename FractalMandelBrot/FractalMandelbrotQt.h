#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FractalMandelbrotQt.h"

class FractalMandelbrotQt : public QMainWindow
{
    Q_OBJECT

public:
    FractalMandelbrotQt(QWidget *parent = Q_NULLPTR);

private:
    Ui::FractalMandelbrotQtClass ui;
};
