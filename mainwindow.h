#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTabWidget>
#include <QtCore/QCoreApplication>
#include <QMessageBox>
#include <QImage>
#include "goprocontroller.h"

namespace Ui {
    class MainWindow;
    class GeneralTab;
    class PermissionsTab;
}

/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void checkConnection();

    QTabWidget *tabs;
    QTabWidget *generalTab;
    QTabWidget *permissionsTab;

    GoproController * goproController;

};

/**
 * @brief The GeneralTab class
 */
class GeneralTab : public QTabWidget
{
    Q_OBJECT

public:
    GeneralTab(QTabWidget *parent = 0);

private slots:
    void standBy();

private:
    QPushButton *stbyButton, *recordButton;
    GoproController *goproController;
};

/**
  * @brief The PermissionsTab class
  */
class PermissionsTab : public QTabWidget
{
    Q_OBJECT

public:
    PermissionsTab(QTabWidget *parent = 0);

private:
    GoproController * goproController;
};

#endif // MAINWINDOW_H
