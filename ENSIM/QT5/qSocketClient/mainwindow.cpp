#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    soc = new QTcpSocket(this);
    ui->listWidgetState->setAutoScroll(true);
    connect(soc, SIGNAL(connected()), this, SLOT(onQTcpSocket_Connected()));
    connect(soc, SIGNAL(disconnected()), this, SLOT(onQTcpSocket_Disconnected()));
    connect(soc, SIGNAL(readChannelFinished()), this, SLOT(onQTcpSocket_read()));
    connect(soc, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onQTcpSocket_error(QAbstractSocket::SocketError)));
    connect(soc, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onQTcpSocket_stateChanged(QAbstractSocket::SocketState)));
    connect(ui->listWidgetState->model(), SIGNAL(rowsInserted(QModelIndex,int,int)), ui->listWidgetState, SLOT(scrollToBottom()));
}

void MainWindow::onQTcpSocket_Connected()
{
    qDebug("Connecté");
    ui->pushButtonConnection->setText("Déconnexion");
}

void MainWindow::onQTcpSocket_Disconnected()
{
    qDebug("Deconnecté");
    ui->pushButtonConnection->setText("Connexion");
}

void MainWindow::onQTcpSocket_read()
{
    qDebug("Message : %c", data);
    ui->listWidgetState->addItem("Message : " + QString(data));
}

void MainWindow::onQTcpSocket_stateChanged(QAbstractSocket::SocketState etat)
{
    switch(etat)
    {
    case 0:
        ui->listWidgetState->addItem("Déconnecté");
        break;

    case 1:
        ui->listWidgetState->addItem("Résolution de l'adresse");
        break;

    case 2:
        ui->listWidgetState->addItem("Connexion...");
        break;

    case 3:
        ui->listWidgetState->addItem("Connecté");
        break;

    case 4:
        ui->listWidgetState->addItem("Déjà connecté");
        break;

    case 6:
        ui->listWidgetState->addItem("Déconnexion...");
        break;

    case 5:
        ui->listWidgetState->addItem("Ecoute...");
        break;

    default:
        ui->listWidgetState->addItem("Error 404 : Error not found");
        break;
    }
}

void MainWindow::onQTcpSocket_error(QAbstractSocket::SocketError error)
{
    qDebug("Erreur : %d", QString::number(error));

    switch (error) {

    case 0:
        ui->listWidgetState->addItem("Erreur : Connexion refusée");
        break;

    case 1:
        ui->listWidgetState->addItem("Erreur : Connexion terminée par le serveur");
        break;

    case 2:
        ui->listWidgetState->addItem("Erreur : Adresse inconnue");
        break;

    case 3:
        ui->listWidgetState->addItem("Erreur : Aucune permission");
        break;

    case 4:
        ui->listWidgetState->addItem("Erreur : Manque de ressource");
        break;

    case 5:
        ui->listWidgetState->addItem("Erreur : Temps écoulé");
        break;

    case 6:
        ui->listWidgetState->addItem("Erreur : Datagramme trop grand");
        break;

    case 7:
        ui->listWidgetState->addItem("Erreur : Erreur réseau");
        break;

    case 8:
        ui->listWidgetState->addItem("Erreur : Adresse déjà utilisée");
        break;

    case 9:
        ui->listWidgetState->addItem("Erreur : Adresse spécifiée non conforme au serveur");
        break;

    case 10:
        ui->listWidgetState->addItem("Erreur : Opération non supportée");
        break;

    case 11:
        ui->listWidgetState->addItem("Erreur : Flux de communication non terminée");
        break;

    case 12:
        ui->listWidgetState->addItem("Erreur : Erreur d'authentification avec le proxy");
        break;

    case 13:
        ui->listWidgetState->addItem("Erreur : Erreur SSL/TLS");
        break;

    case 14:
        ui->listWidgetState->addItem("Erreur : Connexion refusée par le proxy");
        break;

    case 15:
        ui->listWidgetState->addItem("Erreur : Connexion avec le proxy terminée");
        break;

    case 16:
        ui->listWidgetState->addItem("Erreur : Le proxy a cessé de répondre");
        break;

    case 17:
        ui->listWidgetState->addItem("Erreur : Proxy non reconnu");
        break;

    case 18:
        ui->listWidgetState->addItem("Erreur : Réponse proxy invalide");
        break;

    case 19:
        ui->listWidgetState->addItem("Erreur : Opération non permise au moment de l'exécution");
        break;

    case 20:
        ui->listWidgetState->addItem("Erreur : Erreur de la librairie SSL");
        break;

    case 21:
        ui->listWidgetState->addItem("Erreur : Informations SSL invalides");
        break;

    case 22:
        ui->listWidgetState->addItem("Erreur : Erreur temporaire");
        break;

    default:
        ui->listWidgetState->addItem("Erreur : Erreur inconnue");
        break;
    }
}

void MainWindow::on_pushButtonConnection_clicked()
{
    ui->pushButtonConnection->setText("Connexion...");
    soc->abort();
    soc->connectToHost("127.0.0.1", 8454);
}

void MainWindow::on_pushButtonSend_clicked()
{
    if(ui->lineEditMessage->text() != "")
    {
        soc->write(ui->lineEditMessage->text().toLatin1());
        ui->lineEditMessage->clear();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
