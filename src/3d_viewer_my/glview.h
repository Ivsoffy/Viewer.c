#ifndef GLVIEW_H
#define GLVIEW_H

//#include <QGLWidget>
//#include <QWidget>
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QDoubleSpinBox>
#include <QScrollBar>


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
    void SetPallette(QColor color){
        this->_red=color.redF();
        this->_blue=color.blueF();
        this->_green=color.greenF();
        this->_alpha=color.alphaF();
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


};

class glView : public QOpenGLWidget
{
        Q_OBJECT
private:
    void setMetrics();
    QString filename;
    vector *vectors;
    vector *current_vectors;
    surface_dot *surface;
    QList<ColorPallette> colorBackground;
    ColorPallette* currentBackground;
    ColorPallette* colorVertex;
     ColorPallette* colorEdges;
    double speed;
    double position_x;
    double position_y;
    bool shift;
    double size_edges;
    double size_vertex;
    int count_vector, count_surface;
    QDoubleSpinBox* Shift_X;
    QDoubleSpinBox* Shift_Y;
    QDoubleSpinBox* Shift_Z;
    QDoubleSpinBox* Rotate_X;
    QDoubleSpinBox* Rotate_Y;
    QDoubleSpinBox* Rotate_Z;
    QDoubleSpinBox* Shift_Size;
    difference diff;
    QList<QImage> frames;
    QTimer* timer;
    QString fileGIF;
public:
    int pointType;
    int VertexType;
    int ProjectionType;
    glView(QWidget*parent=nullptr);
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void setFilename(QString);
    int GetVectors();
    int GetSurface();
    void setColor(QString);
    void AddColor(QColor, QString);
    void AddColorModel(QColor, QString);
    void setEdges(double);
    void setVertex(double);
    void SetShift_Z(double);
    void SetShift_X(double);
    void SetShift_Y(double);
    void SetRotate_X(double);
    void SetRotate_Y(double);
    void SetRotate_Z(double);
    void SetScaling(double);
    void SetShift_XYZ(QDoubleSpinBox*, QDoubleSpinBox*, QDoubleSpinBox*, QDoubleSpinBox*);
    void SetRotate_XYZ(QDoubleSpinBox*, QDoubleSpinBox*, QDoubleSpinBox*);
    void recalc();
    void TakeGif(QString);
    void SaveGif();
    void UpdateProjection(int);
    QScrollBar* Time;
private slots:
    void TakePic();
protected:
    void wheelEvent(QWheelEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
     void mousePressEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

};

#endif // GLVIEW_H
