#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Exercise6.h"

class Exercise6 : public QMainWindow
{
    Q_OBJECT

public:
    Exercise6(QWidget *parent = Q_NULLPTR);

private:
    Ui::Exercise6Class ui;
};
