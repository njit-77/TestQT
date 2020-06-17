#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "TestQT.h"
#include "itemdelegate.h"
#include "itemdef.h"

#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QDebug>
#include <QLineEdit>
#include <QInputDialog>
#include <QString>
#include <QMessageBox>
#include <QToolButton>
#include <QButtonGroup>
#include <QRadioButton>
#include <QCheckBox>
#include <QLabel>
#include <QCommandLinkButton>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QComboBox>
#include <QMetaEnum>
#include <QDateTimeEdit>
#include <QGroupBox>
#include <QScrollArea>
#include <QProgressBar>
#include <QCalendarWidget>
#include <QLCDNumber>
#include <QTimer>


TestQT::TestQT(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	{
		// QDialog
		if (true)
		{
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
					if (false)
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
	}

	{
		// QPushButton
		if (false)
		{
			QPushButton* btn = new QPushButton;

			// btn应该依赖于主窗口
			btn->setParent(this);

			// btn显示文字
			btn->setText("我的天");
		}

		if (false)
		{
			QPushButton* btn = new QPushButton("我的天", this);

			// 移动窗口
			btn->move(100, 100);

			// 重置窗口大小
			resize(960, 640);

			// btn resize
			btn->resize(50, 50);

			//设置窗口标题名称
			this->setWindowTitle("我的天!");
		}
	}

	{
		// QToolButton
		if (false)
		{
			QToolButton* pButton = new QToolButton(this);

			// 设置按钮是否显示一个箭头
			pButton->setArrowType(Qt::LeftArrow);

			pButton->setText("Left Arrow");

			pButton->resize(QSize(100, 100));

			pButton->move(50, 50);

			// 设置按钮风格
			/* Qt::ToolButtonIconOnly		只显示图标
			 * Qt::ToolButtonTextOnly		只显示文本
			 * Qt::ToolButtonTextBesideIcon	文本显示在图标旁边
			 * Qt::ToolButtonTextUnderIcon	文本显示在图标下边
			 * Qt::ToolButtonFollowStyle	遵循QStyle::StyleHint
			 */
			pButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
			pButton->setStyleSheet("QToolButton{border: none; background: rgb(68, 69, 73); color: rgb(0, 160, 230);}");

			QAction* pAction = new QAction(this);
			pAction->setText("河南洛阳");

			pButton->setIconSize(QSize(48, 48));
			pAction->setToolTip("牡丹花");
			pButton->setDefaultAction(pAction);
			pButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
		}
	}

	{
		// QRadioButton
		if (false)
		{
			QButtonGroup* btnGroupFruits = new QButtonGroup(this);

			QRadioButton* radioButton11 = new QRadioButton("苹果", this);
			radioButton11->setChecked(true);
			radioButton11->move(20, 300);
			connect(radioButton11, &QRadioButton::clicked, this, [&]()
				{
					ui.plainTextEdit->append("苹果");
				});

			QRadioButton* radioButton12 = new QRadioButton("芒果", this);
			radioButton12->move(80, 300);
			connect(radioButton12, &QRadioButton::clicked, this, [&]()
				{
					ui.plainTextEdit->append("芒果");
				});

			QRadioButton* radioButton13 = new QRadioButton("土豆", this);
			radioButton13->move(140, 300);
			connect(radioButton13, &QRadioButton::clicked, this, [&]()
				{
					ui.plainTextEdit->append("土豆");
				});

			btnGroupFruits->addButton(radioButton11, 0);
			btnGroupFruits->addButton(radioButton12, 1);
			btnGroupFruits->addButton(radioButton13, 2);


			QButtonGroup* btnGroupVegetables = new QButtonGroup(this);

			QRadioButton* radioButton21 = new QRadioButton("土豆", this);
			radioButton21->setChecked(true);
			radioButton21->move(40, 330);
			connect(radioButton21, &QRadioButton::clicked, this, [&]()
				{
					ui.plainTextEdit->append("土豆");
				});

			QRadioButton* radioButton22 = new QRadioButton("青椒", this);
			radioButton22->move(40, 360);
			connect(radioButton22, &QRadioButton::clicked, this, [&]()
				{
					ui.plainTextEdit->append("青椒");
				});

			QRadioButton* radioButton23 = new QRadioButton("菠菜", this);
			radioButton23->move(40, 390);
			connect(radioButton23, &QRadioButton::clicked, this, [&]()
				{
					ui.plainTextEdit->append("菠菜");
				});
			btnGroupVegetables->addButton(radioButton21, 0);
			btnGroupVegetables->addButton(radioButton22, 1);
			btnGroupVegetables->addButton(radioButton23, 2);
		}
	}

	{
		// QCheckBox
		if (false)
		{
			// 三态模式
			QLabel* pLabel = new QLabel(this);
			pLabel->setText("Click CheckBox...");
			pLabel->resize(200, 30);
			pLabel->move(20, 410);

			QCheckBox* pCheckBox = new QCheckBox(this);
			pCheckBox->setText("三态复选框");
			pCheckBox->resize(200, 30);
			pCheckBox->move(20, 450);

			// 开启三态模式
			pCheckBox->setTristate();

			// 连接信号槽
			connect(pCheckBox, &QCheckBox::stateChanged, this, [&](int state)
				{
					if (Qt::Checked == state)
					{
						ui.plainTextEdit->append("Checked");
					}
					else if (Qt::PartiallyChecked == state)
					{
						ui.plainTextEdit->append("PartiallyChecked");
					}
					else if (Qt::Unchecked == state)
					{
						ui.plainTextEdit->append("Unchecked");
					}
				});
		}
	}

	{
		// QCommandLinkBut​​ton
		if (false)
		{
			QCommandLinkButton* cmmBtn = new QCommandLinkButton("Version", "Version Project", this);
			cmmBtn->setFlat(true);
			cmmBtn->move(250, 250);
			cmmBtn->resize(200, 100);
			connect(cmmBtn, &QCommandLinkButton::clicked, this, [&]()
				{

				});
		}
	}

	{
		// QDialogButtonBox
		if (false)
		{
			QDialogButtonBox* buttonBox = new QDialogButtonBox(Qt::Vertical, this);
			QGridLayout* layout = new QGridLayout();

			QPushButton* add = new QPushButton(QObject::tr("&Add"));
			QPushButton* reset = new QPushButton(QObject::tr("&Reset"));
			QPushButton* remove = new QPushButton(QObject::tr("&Remove"));
			QPushButton* help = new QPushButton(QObject::tr("Help"));

			buttonBox->addButton(add, QDialogButtonBox::ActionRole);
			buttonBox->addButton(reset, QDialogButtonBox::ActionRole);
			buttonBox->addButton(remove, QDialogButtonBox::ActionRole);
			buttonBox->addButton(help, QDialogButtonBox::ActionRole);

			connect(add, &QPushButton::clicked, this, [&]()
				{
					ui.plainTextEdit->append("Add Clicked...");
				});
			connect(reset, &QPushButton::clicked, this, [&]()
				{
					ui.plainTextEdit->append("Reset Clicked...");
				});
			connect(remove, &QPushButton::clicked, this, [&]()
				{
					ui.plainTextEdit->append("Remove Clicked...");
				});
			connect(help, &QPushButton::clicked, this, [&]()
				{
					ui.plainTextEdit->append("Help Clicked...");
				});

			buttonBox->move(160, 250);
			buttonBox->resize(100, 500);
			layout->addWidget(buttonBox, 0, 0, Qt::AlignCenter);
			setLayout(layout);
		}
	}

	{
		// QListView
		if (false)
		{
			initData();
			updateButtonNum();

			delegate = new ItemDelegate(this);
			filterButtonGroup = new QButtonGroup(this);

			// 设置互斥
			filterButtonGroup->setExclusive(true);

			filterButtonGroup->addButton(ui.allBtn);
			filterButtonGroup->addButton(ui.redBtn);
			filterButtonGroup->addButton(ui.blueBtn);
			filterButtonGroup->addButton(ui.yellowBtn);

			connect(filterButtonGroup, static_cast<void(QButtonGroup::*)(QAbstractButton*)>(&QButtonGroup::buttonClicked), this, [](QAbstractButton* button)
				{
					qDebug() << button->text();
				});

			ui.listView->setItemDelegate(delegate);       //为视图设置委托
			ui.listView->setSpacing(15);                  //为视图设置控件间距
			proxyModel = new QSortFilterProxyModel(ui.listView);
			proxyModel->setSourceModel(model);
			proxyModel->setFilterRole(Qt::UserRole);
			proxyModel->setDynamicSortFilter(true);
			ui.listView->setModel(proxyModel);                  //为委托设置模型
			ui.listView->setViewMode(QListView::IconMode); //设置Item图标显示
			ui.listView->setDragEnabled(false);            //控件不允许拖动

			connect(ui.allBtn, &QPushButton::clicked, this, [&]()
				{
					if (proxyModel)
					{
						proxyModel->setFilterFixedString(QString());
					}
				});
			connect(ui.redBtn, &QPushButton::clicked, this, [&]()
				{
					if (proxyModel)
					{
						proxyModel->setFilterFixedString(QString::number(S_RED));
					}
				});
			connect(ui.blueBtn, &QPushButton::clicked, this, [&]()
				{
					if (proxyModel)
					{
						proxyModel->setFilterFixedString(QString::number(S_BLUE));
					}
				});
			connect(ui.yellowBtn, &QPushButton::clicked, this, [&]()
				{
					if (proxyModel)
					{
						proxyModel->setFilterFixedString(QString::number(S_YELLOW));
					}
				});
			connect(ui.setRedBtn, &QPushButton::clicked, this, [&]()
				{
					QModelIndexList modelIndexList = ui.listView->selectionModel()->selectedIndexes();
					QModelIndexList sourceIndexList;
					foreach(QModelIndex modelIndex, modelIndexList)
					{
						sourceIndexList << proxyModel->mapToSource(modelIndex); //获取源model的modelIndex
					}

					foreach(QModelIndex sourceIndex, sourceIndexList)
					{
						ItemStatus status = (ItemStatus)(sourceIndex.data(Qt::UserRole).toInt());
						qDebug() << "Index : " << sourceIndex.row();

						switch (status) {
						case S_RED:
							redNum--;
							break;
						case S_BLUE:
							blueNum--;
							break;
						case S_YELLOW:
							yellowNum--;
							break;
						}

						status = S_RED;
						redNum++;

						model->setData(sourceIndex, status, Qt::UserRole);
					}
					this->updateButtonNum();
				});
		}
	}

	{
		// QTreeView
		if (false)
		{
			// 1、QTreeView常用设置项
			// 单元格不能编辑
			/*
			 * NoEditTriggers = 0,     不可编辑
			 * CurrentChanged = 1,     任何时候都能对单元格修改
			 * DoubleClicked = 2,      双击单元格
			 * SelectedClicked = 4,    单击已选中的内容
			 * EditKeyPressed = 8,     键盘的编辑键，如F2
			 * AnyKeyPressed = 16,     按下任意键就能修改
			 * AllEditTriggers = 31    以上条件全包括
			 */
			ui.treeView->setEditTriggers(QTreeView::NoEditTriggers);

			// 一次选中整行
			/*
			 * SelectItems,        选中单个单元格
			 * SelectRows,         选中一行
			 * SelectColumns       选中一列
			 */
			ui.treeView->setSelectionBehavior(QTreeView::SelectRows);

			// 单选，配合上面的整行就是一次选单行
			/*
			 * NoSelection,         不能选择
			 * SingleSelection,     单选
			 * MultiSelection,      多选，不用按ctrl键即可多选，选择新项时不取消之前选择，已选中的再选择会取消选择
			 * ExtendedSelection,   多选，按ctrl、shift键多选，选择新项时取消之前选择
			 * ContiguousSelection  多选，需要按ctrl或shift都是shift选中效果,即选中两次点击之间的所有元素
			 */
			ui.treeView->setSelectionMode(QTreeView::SingleSelection);

			// 每间隔一行颜色不一样，当有qss时该属性无效
			ui.treeView->setAlternatingRowColors(true);

			// 去掉鼠标移到单元格上时的虚线框
			ui.treeView->setFocusPolicy(Qt::NoFocus);

			// 2、列头相关设置
			// 隐藏列头
			//ui.treeView->header()->hide();
			// 最后一列自适应宽度
			ui.treeView->header()->setStretchLastSection(true);
			// 列头文字默认居中对齐
			ui.treeView->header()->setDefaultAlignment(Qt::AlignCenter);

			// 3，构造Model
			/*
			 * 此处如果不是static修饰，connect[QItemSelectionModel::currentChanged]
			 * 里面直接报错，查看发现获取的model数据地址是错误的，怀疑是局部变量生命周期没有那么久导致的
			 */
			static QStandardItemModel* model = new QStandardItemModel(ui.treeView);

			// 设置列头
			model->setHorizontalHeaderLabels(QStringList() << "序号" << "名称");
			for (int i = 0; i < 5; i++)
			{
				// 一级节点，加入mModel
				QList<QStandardItem*> items1;
				QStandardItem* item1 = new QStandardItem(QString::number(i));
				QStandardItem* item2 = new QStandardItem("一级节点");
				items1.append(item1);
				items1.append(item2);
				model->appendRow(items1);

				for (int j = 0; j < 5; j++)
				{
					// 二级节点,加入第1个一级节点
					QList<QStandardItem*> items2;
					QStandardItem* item3 = new QStandardItem(QString::number(j));
					QStandardItem* item4 = new QStandardItem("二级节点");
					items2.append(item3);
					items2.append(item4);
					item1->appendRow(items2);

					for (int k = 0; k < 5; k++)
					{
						// 三级节点,加入第1个二级节点
						QList<QStandardItem*> items3;
						QStandardItem* item5 = new QStandardItem(QString::number(k));
						QStandardItem* item6 = new QStandardItem("三级节点");
						items3.append(item5);
						items3.append(item6);
						item3->appendRow(items3);
					}
				}
			}

			// 4，应用model
			ui.treeView->setModel(model);

			// 一些项在应用model后设置
			// 5、设第一列初始宽度：第一列固定宽度
			ui.treeView->header()->resizeSection(0, 100);
			ui.treeView->header()->setSectionResizeMode(0, QHeaderView::Fixed);

			// 6、默认选中一级节点的第一行
			QModelIndex rootIndex = ui.treeView->rootIndex();
			QModelIndex selIndex = model->index(0, 0, rootIndex);
			ui.treeView->setCurrentIndex(selIndex);

			connect(ui.treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this, [&](const QItemSelection& selected, const QItemSelection& deselected)
				{
					// 选中内容变化，覆盖单选和多选的情况

					QItemSelectionModel* selections = ui.treeView->selectionModel();

					// 得到所有选中的index
					QModelIndexList indexes = selections->selectedIndexes();
					foreach(QModelIndex index, indexes)
					{
						// 从索引index获取item指针,mModel是tree的数据Model,这里是QStandardItemModel*类型
						QStandardItem* item = model->itemFromIndex(index);
						if (item)
						{
							//你的操作,比如取文本、取附带的data
							QString text = item->text();
							QString data1 = item->data(Qt::UserRole + 1).toString();
							QString data2 = item->data(Qt::UserRole + 2).toInt();
						}
					}
				});
			connect(ui.treeView->selectionModel(), &QItemSelectionModel::currentChanged, this, [&](const QModelIndex& current, const QModelIndex& previous)
				{
					// 当前选中index变化，单个
					QStandardItem* item = model->itemFromIndex(current);
					if (item)
					{
						//你的操作,同上
					}
				});
			connect(ui.treeView->selectionModel(), &QItemSelectionModel::currentRowChanged, this, [&](const QModelIndex& current, const QModelIndex& previous)
				{
					// 当前选中行变化，单行

					// 取选中的这行的第一个元素的index
					QModelIndex index = current.sibling(current.row(), 0);
					QStandardItem* item = model->itemFromIndex(index);
					if (item)
					{
						//你的操作,同上
					}
				});

			// 7、信号槽，右键菜单
			ui.treeView->setContextMenuPolicy(Qt::CustomContextMenu);

			connect(ui.treeView, &QTreeView::customContextMenuRequested, this, [&](const QPoint& pos)
				{
					QString qss = "QMenu{color:#E8E8E8;background:#4D4D4D;margin:2px;}\
                QMenu::item{padding:3px 20px 3px 20px;}\
                QMenu::indicator{width:13px;height:13px;}\
                QMenu::item:selected{color:#E8E8E8;border:0px solid #575757;background:#1E90FF;}\
                QMenu::separator{height:1px;background:#757575;}";

					QMenu menu;
					menu.setStyleSheet(qss);    //可以给菜单设置样式

					QModelIndex curIndex = ui.treeView->indexAt(pos);      //当前点击的元素的index
					QModelIndex index = curIndex.sibling(curIndex.row(), 0); //该行的第1列元素的index
					if (index.isValid())
					{
						//可获取元素的文本、data,进行其他判断处理
						//QStandardItem* item = mModel->itemFromIndex(index);
						//QString text = item->text();
						//QVariant data = item->data(Qt::UserRole + 1);
						//...

						// 添加一行菜单，进行展开
						menu.addAction("展开", this, [&](bool checked)
							{
								QModelIndex curIndex = ui.treeView->currentIndex();
								QModelIndex index = curIndex.sibling(curIndex.row(), 0); //同一行第一列元素的index
								if (index.isValid())
								{
									ui.treeView->expand(index);
								}
							});
						// 添加一个分隔线
						menu.addSeparator();
						menu.addAction("折叠", this, [&](bool checked)
							{
								QModelIndex curIndex = ui.treeView->currentIndex();
								QModelIndex index = curIndex.sibling(curIndex.row(), 0); //同一行第一列元素的index
								if (index.isValid())
								{
									ui.treeView->collapse(index);
								}
							});
					}
					// 显示菜单
					menu.exec(QCursor::pos());
				});
		}
	}

	{
		// QTableView
		if (false)
		{
			QTableView* tableView = new QTableView(this);
			tableView->resize(400, 400);
			tableView->move(280, 80);
			// 背景网格线设置 显示
			tableView->setShowGrid(true);

			// 网格背景画笔
			/*
			 * NoPen			无线
			 * SolidLine		实线
			 * DashLine			虚线
			 * DotLine			点线
			 * DashDotLine		虚点线
			 * DashDotDotLine	虚点点线
			 * CustomDashLine	自定义虚线
			 */
			tableView->setGridStyle(Qt::DotLine);

			// 排序功能
			tableView->setSortingEnabled(true);

			// 设置列表头
			QStandardItemModel* model = new QStandardItemModel;
			QStringList labels = QObject::trUtf8("频率,功率,误差").simplified().split(",");
			model->setHorizontalHeaderLabels(labels);

			// 定义item
			QStandardItem* item = 0;
			for (int i = 0; i < 10; i++)
			{
				item = new QStandardItem(QString("%1").arg(i));
				model->setItem(i, 0, item);
				item = new QStandardItem(QString("%1").arg(i * 2));
				model->setItem(i, 1, item);
				item = new QStandardItem(QString("%1").arg(i * 3));
				model->setItem(i, 2, item);
			}

			tableView->setStyleSheet("QTableView { border: none;"
				"selection-background-color: #8EDE21;"
				"color: red}");

			tableView->setModel(model);
		}
	}

	{
		// QComboBox
		if (false)
		{
			QComboBox* comboBox = new QComboBox(this);
			comboBox->move(20, 430);
			comboBox->setStyleSheet("QComboBox{border:1px solid gray;}"
				"QComboBox QAbstractItemView::item{height:20px;}" //下拉选项高度
				"QComboBox::down-arrow{image:url(:/icon/arrowdown);}" //下拉箭头
				"QComboBox::drop-down{border:0px;}"); //下拉按钮
			comboBox->setView(new QListView());

			comboBox->addItem("none", PROXY_NONE);
			comboBox->addItem("browser", PROXY_BROWSER);
			comboBox->addItem("http", PROXY_HTTP);
			comboBox->addItem("socks4", PROXY_SOCKS4);
			comboBox->addItem("socks5", PROXY_SOCK5);

			comboBox->setItemText(0, tr("no proxy"));
			comboBox->setItemText(1, tr("use browser"));
			comboBox->setItemText(2, tr("http"));
			comboBox->setItemText(3, tr("socks4"));
			comboBox->setItemText(4, tr("socks5"));

			connect(comboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, [&, comboBox](int)
				{
					Proxy_Types proxy_type = (Proxy_Types)(comboBox->currentIndex());
					QMetaEnum metaEnum = QMetaEnum::fromType<Proxy_Types>();
					ui.plainTextEdit->append(metaEnum.valueToKey(proxy_type));

					//{
					//	// enum转QString
					//	QString enum2string(int enumration)
					//	{
					//		QMetaEnum metaEnum = QMetaEnum::fromType<QNetworkReply::NetworkError>();
					//		return metaEnum.valueToKey(enumration);
					//	}

					//	// QString转enum
					//	int string2enum(QString enumration)
					//	{
					//		QMetaEnum metaEnum = QMetaEnum::fromType<QNetworkReply::NetworkError>();
					//		return metaEnum.keyToValue(enumration);
					//	}
					//}

				});
		}
	}

	{
		// QLineEdit
		if (false)
		{
			QLineEdit* lineEdit = new QLineEdit(this);
			lineEdit->resize(200, 30);
			lineEdit->move(20, 430);

			// setPlaceholderText()设置提示文字
			lineEdit->setPlaceholderText("电影、影人、影院、电视剧");

			// setEchoMode()设置模式
			/*
			 * Normal				默认，输入什么即显示什么
			 * NoEcho				任何输入都看不见
			 * Password				密码，一般是用小黑点覆盖你所输入的字符
			 * PasswordEchoOnEdit	编辑时输入字符显示输入内容，否则用小黑点代替
			 */
			lineEdit->setEchoMode(QLineEdit::Normal);

			// setAlignment()设置文本位置
			/*
			 * Qt::AlignLeft
			 * Qt::AlignCenter
			 * Qt::AlignRight
			 */
			lineEdit->setAlignment(Qt::AlignLeft);

			// setReadOnly()设置能否编辑
			/*
			* true
			* false
			*/
			lineEdit->setReadOnly(false);

			// setValidator()对输入进行限制
			/*
			 * lineEdit->setValidator(0);							无限制
			 * lineEdit->setValidator(new QIntValidator(lineEdit));	只能输入整数
			 *
			 {
				 // 实例，只能输入-180到180之间的小数，小数点后最多两位（可用于限制经纬度等）
				 QDoubleValidator* pDfValidator = new QDoubleValidator(-180.0, 180.0, 2, this);
				 pDfValidator->setNotation(QDoubleValidator::StandardNotation);
				 lineEdit->setValidator(new QIntValidator(lineEdit));
			 }
			 */
			 //QDoubleValidator *pDfValidator = new QDoubleValidator(-180, 180, 2, this);
			 //pDfValidator->setNotation(QDoubleValidator::StandardNotation);
			 //lineEdit->setValidator(pDfValidator);

			 // setInputMask()对输入进行限制
			 /*
			  * lineEdit->setInputMask("");
			  * lineEdit->setInputMask("+99 99 99 99 99;_");
			  *
			  {
				  lineEdit->setInputMask("0000-00-00");
				  lineEdit->setText("00000000");
				  lineEdit->setCursorPosition(0);
			  }
			  lineEdit->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA;#");
			  */
			  //lineEdit->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA-AAAAA");

			  // setMaxLength()设置可以输入的最多字符数
			  //lineEdit->setMaxLength(9);

			  // validator和inputmask的结合
			  // 比如纬度用“度:分:秒”的格式表示，分和秒的范围都是00-59，度的范围是-89到89。
			  //QRegExp rx("(-|\\+)?[0-8]\\d:[0-5]\\d:[0-5]\\d");
			  //lineEdit->setValidator(new QRegExpValidator(rx, lineEdit));
			  //lineEdit->setInputMask("#00:00:00;0");
			  //lineEdit->setText("+00:00:00");
		}
	}

	{
		// QTextEdit
		if (false)
		{
			QTextEdit* textEdit = new QTextEdit(this);
			textEdit->resize(300, 300);
			textEdit->move(20, 300);

			// 设置字体粗细
			textEdit->setFontWeight(QFont::Light);

			// 设置字体斜体
			/*
			* true	 斜体
			* false 非斜体
			*/
			textEdit->setFontItalic(false);

			// 设置下划线
			/*
			* true	下划线
			* false 无
			*/
			textEdit->setFontUnderline(false);

			// 设置字体类型
			//textEdit->setFontFamily("仿宋");

			// 设置字体大小
			textEdit->setFontPointSize(32);

			// 设置文本色
			textEdit->setTextColor(QColor('red'));

			// 设置文本背景色
			textEdit->setTextBackgroundColor(QColor(255, 0, 255));

			// 设置对齐方式
			/*
			* Horizontal flags are:
			* Qt::AlignLeft		左对齐
			* Qt::AlignRight		右对齐
			* Qt::AlignHCenter		居中对齐
			* Qt::AlignJustify		两端对齐
			*
			* Vertical flags are:
			* Qt::AlignTop
			* Qt::AlignBottom
			* Qt::AlignVCenter
			* Qt::AlignBaseline
			*/
			textEdit->setAlignment(Qt::AlignLeft);

			// 设置占位文本
			textEdit->setPlaceholderText("占位文本");

			{
				// 普通文本设定
				if (false)
				{
					// 普通文本设定
					textEdit->setPlainText("[普通文本设定]");

					// 光标处插入普通文本
					textEdit->insertPlainText("<光标处插入普通文本>");

					// 普通文本获取
					ui.plainTextEdit->append(textEdit->toPlainText());
				}

				// html标签文本设定
				if (false)
				{
					// 普通文本设定
					textEdit->setHtml("[<p>这是一个段落。。。</p>]");

					// 光标处插入普通文本
					textEdit->insertHtml("{<a href='http://www.baidu.com'> 百度</a>}");

					// 普通文本获取
					ui.plainTextEdit->append(textEdit->toHtml());
				}

				// 自动设置文本
				if (false)
				{
					textEdit->setText("2020/06/17");
				}

				// 文本追加(不管光标位置)
				//textEdit->append("文本追加(不管光标位置)");

				// 文本清除
				//textEdit->clear();
			}

			{
				// 插入列表
				if (true)
				{
					auto tc = textEdit->textCursor();

					/*
					* 常用列表样式枚举值
					* QTextListFormat.ListDisc			圆点
					* QTextListFormat.ListCircle		空心圆
					* QTextListFormat.ListSquare		方块
					* QTextListFormat.ListDecimal		数字升序
					* QTextListFormat.ListUpperRoman	大写罗马数字
					* QTextListFormat.ListLowerRoman	小写罗马数字
					* QTextListFormat.ListUpperAlpha	大写拉丁字母
					* QTextListFormat.ListLowerAlpha	小写拉丁字母
					*/
					auto tlf = QTextListFormat::ListSquare;

					// 插入列表，并把光标右边的字符置为列表第一项
					tc.insertList(QTextListFormat::ListCircle);

					// 在当前位置插入一个新块，并使其成为具有给定格式的新创建列表的第一个列表项，返回创建的列表
					tc.insertList(tlf);

					// 创建列表，并把光标所在行（段落）的字符置为列表第一项
					tc.createList(QTextListFormat::ListCircle);
					tc.createList(tlf);
				}
			}
		}
	}

	{
		// QDateTimeEdit
		// QDateEdit
		// QTimeEdit
		/*
		 * 使用QDateEdit时，如果不设置日期，则系统会为其指定一个默认的日期：2000年1月1日。
		 * 使用QTimeEdit时，如果不设置时间，则系统会为其指定一个默认的时间：0时0分0秒。
		 * 所以，我们一般都会指定一个合适的日期和时间（当前日期时间）。
		 * QDateEdit *dateEdit = new QDateEdit(QDate::currentDate(), this);
		 * QTimeEdit *timeEdit = new QTimeEdit(QTime::currentTime(), this);
		 */
		 /*
		  * QDateEdit用于编辑日期，而QTimeEdit用于编辑时间。如果要同时操作日期时间，请使用QDateTimeEdit。
		  */
		if (false)
		{
			QDateTimeEdit* dateTimeEdit = new QDateTimeEdit(this);
			dateTimeEdit->resize(200, 30);
			dateTimeEdit->move(20, 330);

			QDateTimeEdit* dateTimeEdit2 = new QDateTimeEdit(QDateTime::currentDateTime(), this);
			dateTimeEdit2->resize(200, 30);
			dateTimeEdit2->move(20, 380);

			QDateTimeEdit* dateEdit = new QDateTimeEdit(QDate::currentDate(), this);
			dateEdit->resize(150, 30);
			dateEdit->move(20, 430);

			QDateTimeEdit* timeEdit = new QDateTimeEdit(QTime::currentTime(), this);
			timeEdit->resize(150, 30);
			timeEdit->move(20, 480);

			// 设置日期时间格式
			dateTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
			dateTimeEdit2->setDisplayFormat("yyyy/MM/dd HH-mm-ss");
			dateEdit->setDisplayFormat("yyyy.M.d");
			timeEdit->setDisplayFormat("H:mm");

			// 日期时间范围
			/*
			 * setDateTimeRange()
			 * setDateRange()
			 * setTimeRange()
			 * setMaximumDateTime()
			 * setMinimumDateTime()
			 * setMinimumTime()
			 * setMaximumTime()
			 */
			dateEdit->setMinimumDate(QDate::currentDate().addDays(-365));  // -365天
			dateEdit->setMaximumDate(QDate::currentDate().addDays(365));  // +365天

			// 默认情况下只能通过鼠标点击上下箭头来改变日期时间，如果要弹出日期控件，只需调用setCalendarPopup(true)即可
			dateEdit->setCalendarPopup(true);

			// 获取日期时间
			QDate date = dateEdit->date();  // 日期
			QDateTime dateTime = dateEdit->dateTime();  // 日期时间
			QDate maxDate = dateEdit->maximumDate();  // 最大日期
			QDateTime maxDateTime = dateEdit->maximumDateTime();  // 最大日期时间
			QTime maxTime = dateEdit->maximumTime();  // 最大时间
			QDate minDate = dateEdit->minimumDate();  // 最小日期
			QDateTime minDateTime = dateEdit->minimumDateTime();  // 最小日期时间
			QTime minTime = dateEdit->minimumTime();  // 最小时间


			int nCount = dateEdit->sectionCount();  // 部分数量
			QDateTimeEdit::Section monthSection = dateEdit->sectionAt(1);  // 下标为1对应的部分
			QDateTimeEdit::Section section = dateEdit->currentSection(); // 当前部分
			int nIndex = dateEdit->currentSectionIndex();  // 当前部分下标
														   // 各部分对应的值
			QString strYear = dateEdit->sectionText(QDateTimeEdit::YearSection);
			QString strMonth = dateEdit->sectionText(QDateTimeEdit::MonthSection);
			QString strDay = dateEdit->sectionText(QDateTimeEdit::DaySection);
			QString strHour = dateEdit->sectionText(QDateTimeEdit::HourSection);
			QString strMinute = dateEdit->sectionText(QDateTimeEdit::MinuteSection);
			QString strSecond = dateEdit->sectionText(QDateTimeEdit::SecondSection);
		}
	}

	{
		// QTabWidget
		if (false)
		{
			QWidget* pGroup1 = new QWidget;

			QToolButton* pBtn1 = new QToolButton;
			pBtn1->setText("apple");
			pBtn1->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
			pBtn1->setAutoRaise(true);
			pBtn1->setArrowType(Qt::ArrowType::DownArrow);

			QToolButton* pBtn2 = new QToolButton;
			pBtn2->setText("babala");
			pBtn2->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
			pBtn2->setAutoRaise(true);

			QVBoxLayout* pLayout1 = new QVBoxLayout(pGroup1);
			pLayout1->setMargin(10);
			pLayout1->setAlignment(Qt::AlignmentFlag::AlignLeft);
			pLayout1->addWidget(pBtn1);
			pLayout1->addWidget(pBtn2);

			//////////////////////////////////////
			QWidget* pGroup2 = new QWidget;
			QToolButton* pBtn3 = new QToolButton;
			pBtn3->setText("HUAWEI");
			pBtn3->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
			pBtn3->setAutoRaise(true);

			QToolButton* pBtn4 = new QToolButton;
			pBtn4->setText("XIAOMI");
			pBtn4->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextBesideIcon);
			pBtn4->setAutoRaise(true);

			QVBoxLayout* pLayout2 = new QVBoxLayout(pGroup2);
			pLayout2->setMargin(10);
			pLayout2->setAlignment(Qt::AlignmentFlag::AlignLeft);
			pLayout2->addWidget(pBtn3);
			pLayout2->addWidget(pBtn4);

			QTabWidget* pTab = new QTabWidget(this);
			pTab->addTab(pGroup1, "fruit");
			pTab->addTab(pGroup2, "telephone");
			pTab->resize(200, 200);
			pTab->move(20, 330);
		}
	}

	{
		// QGroupBox
		if (false)
		{
			QGroupBox* pGroupBox = new QGroupBox(QObject::tr("GroupBox test"), this);
			QPushButton* pBtn = new QPushButton(QObject::tr("button"));
			QCheckBox* pCheckBox = new QCheckBox(QObject::tr("checkbox test"));
			QRadioButton* pRadio = new QRadioButton(QObject::tr("radiobtn test"));
			QVBoxLayout* layout = new QVBoxLayout;
			layout->addWidget(pBtn);
			layout->addWidget(pCheckBox);
			layout->addWidget(pRadio);

			pGroupBox->setLayout(layout);
			// GroupBox里面控件是否可选择是能
			pGroupBox->setCheckable(true);
			pGroupBox->move(20, 330);
			pGroupBox->resize(200, 200);
		}
	}

	{
		// QScrollArea
		if (false)
		{
			QGroupBox* pGroupBox = new QGroupBox(QObject::tr("GroupBox test"), this);
			QPushButton* pBtn = new QPushButton(QObject::tr("button"));
			QCheckBox* pCheckBox = new QCheckBox(QObject::tr("checkbox test"));
			QRadioButton* pRadio = new QRadioButton(QObject::tr("radiobtn test"));

			QScrollArea* pSCrollArea = new QScrollArea(this);

			QVBoxLayout* layout = new QVBoxLayout;
			layout->addWidget(pBtn);
			layout->addWidget(pCheckBox);
			layout->addWidget(pRadio);
			pGroupBox->setLayout(layout);
			pGroupBox->setCheckable(true);

			pSCrollArea->move(20, 330);
			pSCrollArea->resize(200, 200);
			pSCrollArea->setWidgetResizable(true);
			pSCrollArea->setBackgroundRole(QPalette::Dark);
			pSCrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
			pSCrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
			pSCrollArea->setWidget(pGroupBox);
		}
	}

	{
		// QProgressBar
		if (false)
		{
			QProgressBar* pProgressBar = new QProgressBar(this);
			pProgressBar->move(20, 330);
			pProgressBar->setOrientation(Qt::Horizontal);  // 水平方向
			pProgressBar->setMinimum(0);  // 最小值
			pProgressBar->setMaximum(100);  // 最大值
			pProgressBar->setValue(50);  // 当前进度

			QProgressBar* pProgressBar2 = new QProgressBar(this);
			pProgressBar2->move(20, 380);
			pProgressBar2->setOrientation(Qt::Horizontal);  // 水平方向
			pProgressBar2->setMinimum(0);  // 最小值
			pProgressBar2->setMaximum(100);  // 最大值
			pProgressBar2->setValue(50);  // 当前进度
			pProgressBar2->setInvertedAppearance(true);  // 反方向
		}
	}

	{
		// Qlabel
		if (false)
		{
			QLabel* lbl = new QLabel(this);
			lbl->resize(150, 30);
			QFont lbl_font;
			lbl_font.setPointSize(11);      //设置字体大小
			lbl->move(20, 330);
			lbl->setFont(lbl_font);
			lbl->setText("Hello World.");
			lbl->setFrameStyle(QFrame::Panel | QFrame::Sunken); //设置外观
		}
	}

	{
		// QCalendarWidget
		if (false)
		{
			QCalendarWidget* calendar = new QCalendarWidget(this);
			calendar->move(300, 100);
			// 垂直标题可以显示的各种格式
			/*
			 * QCalendarWidget::NoVerticalHeader	标题被隐藏
			 * QCalendarWidget::ISOWeekNumbers		标题显示QDate::weekNumber()所描述的ISO星期编号
			 */
			calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

			// 保存水平头的显示格式
			/*
			 * QCalendarWidget::NoHorizontalHeader		标题被隐藏
			 * QCalendarWidget::SingleLetterDayNames	标题显示日期名称的单个字母缩写（例如，星期一为M）
			 * QCalendarWidget::ShortDayNames			标题显示日期名称缩写（例如星期一为周一）
			 * QCalendarWidget::LongDayNames			标题显示完整的日期名称（例如星期一）
			 */
			calendar->setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);
			calendar->setFont(QFont("微软雅黑", 15));
			calendar->adjustSize();

			// 设置可选择最小日期
			calendar->setMinimumDate(QDate(2019, 1, 1));

			// 设置可选择最大日期
			calendar->setMaximumDate(QDate(2020, 1, 31));

			// 是否显示导航栏
			calendar->setNavigationBarVisible(true);

			// 是否显示表格
			calendar->setGridVisible(false);

			calendar->setDateEditEnabled(false);
		}
	}

	{
		// QLCDNumber
		if (false)
		{
			QLCDNumber* pLCD = new QLCDNumber(this);
			pLCD->move(300, 100);
			pLCD->resize(300, 100);

			// 设置能显示的位数
			pLCD->setDigitCount(25);

			// 设置显示的模式为十进制
			pLCD->setMode(QLCDNumber::Dec);

			// 设置显示外观
			pLCD->setSegmentStyle(QLCDNumber::Flat);

			// 决定了小数点单独站一位空间还是在两个位之间
			// 如果参数为true，小数点将占用比平常更少的空间
			pLCD->setSmallDecimalPoint(false);

			// 设置样式
			pLCD->setStyleSheet("border: 2px solid green; color: green; background: silver;");

			QTimer* pTimer = new QTimer(this);

			// 设置定时间隔
			pTimer->setInterval(1000);
			connect(pTimer, &QTimer::timeout, this, [pLCD]()
				{
					// 获取系统当前时间
					QDateTime dateTime = QDateTime::currentDateTime();
					// 显示的内容
					pLCD->display(dateTime.toString("yyyy-MM-dd HH:mm:ss.zzz"));
				});

			// 启动定时器
			pTimer->start();
		}
	}
}

