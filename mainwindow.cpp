#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMovie>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->raise();
    movie = new QMovie(":/engine/assets/cut.gif");
    ui->label->resize(1280,720);
    ui->label->setMovie(movie);
    ui->label->setBackgroundRole(QPalette::Dark);
    movie->setCacheMode(QMovie::CacheAll);
    movie->setSpeed(300);
    movie->start();
    movie->stop();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::finished_slot()
{
    /*QNetworkReply *reply = (QNetworkReply *) sender();
    QString data1 = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data1.toUtf8());
    QJsonObject data = doc.object();
    int id;
    double staticPressure1,staticPressure2,staticPressure3,staticPressure4,staticPressure5,staticPressure6,
           dynamicPressure,temperature1,temperature2,temperature3,airFlowMeter;
    QString timeStamp;
    id = data["id"].toInt();
    staticPressure1 = data.value("staticPressure1").toDouble();
    staticPressure2 = data.value("staticPressure2").toDouble();
    staticPressure3 = data.value("staticPressure3").toDouble();
    staticPressure4 = data.value("staticPressure4").toDouble();
    staticPressure5 = data.value("staticPressure5").toDouble();
    staticPressure6 = data.value("staticPressure6").toDouble();
    dynamicPressure = data.value("dynamicPressure").toDouble();
    temperature1 = data.value("temperature1").toDouble();
    temperature2 = data.value("temperature2").toDouble();
    temperature3 = data.value("temperature3").toDouble();
    airFlowMeter = data.value("airFlowMeter").toDouble();
    timeStamp = data.value("timeStamp").toString();
    ui->tableWidget->setColumnCount(2);//表格列数
    ui->tableWidget->setRowCount(13);//表格行数
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(0,140);
    QStringList list;
    list<<tr("参数名")<<tr("参数值");
    ui->tableWidget->setHorizontalHeaderLabels(list);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("id"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(id)));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("staticPressure1"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem(QString::number(staticPressure1)));
    ui->tableWidget->setItem(2,0,new QTableWidgetItem("staticPressure2"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem(QString::number(staticPressure2)));
    ui->tableWidget->setItem(3,0,new QTableWidgetItem("staticPressure3"));
    ui->tableWidget->setItem(3,1,new QTableWidgetItem(QString::number(staticPressure3)));
    ui->tableWidget->setItem(4,0,new QTableWidgetItem("staticPressure4"));
    ui->tableWidget->setItem(4,1,new QTableWidgetItem(QString::number(staticPressure4)));
    ui->tableWidget->setItem(5,0,new QTableWidgetItem("staticPressure5"));
    ui->tableWidget->setItem(5,1,new QTableWidgetItem(QString::number(staticPressure5)));
    ui->tableWidget->setItem(6,0,new QTableWidgetItem("staticPressure6"));
    ui->tableWidget->setItem(6,1,new QTableWidgetItem(QString::number(staticPressure6)));
    ui->tableWidget->setItem(7,0,new QTableWidgetItem("dynamicPressure"));
    ui->tableWidget->setItem(7,1,new QTableWidgetItem(QString::number(dynamicPressure)));
    ui->tableWidget->setItem(8,0,new QTableWidgetItem("temperature1"));
    ui->tableWidget->setItem(8,1,new QTableWidgetItem(QString::number(temperature1)));
    ui->tableWidget->setItem(9,0,new QTableWidgetItem("temperature2"));
    ui->tableWidget->setItem(9,1,new QTableWidgetItem(QString::number(temperature2)));
    ui->tableWidget->setItem(10,0,new QTableWidgetItem("temperature3"));
    ui->tableWidget->setItem(10,1,new QTableWidgetItem(QString::number(temperature3)));
    ui->tableWidget->setItem(11,0,new QTableWidgetItem("airFlowMeter"));
    ui->tableWidget->setItem(11,1,new QTableWidgetItem(QString::number(airFlowMeter)));
    ui->tableWidget->setItem(12,0,new QTableWidgetItem("timeStamp"));
    ui->tableWidget->setItem(12,1,new QTableWidgetItem(timeStamp));
    reply->deleteLater();*/
    QNetworkReply *reply = (QNetworkReply *) sender();
    QString data1 = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data1.toUtf8());
    QJsonObject data = doc.object();
    int id;
    double dynamicPressure,staticPressure1,staticPressure2,angle,speed1,speed2;
    QString timeStamp;
    id = data["id"].toInt();
    dynamicPressure = data.value("dynamicPressure").toDouble();
    staticPressure1 = data.value("staticPressure1").toDouble();
    staticPressure2 = data.value("staticPressure2").toDouble();
    angle = data.value("angle").toDouble();
    speed1 = data.value("speed1").toDouble();
    speed2 = data.value("speed2").toDouble();
    timeStamp = data.value("timeStamp").toString();
    ui->arrow->move(200,625-5.25*id);
    ui->tableWidget->setColumnCount(2);//表格列数
    ui->tableWidget->setRowCount(8);//表格行数
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(0,140);
    QStringList list;
    list<<tr("参数名")<<tr("参数值");
    ui->tableWidget->setHorizontalHeaderLabels(list);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("id"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(id)));
    ui->tableWidget->setItem(1,0,new QTableWidgetItem("dynamicPressure"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem(QString::number(dynamicPressure)));
    ui->tableWidget->setItem(2,0,new QTableWidgetItem("staticPressure1"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem(QString::number(staticPressure1)));
    ui->tableWidget->setItem(3,0,new QTableWidgetItem("staticPressure2"));
    ui->tableWidget->setItem(3,1,new QTableWidgetItem(QString::number(staticPressure2)));
    ui->tableWidget->setItem(4,0,new QTableWidgetItem("angle"));
    ui->tableWidget->setItem(4,1,new QTableWidgetItem(QString::number(angle)));
    ui->tableWidget->setItem(5,0,new QTableWidgetItem("speed1"));
    ui->tableWidget->setItem(5,1,new QTableWidgetItem(QString::number(speed1)));
    ui->tableWidget->setItem(6,0,new QTableWidgetItem("speed2"));
    ui->tableWidget->setItem(6,1,new QTableWidgetItem(QString::number(speed2)));
    ui->tableWidget->setItem(7,0,new QTableWidgetItem("timeStamp"));
    ui->tableWidget->setItem(7,1,new QTableWidgetItem(timeStamp));
    reply->deleteLater();
}

void MainWindow::get_data(){
    QUrl url("http://111.186.41.144:33291/engine/latest");
    QNetworkRequest networkRequest(url);
    QNetworkAccessManager *networkAccessManager = new QNetworkAccessManager();
    QNetworkReply *networkReply = networkAccessManager->get(networkRequest);
    connect(networkReply,SIGNAL(finished()),this,SLOT(finished_slot()));
}

void MainWindow::on_pushButton_clicked()
{
    movie->start();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(get_data()));
    timer->start(1000);
}


void MainWindow::on_pushButton_2_clicked()
{
    movie->start();
}

