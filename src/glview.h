#ifndef GLVIEW_H
#define GLVIEW_H

//#include <QGLWidget>
//#include <QWidget>
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
//#include "mainwindow.h"

extern "C" {
#include "obj_reader.h"
#include "affins.h"
}



class glView : public QOpenGLWidget
{
public:
    glView(QWidget*parent=nullptr);
//    glView(MainWindow mainwindow);
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void setFilename(QString);
    void setColor(QString);
protected:
    void wheelEvent(QWheelEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
     void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
private:
    void setMetrics();
    QString filename;
    GLfloat back_red; // 0 - 255
    GLfloat back_blue; // 0 - 255
    GLfloat back_green; // 0 -255
    GLfloat back_alpha; // 0 - 100
    int scale;
    int speed;
    double x;
    double y;
    double move_x;
    double move_y;
    double position_x;
    double position_y;
    bool shift;
};

#endif // GLVIEW_H
