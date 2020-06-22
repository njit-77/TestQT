#pragma once

#include "exercise7_global.h"
#include "ui_mainwindow.h"

namespace Ui {
	class MainWindow;
}

class EXERCISE7_EXPORT MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	Ui::MainWindow *ui;
};