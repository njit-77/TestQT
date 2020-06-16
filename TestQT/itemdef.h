#pragma once

#include <QMetaType>

enum ItemStatus
{
	S_RED,
	S_BLUE,
	S_YELLOW,
};

struct ItemData
{
	QString name;
	QString tel;
};

Q_DECLARE_METATYPE(ItemData)
