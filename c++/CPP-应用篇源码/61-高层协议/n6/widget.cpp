#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    m_file("d:/u6.down")
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);

    QString s = ui->lineEdit->text().trimmed();
    QUrl url = QUrl::fromUserInput(s);
    if(!url.isValid()){
        qDebug() << url.errorString();
        return;
    }

    m_file.open(QIODevice::WriteOnly);

    m_reply = m_manager.get(QNetworkRequest(url));
    connect(m_reply, SIGNAL(finished()), this, SLOT(onMyFinish()));
    connect(m_reply, SIGNAL(readyRead()), this, SLOT(onMyRead()));
    connect(m_reply, SIGNAL(downloadProgress(qint64,qint64)),
            this, SLOT(onMyProgress(qint64,qint64)));
}

void Widget::onMyFinish()
{
    m_file.close();
}

void Widget::onMyRead()
{
    m_file.write(m_reply->readAll());
}

void Widget::onMyProgress(qint64 a, qint64 b)
{
    ui->progressBar->setMaximum(b);
    ui->progressBar->setValue(a);
}
