#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "Exercise6.h"

#include <QPushButton>
#include <QFileInfo>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QTreeView>
#include <QFile>
#include <QByteArray>
#include <QStandardItemModel>
#include <QStandardItem>

Exercise6::Exercise6(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.treeView->setEditTriggers(QTreeView::NoEditTriggers);
	ui.treeView->setSelectionBehavior(QTreeView::SelectRows);
	ui.treeView->setSelectionMode(QTreeView::SingleSelection);
	ui.treeView->header()->hide();

	connect(ui.chooseButton, &QPushButton::clicked, this, [&]()
		{
			QString path = QFileDialog::getOpenFileName(this, "打开文件", "H:\\qt\\Qt5.5应用视频教程\\01-QT2017");
			if (path.isEmpty())
			{
				QMessageBox::warning(this, "警告", "打开失败");
			}
			else
			{
				ui.lineEdit->setText(path);

				QFile file(path);
				file.open(QFileDevice::ReadOnly);

				{
					// 释放旧数据内存空间
					QStandardItemModel* data = static_cast<QStandardItemModel*>(ui.treeView->model());
					if (data != nullptr)
					{
						data->clear();
					}
				}
				QStandardItemModel* model = new QStandardItemModel(ui.treeView);
				QByteArray array;
				int index = 1;
				while (!file.atEnd())
				{
					array = file.readLine();

					QStandardItem* item1 = new QStandardItem(QString::number(index++));
					item1->appendRow(new QStandardItem(QString(array)));

					model->appendRow(item1);
				}
				ui.treeView->setModel(model);
			}
		});

	connect(ui.deleteButton, &QPushButton::clicked, this, [&]()
		{
			QStandardItemModel* model = static_cast<QStandardItemModel*>(ui.treeView->model());
			QModelIndex selIndex = ui.treeView->currentIndex();
			if (selIndex.row() != -1)
			{
				QStandardItem* currentItem = model->itemFromIndex(selIndex);
				if (currentItem->parent())
				{
					// 选择二级节点
					QStandardItem* parent = currentItem->parent();

					// 通过二级节点查找对应一级节点QModelIndex
					selIndex = model->indexFromItem(parent);
					model->removeRow(selIndex.row());
				}
				else
				{
					// 选择一级节点
					model->removeRow(selIndex.row());
				}
			}
		});

	connect(ui.addButton, &QPushButton::clicked, this, []()
		{

		});

	connect(ui.saveAsButton, &QPushButton::clicked, this, []()
		{

		});
}
