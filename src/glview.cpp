#include "glview.h"

glView::glView(QWidget*parent):QOpenGLWidget(parent) {
    this->filename= "";
    this->back_red = 0;
    this->back_green = 0;
    this->back_blue = 1;
    this->back_alpha = 0;
    this->speed = 120;
    this->size_edges = 5;
    this->size_vertex = 0.5;
    this->count_vector = 0, this->count_surface = 0;
    setMetrics();
}

void glView::setEdges(double size) {
    this->size_edges = size;
     this->repaint();
}
void glView::setVertex(double size) {
    this->size_vertex = size;
     this->repaint();
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
     if (obj_read(filename.toStdString().c_str(), &this->vectors, &this->surface,
             &(this->count_vector), &this->count_surface) )
     {
         this->filename=filename;
         setMetrics();
     }
}

void glView::setShift(double x, double y, double z) {
    this->repaint();
}

void glView::wheelEvent(QWheelEvent *event) {
    this->scale+=(double)event->angleDelta().y()/speed;
    printf("what the");
    this->repaint();
}

void glView::mousePressEvent(QMouseEvent *event) {
    this->position_x=event->scenePosition().x();
    this->position_y=event->scenePosition().y();
}

void glView::mouseMoveEvent(QMouseEvent *event){
    if (!shift)
    {
        this->x=event->position().x()/this->size().height()/2.14;
        this->y=event->position().y()/this->size().width()/2.14;
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

//  vector *vectors;
//  surface_dot *surface;
//  int count_vector = 0, count_surface = 0;
//  if (obj_read(this->filename.toStdString().c_str(), &vectors, &surface,
//           &count_vector, &count_surface) )
    if (this->count_vector)
  {
      this->vectors = move_xyz(this->vectors, this->count_vector, this->move_x, this->move_y, 0); // перемещение по x, y, z
      this->vectors = size_xyz(this->vectors, this->count_vector, this->scale, this->scale, this->scale); // масштабирование по x, y, z
      this->vectors = rotation_x(this->vectors, this->count_vector, this->x); // поворот по x
      this->vectors = rotation_y(this->vectors, this->count_vector, this->y); // поворот по y
      glEnable(GL_POINT_SMOOTH);
      glClearColor(this->back_red, this->back_green, this->back_blue, this->back_alpha);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      //команды отрисовки точек
      glColor3d(1, 1, 0.5);
      glPointSize(this->size_edges);
      glBegin(GL_POINTS);
      for (int i = 0; i < this->count_vector; i++) {
          glVertex3d(this->vectors[i].x, this->vectors[i].y, this->vectors[i].z);
      }
      glEnd();
      //команды отрисовки линий
      for (int i = 0; i < this->count_surface; i++) {
          glColor3d(0.5, 0.5, 0.5);
          glLineWidth(this->size_vertex);
          glBegin(GL_LINE_LOOP);
          for (int j = 0; j < surface[i].number_dot_surface; j++) {
              int index = surface[i].v[j] - 1;
              glVertex3d(this->vectors[index].x, this->vectors[index].y, this->vectors[index].z);
          }
          glEnd();
      }
  }

}
