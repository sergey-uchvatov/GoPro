#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    goproController = GoproController::getInstance();
    checkConnection();

    connect(ui->stby, SIGNAL(released()), this, SLOT(standBy()));
}

void MainWindow::checkConnection()
{
    if(goproController->cameraAvailable()) {
//        ui->ta
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("Camera is not available");
        msgBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Retry);

        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Retry:
            checkConnection();
            break;
        case QMessageBox::Cancel:
        default:
//            tabs->setTabEnabled(1, false);
            break;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::standBy() {
    goproController->cameraOn();
    goproController->getStatus("bacpac/se");
}
