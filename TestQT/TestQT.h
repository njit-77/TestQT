#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestQT.h"

#include <QMainWindow>
#include <QButtonGroup>
#include <QObjectUserData>
#include <QSortFilterProxyModel>
#include "itemdelegate.h"

class TestQT : public QMainWindow
{
    Q_OBJECT

public:
    TestQT(QWidget *parent = Q_NULLPTR);

private:
    Ui::TestQTClass ui;

	QButtonGroup* filterButtonGroup;
	ItemDelegate* delegate;
	QSortFilterProxyModel* proxyModel;
	QStandardItemModel* model;
	int totalNum;
	int redNum;
	int blueNum;
	int yellowNum;

	void initData();
	void updateButtonNum();

public:
	typedef enum
	{
		PROXY_NONE,     //û�д���

		PROXY_BROWSER,   //���������

		PROXY_HTTP,      //HTTP����
		PROXY_SOCKS4,    //SOCK4����
		PROXY_SOCK5,     //SOCK5���� 
	}Proxy_Types;

	Q_ENUM(Proxy_Types)

};
