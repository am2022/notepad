#include "font_frm.h"
#include "ui_font_frm.h"

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
