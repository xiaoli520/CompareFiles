#include "wtopwidget.h"
#include "ui_wtopwidget.h"
#include "wappcomm.h"

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

WTopWidget::WTopWidget(QWidget *parent) :
    WBaseQssWidget(parent),
    ui(new Ui::WTopWidget)
{
    ui->setupUi(this);
    this->setFocusPolicy(Qt::StrongFocus);

    m_Close= new QPushButton(this);
    m_Maximize = new QPushButton(this);
    m_Maximize->setIcon(QPixmap(""));
    m_Minimize = new QPushButton(this);

    m_Close->setObjectName("closeButton");
    m_Maximize->setObjectName("maxButton");
    m_Minimize->setObjectName("minButton");

    m_Close->setFocusPolicy(Qt::NoFocus);
    m_Maximize->setFocusPolicy(Qt::NoFocus);
    m_Minimize->setFocusPolicy(Qt::NoFocus);

    m_logoLabel = new QLabel(this);
    m_logoLabel->setObjectName("logoLabel");
    m_logoLabel->setText(tr("CompareFiles 1.0"));
    m_logoLabel->setAlignment(Qt::AlignTop);

    connect(m_Close, SIGNAL(clicked()), SIGNAL(triggerClose()));
    connect(m_Minimize, SIGNAL( clicked() ), parent, SLOT(showMinimized()));
    connect(m_Maximize, SIGNAL( clicked() ), this, SLOT(showMaxRestore()));
    connect(this,SIGNAL(showMax()),parent,SLOT(showMaxSize()));
    connect(this,SIGNAL(showNormal()),parent,SLOT(showNormalSize()));
    hboxLayout = new QHBoxLayout(this);
    QHBoxLayout* right=new QHBoxLayout(this);
    right->addWidget(m_Minimize);
    right->addWidget(m_Maximize);
    right->addWidget(m_Close);
    right->setAlignment(Qt::AlignRight|Qt::AlignTop);
    right->setContentsMargins(0,0,0,0);
    right->setSpacing(0);
    QVBoxLayout* left= new QVBoxLayout(this);
    left->addSpacing(18);
    left->addWidget(m_logoLabel);
    left->addSpacing(18);
    left->setAlignment(Qt::AlignLeft);
    left->setContentsMargins(18,0,0,0);
    left->setSpacing(0);

    hboxLayout->addLayout(left);
    hboxLayout->addSpacing(400);
    hboxLayout->addLayout(right);
    hboxLayout->setSpacing(0);
    hboxLayout->setMargin(0);
    hboxLayout->setAlignment(Qt::AlignTop);
    setLayout(hboxLayout);



    m_isMax=false;

    QString name = PTR_WAPP_COMM->getQssFilePath("wtopwidget.qss");
    loadStyleSheetFromFile(name);

    m_Maximize->setIcon(QPixmap(PTR_WAPP_COMM->getImagePath("maximize.png")));
    m_Maximize->setIconSize(QSize(30, 20));
}

WTopWidget::~WTopWidget()
{
    delete ui;
}

/**
 * @brief mousePressEvent 自定义鼠标拖动事件
 * @param pMouseEvent
 */
void WTopWidget::mousePressEvent(QMouseEvent* pMouseEvent)
{
        m_StartPos=pMouseEvent->globalPos();
        m_ClickPos=mapToParent(pMouseEvent->globalPos());

        if(pMouseEvent->button() == Qt::LeftButton)
        {
            m_DragPosition =pMouseEvent->globalPos()-mapToGlobal(frameGeometry().topLeft());//(mapToParent());
            pMouseEvent->accept();
        }
}

/**
 * @brief mousePressEvent 自定义鼠标拖动事件
 * @param pMouseEvent
 */
void WTopWidget::mouseMoveEvent(QMouseEvent* pMouseEvent)
{
    if(m_isMax)
        return;

    if(pMouseEvent->buttons() == Qt::LeftButton)
    {
        QWidget* temp=(QWidget*)parent();
        if(temp != NULL)
            temp->move(pMouseEvent->globalPos()-m_DragPosition);
        pMouseEvent->accept();
    }
}

/**
 * @brief mousePressEvent 自定义鼠标拖动事件
 * @param pMouseEvent
 */
void WTopWidget::mouseDoubleClickEvent(QMouseEvent *pMouseEvent)
{
    if(pMouseEvent->buttons() == Qt::LeftButton)
    {
        if(QWidget::childAt(pMouseEvent->pos()) == 0)
            showMaxRestore();
    }
}


void WTopWidget::showMaxRestore()
{
    if(m_isMax)
    {
        emit showNormal();
        m_Maximize->setIcon(QPixmap(PTR_WAPP_COMM->getImagePath("maximize.png")));
        m_isMax=false;
    }
    else
    {
        emit showMax();
        m_Maximize->setIcon(QPixmap(PTR_WAPP_COMM->getImagePath("icon_Restore-Down.png")));
        m_isMax=true;
    }
}
