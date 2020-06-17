#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Exercise3.h"

class Exercise3 : public QMainWindow
{
    Q_OBJECT

public:
    Exercise3(QWidget *parent = Q_NULLPTR);

private:
    Ui::Exercise3Class ui;
};
