#include "timerwidget.h"
#include "ui_timerwidget.h"
#include <QTimer>
#include <QDateTime>

TimerWidget::TimerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimerWidget)
{
    ui->setupUi(this);

//    id1 = startTimer(1000);
//    id2 = startTimer(2500);
//    id3 = startTimer(10000);

    auto timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

}

TimerWidget::~TimerWidget()
{
    delete ui;
}

void TimerWidget::timerEvent(QTimerEvent *e)
{
    if (e->timerId() == id1) {
        auto text = tr("%1").arg(qrand()%10);
        ui->label->setText(text);
    }
    else if (e->timerId() == id2) {
        ui->label->setText(tr("hello world"));
    }
    else {
        qApp->quit();
    }
}

void TimerWidget::timerUpdate()
{
    auto time = QDateTime::currentDateTime();
    auto str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->lineEdit->setText(str);

    int randx = qrand() % 10;
    int randy = qrand() % 10;
    ui->lineEdit->move(randx, randy);
}
