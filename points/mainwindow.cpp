#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    view = new View();


    QHBoxLayout* hLayout = new QHBoxLayout;
    hLayout->addWidget(view);


    QWidget* centralWgt = new QWidget;
    centralWgt->setLayout(hLayout);

    setCentralWidget(centralWgt);

    createActions();

}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions()
{
    actCreatePoint = new QAction(QIcon(":/images/point.png"), tr("&Create point"), this);
    actCreatePoint->setStatusTip(tr("Create point"));
    actCreatePoint->setCheckable(true);

    //QToolButton *b = new QToolButton;
    //b->setIcon(QIcon(":/images/point.png"));

    connect(actCreatePoint, &QAction::triggered, this, &MainWindow::createPoint);

    actDeletePoint = new QAction(QIcon(":/images/cross.png"), tr("&Delete point"), this);
    actDeletePoint->setStatusTip(tr("Delete point"));
    actDeletePoint->setCheckable(true);

    connect(actDeletePoint, &QAction::triggered, this, &MainWindow::deletePoint);

    toolBar = addToolBar(tr("Tools"));
    toolBar->setIconSize(QSize(64, 64));
    toolBar->addAction(actCreatePoint);
    toolBar->addAction(actDeletePoint);
    //toolBar->addWidget(b);
}

void MainWindow::createPoint()
{
    actDeletePoint->setChecked(false);
    view->createPoint();
}

void MainWindow::deletePoint()
{
    actCreatePoint->setChecked(false);
    view->deletePoint();
}
