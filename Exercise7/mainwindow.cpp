#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "mainwindow.h"

#include <QPushButton>
#include <QFileInfo>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QFile>
#include <QByteArray>
#include <QStandardItemModel>
#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	ui->treeView->setEditTriggers(QTreeView::NoEditTriggers);
	ui->treeView->setSelectionBehavior(QTreeView::SelectRows);
	ui->treeView->setSelectionMode(QTreeView::SingleSelection);
	ui->treeView->header()->hide();

	connect(ui->chooseButton, &QPushButton::clicked, this, [&]()
	{
		QString path = QFileDialog::getOpenFileName(this, "���ļ�", "H:\\qt\\Qt5.5Ӧ����Ƶ�̳�\\01-QT2017");
		if (path.isEmpty())
		{
			QMessageBox::warning(this, "����", "��ʧ��");
		}
		else
		{
			ui->lineEdit->setText(path);

			QFile file(path);
			file.open(QFileDevice::ReadOnly);

			// �ͷž������ڴ�ռ�
			QStandardItemModel* data = static_cast<QStandardItemModel*>(ui->treeView->model());
			if (data != nullptr)
			{
				data->clear();
			}

			// ����������
			QStandardItemModel* model = new QStandardItemModel(ui->treeView);
			QByteArray array;
			int index = 1;
			while (!file.atEnd())
			{
				array = file.readLine();

				QStandardItem* item1 = new QStandardItem(QString::number(index++));
				item1->appendRow(new QStandardItem(QString(array)));

				model->appendRow(item1);
			}
			ui->treeView->setModel(model);

			file.close();
		}
	});

	connect(ui->deleteButton, &QPushButton::clicked, this, [&]()
	{
		QStandardItemModel* model = static_cast<QStandardItemModel*>(ui->treeView->model());
		QModelIndex selIndex = ui->treeView->currentIndex();
		if (selIndex.row() != -1)
		{
			QStandardItem* currentItem = model->itemFromIndex(selIndex);
			auto aa = currentItem->parent();
			if (currentItem->parent())
			{
				// �����ڵ�
				QStandardItem *parent = currentItem->parent();

				// ���Ҷ����ڵ�����Ӧ��һ���ڵ�
				selIndex = model->indexFromItem(parent);
			}
			model->removeRow(selIndex.row());

			// ����ˢ��һ���ڵ�
			for (int i = 0, Count = model->rowCount(); i < Count; i++)
			{
				QStandardItem* item = model->invisibleRootItem()->child(i, 0);
				item->setText(QString::number(i + 1));
			}
		}
	});

	connect(ui->addButton, &QPushButton::clicked, this, [&]()
	{
		QStandardItemModel* model = static_cast<QStandardItemModel*>(ui->treeView->model());
		QModelIndex selIndex = ui->treeView->currentIndex();
		if (selIndex.row() != -1)
		{
			QStandardItem* currentItem = model->itemFromIndex(selIndex);
			auto aa = currentItem->parent();
			if (currentItem->parent())
			{
				// �����ڵ�
				QStandardItem *parent = currentItem->parent();

				// ���Ҷ����ڵ�����Ӧ��һ���ڵ�
				selIndex = model->indexFromItem(parent);
			}
			QStandardItem* data = new QStandardItem(QString::number(7));
			data->appendRow(new QStandardItem(QString(ui->lineEdit2->text())));

			model->insertRow(selIndex.row() + 1, data);

			// ����ˢ��һ���ڵ�
			for (int i = 0, Count = model->rowCount(); i < Count; i++)
			{
				QStandardItem* item = model->invisibleRootItem()->child(i, 0);
				item->setText(QString::number(i + 1));
			}
		}
		else
		{
			QStandardItem* data = new QStandardItem(QString::number(model->rowCount() + 1));
			data->appendRow(new QStandardItem(QString(ui->lineEdit2->text())));

			model->appendRow(data);
		}
	});

	connect(ui->saveAsButton, &QPushButton::clicked, this, [&]()
	{
		if (ui->lineEdit->text().isEmpty())
		{
			QMessageBox::warning(this, "����", "δ���ļ�");
		}
		else
		{
			QString path = QFileDialog::getSaveFileName(this, "�����ļ�", "H:\\qt\\Qt5.5Ӧ����Ƶ�̳�\\01-QT2017", "Text files (*.txt)");
			if (path.isEmpty())
			{
				QMessageBox::warning(this, "����", "����ʧ��");
			}
			QFile file(path);
			file.open(QFileDevice::WriteOnly);

			QStandardItemModel* model = static_cast<QStandardItemModel*>(ui->treeView->model());
			for (int i = 0, Count = model->rowCount(); i < Count; i++)
			{
				QStandardItem* item = model->invisibleRootItem()->child(i, 0)->child(0, 0);
				file.write(item->text().toUtf8());
			}
		}
	});
}

MainWindow::~MainWindow()
{
	delete ui;
}
