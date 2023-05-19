#include "mainwindow.h"

#include <QtWidgets/QFileDialog.h>

#include <QColorDialog>
#include <QMessageBox>
#include <QOpenGLWidget>
#include <QSettings>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  readSettings();
  countCustomColor = 1;
  ui->openGLWidget->SetShift_XYZ(this->ui->Shift_X, this->ui->Shift_Y,
                                 this->ui->Shift_Z, this->ui->Shift_Size);
  ui->openGLWidget->SetRotate_XYZ(this->ui->Rotate_X, this->ui->Rotate_Y,
                                  this->ui->Rotate_Z);
  ui->openGLWidget->Time = ui->ScrollTimer;
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::closeEvent(QCloseEvent *event) {
  QMessageBox::StandardButton resBtn = QMessageBox::question(
      this, "A", tr("Save current Settinings?\n"),
      QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
      QMessageBox::Yes);
  if (resBtn != QMessageBox::Yes) {
    if (resBtn == QMessageBox::No) {
      event->accept();
    } else {
      event->ignore();
    }
  } else {
    writeSettings();
    event->accept();
  }
}

void MainWindow::writeSettings() {
  QSettings settings("Cabbage.conf", "AAA");
  int indexVertex = ui->Vertex_Settenings->currentIndex();
  int indexEdges = ui->Edges_Settenings->currentIndex();
  double lineWidth = ui->doubleSpinBox->value();
  double pointWidth = ui->doubleSpinBox_2->value();
  int index_typeProjection = ui->comboBox_4->currentIndex();
  int index_colorProjection = ui->comboBox->currentIndex();
  settings.beginGroup("MainWindow_UI");
  settings.setValue("Vertex_Settenings/indexVertex", indexVertex);
  settings.setValue("Edges_Settenings/indexEdges", indexEdges);
  settings.setValue("doubleSpinBox/lineWidth", lineWidth);
  settings.setValue("doubleSpinBox_2/pointWidth", pointWidth);
  settings.setValue("comboBox_4/index_typeProjection", index_typeProjection);
  settings.setValue("comboBox/index_colorProjection", index_colorProjection);
  settings.setValue("file/filename", ui->lineEdit->text());

  settings.endGroup();
}

void MainWindow::readSettings() {
  QSettings settings("Cabbage.conf", "AAA");
  settings.beginGroup("MainWindow_UI");
  ui->Edges_Settenings->currentIndexChanged(
      settings.value("Vertex_Settenings/indexVertex").toInt());
  ui->Vertex_Settenings->currentIndexChanged(
      settings.value("Edges_Settenings/indexEdges").toInt());
  ui->Edges_Settenings->setCurrentIndex(
      settings.value("Edges_Settenings/indexEdges").toInt());
  ui->Vertex_Settenings->setCurrentIndex(
      settings.value("Vertex_Settenings/indexVertex").toInt());
  ui->comboBox->setCurrentIndex(
      settings.value("comboBox/index_colorProjection").toInt());
  ui->comboBox_4->setCurrentIndex(
      settings.value("comboBox_4/index_typeProjection").toInt());
  ui->doubleSpinBox->setValue(
      settings.value("doubleSpinBox/lineWidth").toDouble());
  ui->doubleSpinBox_2->setValue(
      settings.value("doubleSpinBox_2/pointWidth").toDouble());
  ui->lineEdit->setText(settings.value("file/filename").toString());
  ui->openGLWidget->setFilename(settings.value("file/filename").toString());
  settings.endGroup();
}

void MainWindow::on_pushButton_clicked() {
  OpenFileDialog openfile;
  QString filename = openfile.GetFileName();
  if (!filename.isEmpty()) {
    ui->lineEdit->setText(filename);
    ui->openGLWidget->setFilename(filename);
    ui->lineEdit_2->setText(QString::number(ui->openGLWidget->GetVectors()));
    ui->lineEdit_3->setText(QString::number(ui->openGLWidget->GetSurface()));
  }
}

void MainWindow::on_pushButton_2_clicked() {
  QString file = QFileDialog::getSaveFileName(
      this, "Save as...", "name", "BMP (*.bmp);; JPEG (*.jpg *.jpeg)");
  if (!file.isEmpty()) ui->openGLWidget->grab().save(file);
}

void MainWindow::on_comboBox_currentIndexChanged(int index) {
  ui->openGLWidget->setColor(ui->comboBox->currentText());
  ui->openGLWidget->repaint();
}

void MainWindow::on_pushButton_3_clicked() {
  QString filename = QFileDialog::getSaveFileName(NULL, "Save to ...", "",
                                                  "GIF image (*.gif)");
  if (!filename.isEmpty()) ui->openGLWidget->TakeGif(filename);
}

