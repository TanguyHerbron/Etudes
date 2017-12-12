#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    soc = new QTcpServer();
    process = new QProcess();
    connexionClient = NULL;
    QList<QHostAddress> ipAdressList = QNetworkInterface::allAddresses();

    connect(ui->listWidgetState->model(), SIGNAL(rowsInserted(QModelIndex,int,int)), ui->listWidgetState, SLOT(scrollToBottom()));

    soc->setMaxPendingConnections(NUMCO);

    if(soc->listen(QHostAddress::Any, 8454))
    {
        for(int i = 0; i < ipAdressList.size(); i++)
        {
            if(ipAdressList.at(i).toIPv4Address())
            {
                ui->listWidgetState->addItem(ipAdressList.at(i).toString());
            }
        }

        if(!connect(soc, SIGNAL(newConnection()), this, SLOT(onQTcpServer_newConnection())))
        {
            qDebug() << "Erreur connect newConnection avec onQTcpServer_newConnection";
        }
    }

    if(!connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(onQProcess_readyRead())))
    {
        qDebug() << "Erreur connect readyRead vers onQTcpSocket_readyRead";
    }
}

void MainWindow::onQTcpServer_newConnection()
{
    if(connexionClient == NULL)
    {
        connexionClient = soc->nextPendingConnection();

        ui->listWidgetState->addItem(QString("Nouvelle connexion : ") + QString(connexionClient->peerAddress().toString()));

        qDebug("Nouvelle connexion : %s", QString(connexionClient->peerAddress().toString()));

        if(!connect(connexionClient, SIGNAL(readyRead()), this, SLOT(onQTcpSocket_readyRead())))
        {
            qDebug("Erreur connect readyRead avec onQTcpSocket_readyRead");
        }

        if(!connect(connexionClient, SIGNAL(disconnected()), this, SLOT(onQTcpSocket_disconnected())))
        {
            qDebug("Erreur connect newConnection avec onQTcpServer_newConnection");
        }
    }
    else
    {
        ui->listWidgetState->addItem("Connexion refusée");
        connexionClient = soc->nextPendingConnection();
        connexionClient->write("Connexion refusée");
        connexionClient->abort();
    }
}

void MainWindow::onQTcpSocket_readyRead()
{
    QByteArray data;
    data = connexionClient->readLine();
    ui->listWidgetMessage->addItem(QString::fromLatin1(data));

    qDebug("Data : %s", QString(data));
}

void MainWindow::onQTcpSocket_disconnected()
{
    ui->listWidgetState->addItem("Deconnexion du client");
    connexionClient->deleteLater();
    connexionClient = NULL;
}

void MainWindow::onQProcess_readyRead()
{
    qDebug("Process output : %s", process->readLine());
}

void MainWindow::on_pushButtonSend_clicked()
{
    if(ui->lineEditMessage->text() != "")
    {
        connexionClient->write(ui->lineEditMessage->text().toLatin1());
        ui->lineEditMessage->clear();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
