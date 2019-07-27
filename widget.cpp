#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
using std::string;
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

void Widget::changeMoney(int n){
    money += n;
    ui->total_number->display(QString::number(money));
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffe_clicked()
{
    // if ui->total_number->intValue() >= 100 not first => not active this button
    if (ui->total_number->intValue()>=100){
        ui->pbCoffe->setEnabled(true);
        changeMoney(-100);
    }
    else{
        ui->pbCoffe->setEnabled(false);
        ui->pbCoffe->setEnabled(true);
    }
}

void Widget::on_pbTea_clicked()
{
    if (ui->total_number->intValue()>=150){
        ui->pbTea->setEnabled(true);
        changeMoney(-150);
    }
    else{
        ui->pbTea->setEnabled(false);
        ui->pbTea->setEnabled(true);
    }
}

void Widget::on_pbGongcha_clicked()
{
    if (ui->total_number->intValue()>=200){
        ui->pbGongcha->setEnabled(true);
        changeMoney(-200);
    }
    else{
        ui->pbGongcha->setEnabled(false);
        ui->pbGongcha->setEnabled(true);
    }
}

void Widget::on_pbReturn_clicked()
{
    QMessageBox msg;
    int res_coin[] = {500, 100, 50, 10};
    int Remain_coin = ui->total_number->intValue();
    int num=0;
    int loop = 0;
    int count[4];
    for (int i = 0; i < 4; i++ ){
      loop = 0;
      while(res_coin[i] <= Remain_coin){
           num = Remain_coin/res_coin[i];
           Remain_coin -= (num*res_coin[i]);
           loop += num;
        }
      count[i] = loop;
    }

    QString status = QString("500won : %1\n 100won : %2\n 50won : %3\n 10won : %4").arg(count[0]).arg(count[1]).arg(count[2]).arg(count[3]);
    msg.information(nullptr, tr("Info"), status);
}
