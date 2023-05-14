#include "glview.h"

glView::glView(QWidget*parent):QOpenGLWidget(parent) {
    this->colorBackground.push_back(ColorPallette("Saphire", 0, 1, 0, 0));
    this->colorBackground.push_back(ColorPallette("White", 255, 255, 255, 0));
    this->colorBackground.push_back(ColorPallette("Black", 0, 0, 0, 0));
    currentBackground = new ColorPallette();
    this->filename= "";
    this->speed = 1000;
    this->size_edges = 5;
    this->size_vertex = 0.5;
    this->count_vector = 0, this->count_surface = 0;
    setMetrics();
}

void glView::initializeGL() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-4, 4, 4, -4, -4, 4);
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


void glView::setEdges(double size) {
    this->size_edges = size;
     this->update();
}
void glView::setVertex(double size) {
    this->size_vertex = size;
     this->update();
}


void glView::setColor(QString color) {
    for (ColorPallette pallette: this->colorBackground){
        if(pallette.Name()==color)
            *currentBackground = pallette;
    }
}

void glView::AddColor(QColor color, QString Colorname) {
    this->colorBackground.push_back(ColorPallette(Colorname, color.redF(), color.blueF(), color.greenF(), color.alphaF()));
    *currentBackground = colorBackground.at(this->colorBackground.size()-1);
}


void glView::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
        int size = 1000;
}

int glView::GetVectors() {
    return this->count_vector;
}
int glView::GetSurface() {
    return this->count_surface;
}

void glView::setFilename(QString filename) {
     if (obj_read(filename.toStdString().c_str(), &this->vectors, &this->surface,
             &(this->count_vector), &this->count_surface) )
     {
         this->current_vectors = new vector[count_vector];
         for (int j = 0; j < count_vector; j++)
         {
             this->current_vectors[j].x=this->vectors[j].x;
             this->current_vectors[j].y=this->vectors[j].y;
             this->current_vectors[j].z=this->vectors[j].z;
         }
         this->filename=filename;
         setMetrics();
     }
}

void glView::SetShift_Z(double Z) {
    this->scale=Z;
    this->current_vectors = size_xyz(this->vectors, this->count_vector, Z, Z, Z, this->current_vectors); // масштабирование по x, y, z
    this->Shift_Z->setValue(Z);
    this->update();
}

void glView::wheelEvent(QWheelEvent *event) {
    if (event->position().x()>0 && event->position().y()>0)
    {
        this->scale+=(double)event->angleDelta().y()/speed;
        this->current_vectors = size_xyz(this->vectors, this->count_vector, this->scale, this->scale, this->scale, this->current_vectors); // масштабирование по x, y, z
        this->Shift_Z->setValue(this->scale);
        this->update();
    }
}

void glView::mousePressEvent(QMouseEvent *event) {
    this->position_x=event->scenePosition().x();
    this->position_y=event->scenePosition().y();
}

void glView::mouseMoveEvent(QMouseEvent *event){
    if (!shift)
    {
        this->x=event->position().x()/this->size().height()/5;
        this->y=event->position().y()/this->size().width()/5;
        this->current_vectors = rotation_x(this->vectors, this->count_vector, this->x, this->current_vectors); // поворот по x
        this->current_vectors = rotation_y(this->vectors, this->count_vector, this->y, this->current_vectors); // поворот по y
    } else {
        this->move_x -= (event->scenePosition().x() - this->position_x)/50;
        this->move_y +=  (event->scenePosition().y() - this->position_y)/50;
        this->current_vectors = move_xyz(this->vectors, this->count_vector, this->move_x, this->move_y, 0, this->current_vectors); // перемещение по x, y, z
        this->position_x=event->scenePosition().x();
        this->position_y=event->scenePosition().y();
                this->Shift_X->setValue(this->scale);
    }

    this->update();
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
    if (this->count_vector)
  {

      glEnable(GL_POINT_SMOOTH);
      glClearColor(this->currentBackground->Red(), this->currentBackground->Green(), this->currentBackground->Blue(), this->currentBackground->Alpha());
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      //команды отрисовки точек
      glColor3d(1, 1, 0.5);
      glPointSize(this->size_edges);
      glBegin(GL_POINTS);
      for (int i = 0; i < this->count_vector; i++) {
          glVertex3d(this->current_vectors[i].x, this->current_vectors[i].y, this->current_vectors[i].z);
      }
      glEnd();
      //команды отрисовки линий
      glColor3d(0.5, 0.5, 0.5);
      glLineWidth(this->size_vertex);
      for (int i = 0; i < this->count_surface; i++) {
          glBegin(GL_LINE_LOOP);
          for (int j = 0; j < surface[i].number_dot_surface; j++) {
              int index = surface[i].v[j] - 1;
              glVertex3d(this->current_vectors[index].x, this->current_vectors[index].y, this->current_vectors[index].z);
          }
          glEnd();
      }
  }
}
