#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QOpenGLWidget>
#include <QtWidgets/QFileDialog.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->on_pushButton_clicked();
//    ui->comboBox->setItemText(0,"Blue");
//     ui->comboBox->setItemText(1,"Black");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    OpenFileDialog openfile;
    QString filename = openfile.GetFileName();
        if (!filename.isEmpty())
        {
            ui->lineEdit->setText(filename);
            ui->openGLWidget->setFilename(filename);
        }
}


void MainWindow::on_pushButton_2_clicked()
{
    QString file = QFileDialog::getSaveFileName(this, "Save as...", "name", "PNG (*.png);; BMP (*.bmp);;TIFF (*.tiff *.tif);; JPEG (*.jpg *.jpeg)");
    if (!file.isEmpty())
    ui->openGLWidget->grab().save(file);
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->openGLWidget->setColor(ui->comboBox->currentText());
    ui->openGLWidget->repaint();
}

void MainWindow::on_pushButton_3_clicked()
{

    QPixmap map = ui->openGLWidget->grab();
    printf("You get a gif!");
}

