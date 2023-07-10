#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QInputDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString afname = QFileDialog::getOpenFileName(this,
                                "选个文件",
                                "d:/",
                                "文本(*.txt);;图片(*.jpg *.png);;所有(*.*)");
    if(!afname.isEmpty())
        ui->plainTextEdit->appendPlainText(afname);
}

void Widget::on_pushButton_2_clicked()
{
    auto plt = ui->plainTextEdit->palette();
    QColor acolor = QColorDialog::getColor(plt.color(QPalette::Text),
                                this,
                                "选择颜色");

    if(acolor.isValid()){
        plt.setColor(QPalette::Text, acolor);
        ui->plainTextEdit->setPalette(plt);
    }
}

void Widget::on_pushButton_3_clicked()
{
    bool ok = false;
    int iVal = QInputDialog::getInt(this,
                        "输入整数",
                        "请输入字体大小：",
                        ui->plainTextEdit->font().pointSize(),
                        6, 40, 1,
                        &ok);
    if(ok){
        QFont font = ui->plainTextEdit->font();
        font.setPointSize(iVal);
        ui->plainTextEdit->setFont(font);
    }
}

void Widget::on_pushButton_4_clicked()
{
    QStringList items;
    items << "黑龙江" << "吉林" << "辽宁" << "河北" << "山东";
    bool ok = false;
    QString text = QInputDialog::getItem(this, "选择项", "请选择省份",
                                         items, 0, true, &ok,
                                         Qt::MSWindowsFixedSizeDialogHint);
    if(ok && !text.isEmpty()){
        ui->plainTextEdit->appendPlainText(text);
    }
}

void Widget::on_pushButton_5_clicked()
{
    bool ok = false;
    QString text = QInputDialog::getText(this, "输入串", "请输入串：",
                                         QLineEdit::Password, //::Normal
                                         "1234", &ok,
                                         Qt::MSWindowsFixedSizeDialogHint);
    if(ok && !text.isEmpty()){
        ui->plainTextEdit->appendPlainText(text);
    }
}

void Widget::on_pushButton_6_clicked()
{
    auto res = QMessageBox::question(this, "消息", "保存不？",
                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                    QMessageBox::NoButton);
    if(res==QMessageBox::Yes)
        ui->plainTextEdit->appendPlainText("yes");
    if(res==QMessageBox::No)
        ui->plainTextEdit->appendPlainText("no");
    if(res==QMessageBox::Cancel)
        ui->plainTextEdit->appendPlainText("cancel");

}
