#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QAction>
#include <QToolBar>
#include <QToolButton>

#include "view.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createActions();

private slots:
    void createPoint();
    void deletePoint();
    void createLine();

private:
    View *view;

    QAction *actCreatePoint;
    QAction *actDeletePoint;
    QAction *actCreateLine;

    QToolBar *toolBar;

};

#endif // MAINWINDOW_H
