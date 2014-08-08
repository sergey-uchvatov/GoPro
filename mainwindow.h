#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTabWidget>
#include <QtCore/QCoreApplication>
#include <QMessageBox>
#include "goprocontroller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void checkConnection();
    GoproController * goproController;

private:
    Ui::MainWindow *ui;

private slots:
    void standBy();


};

#endif // MAINWINDOW_H
