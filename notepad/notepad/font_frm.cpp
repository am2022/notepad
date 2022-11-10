#include "font_frm.h"
#include "ui_font_frm.h"

font_frm::font_frm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::font_frm)
{
    ui->setupUi(this);
}

font_frm::~font_frm()
{
    delete ui;
}
