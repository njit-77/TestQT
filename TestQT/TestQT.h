#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestQT.h"

class TestQT : public QMainWindow
{
    Q_OBJECT

public:
    TestQT(QWidget *parent = Q_NULLPTR);

private:
    Ui::TestQTClass ui;
};
