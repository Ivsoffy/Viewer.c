#include "glview.h"

glView::glView(QWidget*parent):QOpenGLWidget(parent) {
    this->filename= "";
    this->back_red = 0;
    this->back_green = 0;
    this->back_blue = 1;
    this->back_alpha = 0;
    this->speed = 120;
    setMetrics();

}

void glView::setMetrics() {
    this->scale = 1;
    this->x=0;
    this->y=0;
    this->shift=0;
    this->move_x=0;
    this->move_y=0;
    this->position_x =0;
    this->position_y=0;
}

void glView::setColor(QString color) {
    if (color == "Saphire") {
        this->back_red = 0;
        this->back_green = 0;
        this->back_blue = 1;
        this->back_alpha = 0;
    } else if (color == "White") {
        this->back_red = 255;
        this->back_green = 255;
        this->back_blue = 255;
        this->back_alpha = 0;
    }
    else if (color == "Black") {
            this->back_red = 0;
            this->back_green = 0;
            this->back_blue = 0;
            this->back_alpha = 0;
    }
}

void glView::initializeGL() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-8, 8, 8, -8, -8, 8);
}

void glView::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
        int size = 1000;
}

void glView::setFilename(QString filename) {
    this->filename=filename;
    setMetrics();
}

void glView::wheelEvent(QWheelEvent *event) {
    this->scale+=event->angleDelta().y()/this->speed;
    this->repaint();
}

void glView::mousePressEvent(QMouseEvent *event) {
    this->position_x=event->scenePosition().x();
    this->position_y=event->scenePosition().y();
}

void glView::mouseMoveEvent(QMouseEvent *event){
    if (!shift)
    {
        this->x=event->position().x()/this->size().height()*6.28;
        this->y=event->position().y()/this->size().width()*6.28;
    } else {
        this->move_x -= (event->scenePosition().x() - this->position_x)/50;
        this->move_y +=  (event->scenePosition().y() - this->position_y)/50;
        this->position_x=event->scenePosition().x();
        this->position_y=event->scenePosition().y();
    }
    this->repaint();
}

void glView::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Shift)
        this->shift=1;
}

void glView::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Shift)
        this->shift=0;
}

void glView::paintGL() {

  vector *vectors;
  surface_dot *surface;
  int count_vector = 0, count_surface = 0;
  if (obj_read(this->filename.toStdString().c_str(), &vectors, &surface,
           &count_vector, &count_surface) )
  {
      vectors = move_xyz(vectors, count_vector, this->move_x, this->move_y, 0); // перемещение по x, y, z
      vectors = size_xyz(vectors, count_vector, this->scale, this->scale, this->scale); // масштабирование по x, y, z
      vectors = rotation_x(vectors, count_vector, this->x); // поворот по x
      vectors = rotation_y(vectors, count_vector, this->y); // поворот по y
      glEnable(GL_POINT_SMOOTH);
      glClearColor(this->back_red, this->back_green, this->back_blue, this->back_alpha);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      //команды отрисовки точек
      glColor3d(1, 1, 0.5);
      glPointSize(5);
      glBegin(GL_POINTS);
      for (int i = 0; i < count_vector; i++) {
          glVertex3d(vectors[i].x, vectors[i].y, vectors[i].z);
      }
      glEnd();
      //команды отрисовки линий
      for (int i = 0; i < count_surface; i++) {
          glColor3d(0.5, 0.5, 0.5);
          glBegin(GL_LINE_LOOP);
          for (int j = 0; j < surface[i].number_dot_surface; j++) {
              int index = surface[i].v[j] - 1;
              glVertex3d(vectors[index].x, vectors[index].y, vectors[index].z);
          }
          glEnd();
      }
  }

}
