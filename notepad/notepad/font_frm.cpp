#include "font_frm.h"
#include "ui_font_frm.h"
#include <QMessageBox>

int global_font_num;

font_frm::font_frm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::font_frm)
{
    ui->setupUi(this);
    setStyleSheet("background-color:white;");
    ui->pushButton->setStyleSheet("background-color:rgb(122, 235, 52);");
    ui->label->setStyleSheet("background-color:white;");
    ui->spinBox->setStyleSheet("background-color:white;");
}

font_frm::~font_frm()
{
    delete ui;
}

void font_frm::on_pushButton_clicked()
{
    int font_num;
    font_num = ui->spinBox->value();

    global_font_num = font_num;

    QMessageBox msg;

    msg.setText("after you click to enter button you should click to update button in menu.");
    msg.exec();

    this->close();
}

int font_frm::show_font_num()
{
    int font_num;
    font_num = global_font_num;

    return font_num;
}
