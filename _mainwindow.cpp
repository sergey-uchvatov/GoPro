//#include "mainwindow.h"


/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//{
//    this->setStyleSheet("background-color:#000000");

//    goproController = GoproController::getInstance();

//    QImage logo ();


//    generalTab = new GeneralTab();
//    permissionsTab = new PermissionsTab();

//    tabs = new QTabWidget(this);
//    tabs->setStyleSheet("background-color:#000000; border-color:#aaaaaa; color:#cccccc");

//    tabs->setFixedSize(400, 300);
//    tabs->addTab(generalTab, tr("General"));
//    tabs->addTab(permissionsTab, tr("Permissions"));

//    checkConnection();
//}

/**
 * @brief MainWindow::checkConnection
 */
/* void MainWindow::checkConnection() {
    if(goproController->cameraAvailable()) {
        tabs->setDisabled(true);
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
            tabs->setTabEnabled(1, false);
            break;
        }
    }
}
*/
/**
 * @brief GeneralTab::GeneralTab
 * @param parent
 */
/*GeneralTab::GeneralTab(QTabWidget *parent)
    : QTabWidget(parent)
{
    goproController = GoproController::getInstance();

    stbyButton = new QPushButton("On", this);
    stbyButton->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));

    connect(stbyButton, SIGNAL(released()), this, SLOT(standBy()));
}
*/
/**
  * @brief PermissionsTab::PermissionsTab
  * @param parent
  */
/*PermissionsTab::PermissionsTab(QTabWidget *parent)
    : QTabWidget(parent)
{

}
*/
/**
 * @brief GeneralTab::standBy
 */
/*void GeneralTab::standBy()
{

    goproController->cameraOn();

}*/
