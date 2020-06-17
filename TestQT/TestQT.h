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
		PROXY_NONE,     //没有代理

		PROXY_BROWSER,   //浏览器代理

		PROXY_HTTP,      //HTTP代理
		PROXY_SOCKS4,    //SOCK4代理
		PROXY_SOCK5,     //SOCK5代理 
	}Proxy_Types;

	Q_ENUM(Proxy_Types)

};
