#include "subtitleparser.h"
#include "ui_subtitleparser.h"

#include <QTimer>
#include <QMovie>
#include <QPalette>
#include <QIcon>

SubtitleParser::SubtitleParser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubtitleParser)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);    // 无边框
    this->setWindowIcon(QIcon(":/icon/SuParser.png"));

//    QPalette palette;   //无作用？？
//    palette.setColor(QPalette::WindowText, Qt::white);
//    ui->labelAppname->setPalette(palette);
//    ui->labelAppname->setAutoFillBackground(true);
//    this->setPalette(palette);

    /*加载条*/
    QMovie *loading = new QMovie(":/welcome/loading.gif");
    ui->labelLoading->setMovie(loading);
    loading->start();

    /*显示与隐藏*/
    welcomeTimer = new QTimer(this);
    welcomeTimer->setSingleShot(true);
    welcomeTimer->setInterval(3500);
    QObject::connect(welcomeTimer, SIGNAL(timeout ()),      //此处也可用简易singleshot：
                                 this, SLOT(slotTimeout ()));          //QTimer::singleShot(600000, &app, SLOT(quit()));
    welcomeTimer->start();
}


SubtitleParser::~SubtitleParser()
{
    delete ui;
}

void SubtitleParser::slotTimeout()
{
    emit signalShowMainInterface ();
    this->hide();
}