void MainWindow::on_doubleSpinBox_textChanged(const QString &arg1) {
  ui->openGLWidget->setVertex(ui->doubleSpinBox->value());
}

void MainWindow::on_doubleSpinBox_2_textChanged(const QString &arg1) {
  if (ui->Edges_Settenings->currentIndex() != 2)
    ui->openGLWidget->setEdges(ui->doubleSpinBox_2->value());
}

void MainWindow::on_Projection_Color_clicked() {
  QColor color = QColorDialog::getColor(QColor("white"), this);
  if (color.isValid()) {
    QString name = "Custom " + QString::number(this->countCustomColor);
    countCustomColor++;
    ui->openGLWidget->AddColor(color, name);
    ui->comboBox->addItem(name);
    ui->comboBox->setCurrentIndex(ui->comboBox->count() - 1);
  }
}

void MainWindow::on_Vertex_Color_clicked() {
  QColor color = QColorDialog::getColor(QColor("white"), this);
  if (color.isValid()) ui->openGLWidget->AddColorModel(color, "vertex");
}

void MainWindow::on_Edges_Color_clicked() {
  QColor color = QColorDialog::getColor(QColor("white"), this);
  if (color.isValid()) ui->openGLWidget->AddColorModel(color, "edges");
}

void MainWindow::on_Shift_Size_editingFinished() {
  ui->Scroll_ShiftSize->setValue(ui->Shift_Size->text().toFloat() * 10);
  ui->openGLWidget->SetScaling(ui->Shift_Size->value());
}

void MainWindow::on_Shift_X_editingFinished() {
  ui->Scroll_ShiftX->setValue(ui->Shift_X->text().toFloat() * 100);
  ui->openGLWidget->SetShift_X(ui->Shift_X->value());
}

void MainWindow::on_Shift_Y_editingFinished() {
  ui->Scroll_ShiftY->setValue(ui->Shift_Y->text().toFloat() * 100);
  ui->openGLWidget->SetShift_Y(ui->Shift_Y->value());
}

void MainWindow::on_Shift_Z_editingFinished() {
  ui->Scroll_ShiftZ->setValue(ui->Shift_Z->text().toFloat() * 100);
  ui->openGLWidget->SetShift_Z(ui->Shift_Z->value());
}

void MainWindow::on_Rotate_X_editingFinished() {
  ui->Scroll_RotateX->setValue(ui->Rotate_X->text().toFloat());
  ui->openGLWidget->SetRotate_X(ui->Rotate_X->value() * (3.14 / 180));
}

void MainWindow::on_Rotate_Y_editingFinished() {
  ui->Scroll_RotateY->setValue(ui->Rotate_Y->text().toFloat());
  ui->openGLWidget->SetRotate_Y(ui->Rotate_Y->value() * (3.14 / 180));
}

void MainWindow::on_Rotate_Z_editingFinished() {
  ui->Scroll_RotateZ->setValue(ui->Rotate_Z->text().toFloat());
  ui->openGLWidget->SetRotate_Z(ui->Rotate_Z->value() * (3.14 / 180));
}

void MainWindow::on_Scroll_ShiftSize_sliderMoved(int position) {
  double shift = (double)position / 10;
  ui->openGLWidget->SetScaling(shift);
}

void MainWindow::on_Scroll_ShiftX_sliderMoved(int position) {
  double shift = (double)position / 100;
  ui->openGLWidget->SetShift_X(shift);
}

void MainWindow::on_Scroll_ShiftY_sliderMoved(int position) {
  double shift = (double)position / 100;
  ui->openGLWidget->SetShift_Y(shift);
}

void MainWindow::on_Scroll_ShiftZ_sliderMoved(int position) {
  double shift = (double)position / 100;
  ui->openGLWidget->SetShift_Z(shift);
}

void MainWindow::on_Scroll_RotateX_sliderMoved(int position) {
  double shift = (double)position / 100;
  ui->openGLWidget->SetRotate_X(shift);
}

void MainWindow::on_Scroll_RotateY_sliderMoved(int position) {
  double shift = (double)position / 100;
  ui->openGLWidget->SetRotate_Y(shift);
}

void MainWindow::on_Scroll_RotateZ_sliderMoved(int position) {
  double shift = (double)position / 100;
  ui->openGLWidget->SetRotate_Z(shift);
}

void MainWindow::on_Edges_Settenings_currentIndexChanged(int index) {
  ui->openGLWidget->pointType = index;
  ui->openGLWidget->update();
}

void MainWindow::on_Vertex_Settenings_currentIndexChanged(int index) {
  ui->openGLWidget->VertexType = index;
  ui->openGLWidget->update();
}

void MainWindow::on_comboBox_4_currentIndexChanged(int index) {
  ui->openGLWidget->UpdateProjection(index);
}
