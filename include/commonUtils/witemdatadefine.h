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


//list���ݻ���
struct sListWidgetBaseData
{
	eListItemType itemType;   //item ��������
	QString       objectName; //������
	QString style;
	virtual ~sListWidgetBaseData()
	{
	}
};

//Ĭ������
struct sListDefualtWidgetData:public sListWidgetBaseData
{
    QString text;
    sListDefualtWidgetData()
    {
        itemType=TYPE_DEFUALT_ITEM;
    }
};
//������������
struct sSearchWidgetData:public sListWidgetBaseData
{
	QString searchDefultText;
	sSearchWidgetData()
	{
		itemType = TYPE_SEARCH_ITEM;
	}

};

//TYPE_LIST_ITEM ��������
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

//TYPE_LIST_ITEM1 ��������
struct sListWidgetData1 :public sListWidgetBaseData
{
	QString labelText;
	QString iconPath;
	sListWidgetData1()
	{
		itemType=TYPE_LIST_ITEM1;
	}
};


//TYPE_LIST_ITEM2 ��������
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


//TYPE_LIST_ITEM3 ��������
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
