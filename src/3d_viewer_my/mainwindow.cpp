#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QOpenGLWidget>
#include <QtWidgets/QFileDialog.h>
#include <QColorDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    countCustomColor = 1;
    ui->openGLWidget->SetShift_XYZ(this->ui->Shift_X, this->ui->Shift_Y, this->ui->Shift_Z);
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


void MainWindow::on_Projection_Color_clicked()
{
    QColor color = QColorDialog::getColor(QColor("white"), this);
    if (color.isValid()){
        QString name = "Custom "+ QString::number(this->countCustomColor);
        countCustomColor++;
        ui->openGLWidget->AddColor(color, name);
        ui->comboBox->addItem(name);
        ui->comboBox->setCurrentIndex(ui->comboBox->count()-1);
    }
}


void MainWindow::on_Vertex_Color_clicked()
{

}


void MainWindow::on_Edges_Color_clicked()
{

}


void MainWindow::on_Shift_X_textChanged(const QString &arg1)
{
 ui->Scroll_ShiftX->setValue(ui->Shift_X->text().toFloat()*100);
}

void MainWindow::on_Shift_Y_textChanged(const QString &arg1)
{
 ui->Scroll_ShiftY->setValue(ui->Shift_Y->text().toFloat()*100);
}

void MainWindow::on_Shift_Z_textChanged(const QString &arg1)
{
    ui->Scroll_ShiftZ->setValue(ui->Shift_Z->text().toFloat()*100);
}

void MainWindow::on_Scroll_ShiftX_sliderMoved(int position)
{
    double shift = (double)position/100;
    ui->openGLWidget->SetShift_X(shift);
}

void MainWindow::on_Scroll_ShiftY_sliderMoved(int position)
{
    double shift = (double)position/100;
    ui->openGLWidget->SetShift_Y(shift);
}

void MainWindow::on_Scroll_ShiftZ_sliderMoved(int position)
{
    double shift = (double)position/100;
    ui->openGLWidget->SetShift_Z(shift);
//    printf("I'm here! 111\n");
}

void MainWindow::on_Scroll_RotateX_sliderMoved(int position)
{
    double shift = (double)position/100;
    ui->openGLWidget->SetRotate_X(shift);
}


void MainWindow::on_Scroll_RotateY_sliderMoved(int position)
{
    double shift = (double)position/100;
    ui->openGLWidget->SetRotate_Y(shift);
}


void MainWindow::on_Scroll_RotateZ_sliderMoved(int position)
{
    double shift = (double)position/100;
   ui->openGLWidget->SetRotate_Z(shift);
}

