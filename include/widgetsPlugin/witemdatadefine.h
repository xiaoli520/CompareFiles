#ifndef WITEMDATADEFINE_H
#define WITEMDATADEFINE_H

#include <QString>

enum eListItemType
{
    TYPE_DEFUALT_ITEM,
	TYPE_SEARCH_ITEM,
	TYPE_LIST_ITEM,
	TYPE_LIST_ITEM1,
	TYPE_LIST_ITEM2,
	TYPE_LIST_ITEM3,
};


//list数据基类
struct sListWidgetBaseData
{
	eListItemType itemType;   //item 数据类型
	QString       objectName; //对象名
	QString style;
	virtual ~sListWidgetBaseData()
	{
	}
};

//默认类型
struct sListDefualtWidgetData:public sListWidgetBaseData
{
    QString text;
    sListDefualtWidgetData()
    {
        itemType=TYPE_DEFUALT_ITEM;
    }
};
//搜索数据类型
struct sSearchWidgetData:public sListWidgetBaseData
{
	QString searchDefultText;
	sSearchWidgetData()
	{
		itemType = TYPE_SEARCH_ITEM;
	}

};

//TYPE_LIST_ITEM 数据类型
struct sListWidgetData :public sListWidgetBaseData
{
	QString label1Text;
	QString label2Text;
	QString iconPath;
	sListWidgetData()
	{
		itemType = TYPE_LIST_ITEM;
	}
};

//TYPE_LIST_ITEM1 数据类型
struct sListWidgetData1 :public sListWidgetBaseData
{
	QString labelText;
	QString iconPath;
	sListWidgetData1()
	{
		itemType=TYPE_LIST_ITEM1;
	}
};


//TYPE_LIST_ITEM2 数据类型
struct sListWidgetData2 :public sListWidgetBaseData
{
	QString labelText;
	QString iconPath;
	QString pushButtonText;
	QString pushButtonStyle;
	int     pushButtonId;
	sListWidgetData2()
	{
		itemType=TYPE_LIST_ITEM2;
	}
};


//TYPE_LIST_ITEM3 数据类型
struct sListWidgetData3 :public sListWidgetBaseData
{
	QString label1Text;
	QString label2Text;
	QString iconPath;
	QString progressBarStyle;
	int     progressBarId;
	sListWidgetData3()
	{
		itemType=TYPE_LIST_ITEM3;
	}
};


#endif // WITEMDATADEFINE_H
