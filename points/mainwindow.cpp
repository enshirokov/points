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

    connect(actCreatePoint, &QAction::triggered, this, &MainWindow::createPoint);

    actDeletePoint = new QAction(QIcon(":/images/cross.png"), tr("&Delete point"), this);
    actDeletePoint->setStatusTip(tr("Delete point"));
    actDeletePoint->setCheckable(true);

    connect(actDeletePoint, &QAction::triggered, this, &MainWindow::deletePoint);

    actCreateLine = new QAction(QIcon(":/images/line.png"), tr("&Create line"), this);
    actCreateLine->setStatusTip(tr("Create line"));
    actCreateLine->setCheckable(true);

    connect(actCreateLine, &QAction::triggered, this, &MainWindow::createLine);

    toolBar = addToolBar(tr("Tools"));
    toolBar->setIconSize(QSize(64, 64));
    toolBar->addAction(actCreatePoint);
    toolBar->addAction(actDeletePoint);
    toolBar->addAction(actCreateLine);
}

void MainWindow::createPoint()
{
    actDeletePoint->setChecked(false);
    actCreateLine->setChecked(false);
    view->createPoint();
}

void MainWindow::deletePoint()
{
    actCreatePoint->setChecked(false);
    actCreateLine->setChecked(false);
    view->deletePoint();
}

void MainWindow::createLine()
{
    actDeletePoint->setChecked(false);
    actCreatePoint->setChecked(false);
    view->createLine();
}
