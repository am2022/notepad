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
    this->setWindowTitle("notepad");
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
    this->setWindowTitle("notepad");
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

void MainWindow::on_actionSave_As_triggered()
{
    QString filename;
    filename = QFileDialog::getSaveFileName(this, "Save");

    QFile file(filename);

    file.open(QIODevice::WriteOnly);

    QTextStream write(&file);

    QString text = ui->textEdit->toPlainText();

    write<<text;

    file.close();
}

void MainWindow::on_actionZoom_In_triggered()
{
    ui->textEdit->zoomIn();
}

void MainWindow::on_actionZoom_Out_triggered()
{
    ui->textEdit->zoomOut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}
