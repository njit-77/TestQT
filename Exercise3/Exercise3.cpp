#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "Exercise3.h"
#include "SearchHighLight.h"

#include <iostream>
#include <QListView>
#include <QStandardItemModel>
#include <QGroupBox>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextFrame>
#include <QSyntaxHighlighter>

Exercise3::Exercise3(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// QStringList
	QStringList* strList = new QStringList;
	strList->append("I_am_a_student");
	strList->append("You_are_a_student");
	strList->append("1_2_3_77_9_sam");
	strList->append("You_Hongye");
	strList->append("1_time");

	// QStandardItemModel
	QStandardItemModel* model = new QStandardItemModel(this);
	foreach(auto var, *strList)
	{
		model->appendRow(new QStandardItem(var.mid(0, 1)));
	}

	// QListView
	QListView* listView = new QListView(this);
	listView->resize(100, 200);
	listView->move(5, 20);
	listView->setModel(model);

	// QTextEdit
	QTextEdit* textEdit = new QTextEdit;
	textEdit->setFontWeight(QFont::Light);
	textEdit->setFontFamily("宋体");
	textEdit->setReadOnly(true);
	textEdit->setFontPointSize(11);
	foreach(auto var, *strList)
	{
		textEdit->append(var);
	}

	// QLineEdit
	QLineEdit* lineEdit = new QLineEdit;

	// QVBoxLayout
	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(textEdit);
	layout->addWidget(lineEdit);
	layout->addStretch(3);

	// QGroupBox
	QGroupBox* groupBox = new QGroupBox(this);
	groupBox->resize(300, 200);
	groupBox->move(100, 20);
	groupBox->setLayout(layout);

	// Create and initialize search highlighting
	SearchHighLight* searchHighLight = new SearchHighLight(textEdit->document());

	connect(listView, &QListView::pressed, this, [searchHighLight, textEdit, lineEdit, strList](const QModelIndex& index)
		{
			// 显示到LineEdit
			auto selectIndex = index.row();
			lineEdit->setText((*strList)[selectIndex]);

			searchHighLight->searchText(lineEdit->text());
		});

	// QLineEdit
	QLineEdit* lineEdit2 = new QLineEdit(this);
	lineEdit2->move(5, 250);

	// QPushButton
	QPushButton* addBtn = new QPushButton("添加", this);
	addBtn->move(5, 290);
	connect(addBtn, &QPushButton::clicked, this, [strList, model, textEdit, lineEdit2]()
		{
			if (!lineEdit2->text().isEmpty())
			{
				auto text = lineEdit2->text();
				strList->append(text);

				model->appendRow(new QStandardItem(text.mid(0, 1)));
				textEdit->append(text);
			}
		});

	QWidget* pGroup1 = new QWidget;
	{
		// 偶数行
		QVBoxLayout* layout = new QVBoxLayout(pGroup1);
		for (size_t i = 0; i < (*strList).size(); i += 2)
		{
			layout->addWidget(new QLineEdit((*strList)[i]));
		}
	}

	QWidget* pGroup2 = new QWidget;
	{
		// 奇数行
		QVBoxLayout* layout = new QVBoxLayout(pGroup2);
		for (size_t i = 1; i < (*strList).size(); i += 2)
		{
			layout->addWidget(new QLineEdit((*strList)[i]));
		}
	}

	QTabWidget* tab = new QTabWidget(this);
	tab->addTab(pGroup1, "偶数行");
	tab->addTab(pGroup2, "奇数行");
	tab->move(420, 20);
	tab->resize(200, 150);
}
