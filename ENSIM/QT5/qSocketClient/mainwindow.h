#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QListWidgetItem>

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
    QTcpSocket *soc;
    QChar data;

private slots:
    void onQTcpSocket_Connected();
    void onQTcpSocket_Disconnected();
    void onQTcpSocket_read();
    void onQTcpSocket_stateChanged(QAbstractSocket::SocketState);
    void onQTcpSocket_error(QAbstractSocket::SocketError);
    void on_pushButtonConnection_clicked();
    void on_pushButtonSend_clicked();
};

#endif // MAINWINDOW_H
