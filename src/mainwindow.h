#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glview.h"
#include "openfiledialog.h"

//#include <QPainter>

extern "C" {
#include "obj_reader.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_3_clicked();

    void on_spinBox_2_textChanged(const QString &arg1);

    void on_spinBox_textChanged(const QString &arg1);

    void on_doubleSpinBox_textChanged(const QString &arg1);

    void on_doubleSpinBox_2_textChanged(const QString &arg1);

    void on_horizontalScrollBar_4_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
