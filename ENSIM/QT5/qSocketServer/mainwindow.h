#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QTcpServer>
#include <QTcpSocket>
#include <QNetworkInterface>

#define NUMCO 10

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTcpServer *soc;
    QTcpSocket *connexionClient;
    QProcess *process;

private slots:
    void onQTcpServer_newConnection();
    void onQTcpSocket_readyRead();
    void onQTcpSocket_disconnected();
    void onQProcess_readyRead();
    void on_pushButtonSend_clicked();
};

#endif // MAINWINDOW_H
