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

    void on_doubleSpinBox_textChanged(const QString &arg1);

    void on_doubleSpinBox_2_textChanged(const QString &arg1);

    void on_Projection_Color_clicked();

    void on_Vertex_Color_clicked();

    void on_Edges_Color_clicked();

    void on_Shift_X_editingFinished();

    void on_Shift_Z_editingFinished();

    void on_Shift_Y_editingFinished();

    void on_Scroll_ShiftZ_sliderMoved(int position);

    void on_Scroll_ShiftY_sliderMoved(int position);

    void on_Scroll_ShiftX_sliderMoved(int position);

    void on_Scroll_RotateX_sliderMoved(int position);

    void on_Scroll_RotateY_sliderMoved(int position);

    void on_Scroll_RotateZ_sliderMoved(int position);

    void on_Scroll_ShiftSize_sliderMoved(int position);

    void on_Shift_Size_editingFinished();

private:
    Ui::MainWindow *ui;
    int countCustomColor;
};
#endif // MAINWINDOW_H
