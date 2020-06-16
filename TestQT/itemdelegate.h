#pragma once

#include <QStyledItemDelegate>
#include <QModelIndex>
#include <QStandardItemModel>

class ItemDelegate : public QStyledItemDelegate
{
	Q_OBJECT
signals:

public:
	explicit ItemDelegate(QObject* parent = 0);
	~ItemDelegate();

	// ��д�ػ�����
	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
	QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;

private:

};