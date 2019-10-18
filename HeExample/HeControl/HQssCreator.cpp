#include "HQssCreator_p.h"
#include "ui_HQssCreator.h"
#include "HQssStyle.h"
#include "HControlHelper.h"
#include <QtGui/QScreen>

HE_CONTROL_BEGIN_NAMESPACE

HQssCreator::HQssCreator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HQssCreator),
    d_ptr(new HQssCreatorPrivate)
{
    ui->setupUi(this);
    init();
}

HQssCreator::~HQssCreator()
{
    delete ui;
}

void HQssCreator::init()
{
    initStyle();
    initAction();    
    initTableWidget();
    initTreeWidget();
    initListWidget();
    initOther();
    HControlHelper::initTranslator();
    ui->tabWidget->setCurrentIndex(0);
}

void HQssCreator::initStyle()
{
    d_ptr->style = new HQssStyle(this);
    setPalette(d_ptr->style->toPalette());
    setStyleSheet(d_ptr->style->toStyleSheet());
}

void HQssCreator::initAction()
{
    auto g = new QActionGroup(this);
    for (auto k : d_ptr->style->keys())
        g->addAction(k)->setData(k);
    connect(g, &QActionGroup::triggered, this, &HQssCreator::changeStyle);
    addActions(g->actions());
    setContextMenuPolicy(Qt::ActionsContextMenu);
}

void HQssCreator::initTableWidget()
{
    // 设置列数和列宽
    int width =  QApplication::primaryScreen()->availableGeometry().width() - 120;
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setColumnWidth(0, width * 0.06);
    ui->tableWidget->setColumnWidth(1, width * 0.10);
    ui->tableWidget->setColumnWidth(2, width * 0.06);
    ui->tableWidget->setColumnWidth(3, width * 0.10);
    ui->tableWidget->setColumnWidth(4, width * 0.15);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(25);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "设备编号" << "设备名称" << "设备地址" << "告警内容" << "告警时间");
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    // 设置行高
    ui->tableWidget->setRowCount(300);
    for (int i = 0; i < 300; i++)
    {
        ui->tableWidget->setRowHeight(i, 24);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(i + 1)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString("测试设备%1").arg(i + 1)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(i + 1)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem("防区告警"));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
    }
}

void HQssCreator::initTreeWidget()
{
    ui->treeWidget->clear();
    ui->treeWidget->setHeaderLabel(" 树状列表控件");

    auto group1 = new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0, "父元素1");
    group1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    group1->setCheckState(0, Qt::PartiallyChecked);

    auto subItem11 = new QTreeWidgetItem(group1);
    subItem11->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem11->setText(0, "子元素1");
    subItem11->setCheckState(0, Qt::Checked);

    auto subItem12 = new QTreeWidgetItem(group1);
    subItem12->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem12->setText(0, "子元素2");
    subItem12->setCheckState(0, Qt::Unchecked);

    auto subItem13 = new QTreeWidgetItem(group1);
    subItem13->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem13->setText(0, "子元素3");
    subItem13->setCheckState(0, Qt::Unchecked);

    auto group2 = new QTreeWidgetItem(ui->treeWidget);
    group2->setText(0, "父元素2");
    group2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    group2->setCheckState(0, Qt::Unchecked);

    auto subItem21 = new QTreeWidgetItem(group2);
    subItem21->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem21->setText(0, "子元素1");
    subItem21->setCheckState(0, Qt::Unchecked);

    auto subItem211 = new QTreeWidgetItem(subItem21);
    subItem211->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem211->setText(0, "子子元素1");
    subItem211->setCheckState(0, Qt::Unchecked);

    ui->treeWidget->expandAll();
}

void HQssCreator::initListWidget()
{
    QStringList list;
    for (int i = 1; i <= 30; i++)
        list << QString("元素%1").arg(i);
    ui->listWidget->addItems(list);
    ui->cbox1->addItems(list);
    ui->cbox2->addItems(list);
}

void HQssCreator::initOther()
{
    ui->rbtn1->setChecked(true);
    ui->ck2->setChecked(true);
    ui->ck3->setCheckState(Qt::PartiallyChecked);
    ui->horizontalSlider->setValue(88);

    ui->tab9->setStyleSheet("QPushButton{font:20pt;}");
    ui->widgetVideo->setStyleSheet("QLabel{font:20pt;}");
    ui->widgetLeft->setProperty("nav", "left");
    ui->widgetBottom->setProperty("form", "bottom");
    ui->widgetTop->setProperty("nav", "top");
    ui->widgetVideo->setProperty("video", true);

    QList<QLabel *> labels = ui->widgetVideo->findChildren<QLabel *>();
    for (auto l : labels)
        l->setFocusPolicy(Qt::StrongFocus);
}

void HQssCreator::changeStyle(QAction *p)
{
    if (p == nullptr || !d_ptr->style->selectStyle(p->data().toString()))
        return;
    // 清除样式表
    setStyleSheet("");
    setPalette(d_ptr->style->toPalette());
    setStyleSheet(d_ptr->style->toStyleSheet());
}

HE_CONTROL_END_NAMESPACE