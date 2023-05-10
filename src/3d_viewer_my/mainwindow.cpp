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
            ui->lineEdit_2->setText(QString::number(ui->openGLWidget->GetVectors()));
            ui->lineEdit_3->setText(QString::number(ui->openGLWidget->GetSurface()));
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





void MainWindow::on_doubleSpinBox_textChanged(const QString &arg1)
{
     ui->openGLWidget->setVertex(ui->doubleSpinBox->value());
}


void MainWindow::on_doubleSpinBox_2_textChanged(const QString &arg1)
{
     ui->openGLWidget->setEdges(ui->doubleSpinBox_2->value());
}


void MainWindow::on_horizontalScrollBar_4_sliderMoved(int position)
{
ui->openGLWidget->setShift(0 ,0 , ui->horizontalScrollBar_4->value());
}

