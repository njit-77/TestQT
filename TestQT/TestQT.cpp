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
				QString file_name = QFileDialog::getOpenFileName(this, "����", ".", "*.txt");
				qDebug() << file_name;


				//QFileDialog fd;

				//// �����Ǵ򿪻��Ǳ����ļ��Ի��� AcceptMode��2��ö�٣�
				///*
				//* QFileDialog::AcceptOpen �ļ��Ի���Ϊ������
				//* QFileDialog::AcceptSave �ļ��Ի���Ϊ��������
				//*/
				//fd.setAcceptMode(QFileDialog::AcceptOpen);

				//// ���öԻ�����ʾ��Ϣ����ϸ�̶ȣ�2��ö�٣�
				///*
				//* QFileDialog::Detail ��ϸ
				//* QFileDialog::List ���б�
				//*/
				//fd.setViewMode(QFileDialog::Detail);

				//// ���õ��OK�󣬶Ի��򷵻�ʲô��4��ö�٣�
				///*
				//* QFileDialog::AnyFile �ļ����������Ƿ����
				//* QFileDialog::ExistingFile ���ڵģ������ļ���
				//* QFileDialog::Directory �ļ�����
				//* QFileDialog::ExistingFiles ���ļ�
				//*/
				//fd.setFileMode(QFileDialog::AnyFile);

				//// ���ñ���
				//fd.setWindowTitle("����");

				//// ����Ĭ�Ϻ�׺
				//fd.setDefaultSuffix("txt");

				//// ��ȡ�Ի����е�Ŀ¼��ַ
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
					// font������Ϊ�û�ѡ�������
				}
				else
				{
					// �û�ȡ������Ի���font������Ϊ��ʼֵ�����������Helvetica [Cronyx], 10
				}
			}
			if (false)
			{
				// QInputDialog
				if (false)
				{
					// �����ַ���
					QString dlgTitle = "�������ֶԻ���";
					QString txtLabel = "�������ļ���";
					QString defaultInput = "�½��ļ�.txt";
					QLineEdit::EchoMode echoMode = QLineEdit::Normal; // ������������
																	  // QLineEdit::EchoMode echoMode = QLineEdit::Password; // ��������

					bool ok = false;
					QString text = QInputDialog::getText(this, dlgTitle, txtLabel, echoMode, defaultInput, &ok);
					if (ok && !text.isEmpty())
						ui.plainTextEdit->append(text);
				}
				if (false)
				{
					// ��������
					QString dlgTitle = "���������Ի���";
					QString txtLabel = "���������С";
					int defaultValue = ui.plainTextEdit->font().pointSize(); // ���������С
					int minValue = 6, maxValue = 50, stepValue = 1; // ��Χ������

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
					// ���븡����
					QString dlgTitle = "���븡�����Ի���";
					QString txtLabel = "����һ��������";
					float defaultValue = (float)3.13;

					float minValue = 0, maxValue = 10000; // ��Χ
					int decimals = 2; // С����λ��

					bool ok = false;
					float inputValue = QInputDialog::getDouble(this, dlgTitle, txtLabel, defaultValue, minValue, maxValue, decimals, &ok);

					if (ok) // ȷ��ѡ��
					{
						QString str = QString::asprintf("������һ��������:%.2f", inputValue);
						ui.plainTextEdit->append(str);
					}
				}
				if (false)
				{
					// ��Ŀѡ������
					QStringList items;
					items << "���� " << "���� " << "�ϸ� " << "���ϸ�";

					QString dlgTitle = "��Ŀѡ��Ի���";
					QString txtLabel = "��ѡ�񼶱�";
					int curIndex = 0; // ��ʼѡ����
					bool editable = false; // ComboBox�Ƿ�ɱ༭
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
					QString dlgTitle = "information��Ϣ��";
					QString strInfo = "�ļ��Ѿ��򿪣������С������";
					QMessageBox::information(this, dlgTitle, strInfo, QMessageBox::StandardButton::Ok, QMessageBox::StandardButton::NoButton);
				}

				// Warning
				{
					QString dlgTitle = "warning��Ϣ��";
					QString strInfo = "�ļ������Ѿ����޸� ";
					QMessageBox::information(this, dlgTitle, strInfo);
				}

				// Critical
				{
					QString dlgTitle = "critical��Ϣ��";
					QString strInfo = "�в�������������� ";
					QMessageBox::information(this, dlgTitle, strInfo);
				}

				// About
				{
					QString dlgTitle = "about��Ϣ��";
					QString strInfo = "�ҿ��������ݲ鿴��� V1.0 \n �������а�Ȩ ";
					QMessageBox::information(this, dlgTitle, strInfo);
				}

				// ȷ��ѡ��Ի���
				{
					QString dlgTitle = "Question��Ϣ��";
					QString strInfo = "�ļ��Ѿ����޸ģ��Ƿ񱣴��޸ģ�";

					QMessageBox::StandardButton defaultBtn = QMessageBox::NoButton; // ȱʡ��ť

					QMessageBox::StandardButton result; // ����ѡ��İ�ť
					result = QMessageBox::question(this, dlgTitle, strInfo, QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, defaultBtn);

					if (QMessageBox::Yes == result)
					{
						ui.plainTextEdit->append("Question��Ϣ��Yes ��ѡ��");
					}
					else if (QMessageBox::No == result)
					{
						ui.plainTextEdit->append("Question��Ϣ��No ��ѡ��");
					}
					else if (QMessageBox::Cancel == result)
					{
						ui.plainTextEdit->append("Question��Ϣ��Cancel ��ѡ��");
					}
					else
					{
						ui.plainTextEdit->append("Question��Ϣ����ѡ��");
					}
				}
			}
		});
}
