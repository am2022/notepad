#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionNew_triggered()
{
    ui->textEdit->clear();
}

void MainWindow::on_actionOpen_triggered()
{
    QMessageBox msg;
    QString filename = QFileDialog::getOpenFileName(this, "Add File", "/home", tr("Text Files (*.txt)"));

    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        msg.setText("you enter invalid file!");
        msg.exec();
        file.close();
        return;
    }

    this->setWindowTitle(filename);

    QTextStream read(&file);

    QString text = read.readAll();

    ui->textEdit->setText(text);

    file.close();
}
