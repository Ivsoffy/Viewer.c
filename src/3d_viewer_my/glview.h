#ifndef GLVIEW_H
#define GLVIEW_H

//#include <QGLWidget>
//#include <QWidget>
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QDoubleSpinBox>

extern "C" {
#include "obj_reader.h"
#include "affins.h"
}

class ColorPallette {
private:
    GLfloat _red; // 0 - 255
    GLfloat _blue; // 0 - 255
    GLfloat _green; // 0 -255
    GLfloat _alpha; // 0 - 100
    QString _name;
public:
    ColorPallette(QString name, GLfloat red,  GLfloat blue, GLfloat green, GLfloat alpha) {
        this->_red = red;
        this->_blue = blue;
        this->_green = green;
        this->_alpha = alpha;
        this->_name = name;
    }
    ColorPallette() {
        this->_red = 0;
        this->_blue = 1;
        this->_green = 0;
        this->_alpha = 0;
        this->_name = "Saphire";
    }
    QString Name() {
        return _name;
    }
    GLfloat Red() {
        return _red;
    }
    GLfloat Blue() {
        return _blue;
    }
    GLfloat Green() {
        return _green;
    }
    GLfloat Alpha() {
        return _alpha;
    }

    bool Compare(QColor color){
        return color.alphaF()==_alpha && color.redF()==_red && color.blueF()==_blue && color.greenF()==_green ? 1 : 0;
    }

};

class glView : public QOpenGLWidget
{
private:
    void setMetrics();
    QString filename;
    vector *vectors;
    vector *current_vectors;
    surface_dot *surface;
    QList<ColorPallette> colorBackground;
    ColorPallette* currentBackground;
    double scale;
    double speed;
    double x;
    double y;
    double move_x;
    double move_y;
    double position_x;
    double position_y;
    bool shift;
    double size_edges;
    double size_vertex;
    int count_vector, count_surface;
    QDoubleSpinBox* Shift_X;
    QDoubleSpinBox* Shift_Y;
    QDoubleSpinBox* Shift_Z;
public:
    difference diff;
    glView(QWidget*parent=nullptr);
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void setFilename(QString);
    int GetVectors();
    int GetSurface();
    void setColor(QString);
    void AddColor(QColor, QString);
    void setEdges(double);
    void setVertex(double);
    void SetShift_Z(double);
    void SetShift_X(double);
    void SetShift_Y(double);
    void SetRotate_X(double);
    void SetRotate_Y(double);
    void SetRotate_Z(double);
    void SetShift_XYZ(QDoubleSpinBox*, QDoubleSpinBox*, QDoubleSpinBox*);
    void recalc();
protected:
    void wheelEvent(QWheelEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
     void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

};

#endif // GLVIEW_H