void TestQT::initData()
{
	totalNum = 50;
	redNum = 0;
	blueNum = 0;
	yellowNum = 0;

	model = new QStandardItemModel();

	for (int i = 0; i < totalNum; ++i)
	{
		QStandardItem* Item = new QStandardItem;

		ItemData itemData;

		itemData.name = QString("Name %1").arg(i);
		itemData.tel = QString("TEL:1331234567%1").arg(i);
		int randNum = rand() % 3;
		ItemStatus itemStatus;

		switch (randNum)
		{
		case 0:
			itemStatus = S_RED;
			redNum++;
			break;
		case 1:
			itemStatus = S_BLUE;
			blueNum++;
			break;
		case 2:
			itemStatus = S_YELLOW;
			yellowNum++;
			break;
		}
		Item->setData(itemStatus, Qt::UserRole);  // 单一存取
		Item->setData(QVariant::fromValue(itemData), Qt::UserRole + 1);//整体存取

		model->appendRow(Item);      //追加Item
	}
}

void TestQT::updateButtonNum()
{
	ui.allBtn->setText(tr("all %1").arg(totalNum));
	ui.redBtn->setText(tr("red %1").arg(redNum));
	ui.blueBtn->setText(tr("blue %1").arg(blueNum));
	ui.yellowBtn->setText(tr("yellow %1").arg(yellowNum));
}
