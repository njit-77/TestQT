#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "TestQT.h"

#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QDebug>
#include <QLineEdit>
#include <QInputDialog>
#include <QString>
#include <QMessageBox>

TestQT::TestQT(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton, &QPushButton::clicked, this, [&]()
		{
			if (false)
			{
				// QFileDialog
				QString file_name = QFileDialog::getOpenFileName(this, "标题", ".", "*.txt");
				qDebug() << file_name;


				//QFileDialog fd;

				//// 设置是打开还是保存文件对话框 AcceptMode（2个枚举）
				///*
				//* QFileDialog::AcceptOpen 文件对话框为打开类型
				//* QFileDialog::AcceptSave 文件对话框为保存类型
				//*/
				//fd.setAcceptMode(QFileDialog::AcceptOpen);

				//// 设置对话框显示信息的详细程度（2个枚举）
				///*
				//* QFileDialog::Detail 详细
				//* QFileDialog::List 仅列表
				//*/
				//fd.setViewMode(QFileDialog::Detail);

				//// 设置点击OK后，对话框返回什么（4个枚举）
				///*
				//* QFileDialog::AnyFile 文件名，无论是否存在
				//* QFileDialog::ExistingFile 存在的，单个文件名
				//* QFileDialog::Directory 文件夹名
				//* QFileDialog::ExistingFiles 多文件
				//*/
				//fd.setFileMode(QFileDialog::AnyFile);

				//// 设置标题
				//fd.setWindowTitle("标题");

				//// 设置默认后缀
				//fd.setDefaultSuffix("txt");

				//// 获取对话框中的目录地址
				//QDir dir = fd.directory();
			}
			if (false)
			{
				// QColorDialog
				QColor color = QColorDialog::getColor(Qt::black);
				if (color.isValid())
				{
					qDebug() << color.redF() << color.greenF() << color.blueF();
				}
			}
			if (false)
			{
				// QFontDialog
				bool ok;
				QFont font = QFontDialog::getFont(&ok, QFont("Helvetica [Cronyx]", 10));
				qDebug() << ok;
				if (ok)
				{
					// font被设置为用户选择的字体
				}
				else
				{
					// 用户取消这个对话框，font被设置为初始值，在这里就是Helvetica [Cronyx], 10
				}
			}
			if (false)
			{
				// QInputDialog
				if (false)
				{
					// 输入字符串
					QString dlgTitle = "输入文字对话框";
					QString txtLabel = "请输入文件名";
					QString defaultInput = "新建文件.txt";
					QLineEdit::EchoMode echoMode = QLineEdit::Normal; // 正常文字输入
																	  // QLineEdit::EchoMode echoMode = QLineEdit::Password; // 密码输入

					bool ok = false;
					QString text = QInputDialog::getText(this, dlgTitle, txtLabel, echoMode, defaultInput, &ok);
					if (ok && !text.isEmpty())
						ui.plainTextEdit->append(text);
				}
				if (false)
				{
					// 输入整数
					QString dlgTitle = "输入整数对话框";
					QString txtLabel = "设置字体大小";
					int defaultValue = ui.plainTextEdit->font().pointSize(); // 现有字体大小
					int minValue = 6, maxValue = 50, stepValue = 1; // 范围，步长

					bool ok = false;
					int inputValue = QInputDialog::getInt(this, dlgTitle, txtLabel, defaultValue, minValue, maxValue, stepValue, &ok);
					if (ok)
					{
						QFont font = ui.plainTextEdit->font();
						font.setPointSize(inputValue);
						ui.plainTextEdit->setFont(font);
					}
				}
				if (false)
				{
					// 输入浮点数
					QString dlgTitle = "输入浮点数对话框";
					QString txtLabel = "输入一个浮点数";
					float defaultValue = (float)3.13;

					float minValue = 0, maxValue = 10000; // 范围
					int decimals = 2; // 小数点位数

					bool ok = false;
					float inputValue = QInputDialog::getDouble(this, dlgTitle, txtLabel, defaultValue, minValue, maxValue, decimals, &ok);

					if (ok) // 确认选择
					{
						QString str = QString::asprintf("输入了一个浮点数:%.2f", inputValue);
						ui.plainTextEdit->append(str);
					}
				}
				if (false)
				{
					// 条目选择输入
					QStringList items;
					items << "优秀 " << "良好 " << "合格 " << "不合格";

					QString dlgTitle = "条目选择对话框";
					QString txtLabel = "请选择级别";
					int curIndex = 0; // 初始选择项
					bool editable = false; // ComboBox是否可编辑
					bool ok = false;
					QString text = QInputDialog::getItem(this, dlgTitle, txtLabel, items, curIndex, editable, &ok);

					if (ok && !text.isEmpty())
					{
						ui.plainTextEdit->append(text);
					}
				}
			}
			if (true)
			{
				// QMessageBox

				// Information
				{
					QString dlgTitle = "information消息框";
					QString strInfo = "文件已经打开，字体大小已设置";
					QMessageBox::information(this, dlgTitle, strInfo, QMessageBox::StandardButton::Ok, QMessageBox::StandardButton::NoButton);
				}

				// Warning
				{
					QString dlgTitle = "warning消息框";
					QString strInfo = "文件内容已经被修改 ";
					QMessageBox::information(this, dlgTitle, strInfo);
				}

				// Critical
				{
					QString dlgTitle = "critical消息框";
					QString strInfo = "有不明程序访问网络 ";
					QMessageBox::information(this, dlgTitle, strInfo);
				}

				// About
				{
					QString dlgTitle = "about消息框";
					QString strInfo = "我开发的数据查看软件 V1.0 \n 保留所有版权 ";
					QMessageBox::information(this, dlgTitle, strInfo);
				}

				// 确认选择对话框
				{
					QString dlgTitle = "Question消息框";
					QString strInfo = "文件已经被修改，是否保存修改？";

					QMessageBox::StandardButton defaultBtn = QMessageBox::NoButton; // 缺省按钮

					QMessageBox::StandardButton result; // 返回选择的按钮
					result = QMessageBox::question(this, dlgTitle, strInfo, QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, defaultBtn);

					if (QMessageBox::Yes == result)
					{
						ui.plainTextEdit->append("Question消息框：Yes 被选择");
					}
					else if (QMessageBox::No == result)
					{
						ui.plainTextEdit->append("Question消息框：No 被选择");
					}
					else if (QMessageBox::Cancel == result)
					{
						ui.plainTextEdit->append("Question消息框：Cancel 被选择");
					}
					else
					{
						ui.plainTextEdit->append("Question消息框：无选择");
					}
				}
			}
		});
}
