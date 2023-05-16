#include "glview.h"

glView::glView(QWidget*parent):QOpenGLWidget(parent) {
    this->colorBackground.push_back(ColorPallette("Saphire", 0, 1, 0, 0));
    this->colorBackground.push_back(ColorPallette("White", 255, 255, 255, 0));
    this->colorBackground.push_back(ColorPallette("Black", 0, 0, 0, 0));

    this->colorVertex = new ColorPallette("Standart", 0.5, 0.5, 0.5, 0);
    this->colorEdges = new ColorPallette("Standart", 1, 1, 0.5, 0);
    currentBackground = new ColorPallette();
    this->shift=0;
    this->filename= "";
    this->speed = 120;
    this->size_edges = 5;
    this->size_vertex = 0.5;
    this->count_vector = 0, this->count_surface = 0;
    setMetrics();
}

void glView::initializeGL() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-4, 4, 4, -4, -100, 100);
}

void glView::SetShift_XYZ(QDoubleSpinBox* X, QDoubleSpinBox* Y, QDoubleSpinBox* Z, QDoubleSpinBox* Size) {
   this->Shift_X = X;
    this->Shift_Y = Y;
    this->Shift_Z = Z;
    this->Shift_Size = Size;
}

void glView::setMetrics() {
    this->shift=0;
    this->position_x =0;
    this->position_y=0;
    diff.size=1;
    diff.x_move=0;
    diff.y_move=0;
    diff.z_move=0;
    diff.x_alpha=0;
    diff.y_alpha=0;
    diff.z_alpha=0;
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

void glView::AddColorModel(QColor color, QString type){
   if (type=="vertex")
       this->colorVertex->SetPallette(color);
   else if (type=="edges")
       this->colorEdges->SetPallette(color);
   this->update();
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
//            printf("%lf %lf\n", this->vectors[0].x, this->current_vectors[0].x);
         this->filename=filename;
         setMetrics();
     }
}

void glView::recalc() {
   recalculation(this->vectors, this->count_vector, this->current_vectors, diff);
//   printf("%lf %lf\n", this->vectors[0].x, this->current_vectors[0].x);
   this->update();
}

void glView::SetScaling(double size) {
    this->diff.size = size;
//    this->current_vectors = size_xyz(this->vectors, this->count_vector, Z, Z, Z, this->current_vectors); // масштабирование по z
    this->Shift_Size->setValue(size);
//    this->update();
    this->recalc();
}

void glView::SetShift_Z(double Z) {
//    this->scale=Z;
    this->diff.z_move= Z;
//    this->current_vectors = size_xyz(this->vectors, this->count_vector, Z, Z, Z, this->current_vectors); // масштабирование по z
    this->Shift_Z->setValue(Z);
//    this->update();
    this->recalc();
}

void glView::SetShift_X(double X) {
//    this->move_x=X;
    this->diff.x_move=X;

//    this->current_vectors = move_xyz(this->vectors, this->count_vector, this->move_x, this->move_y, 0, this->current_vectors); // перемещение по x

    this->Shift_X->setValue(this->diff.x_move);
//    this->update();
    this->recalc();
}
void glView::SetShift_Y(double Y){
//    this->move_y=Y;
    this->diff.y_move=Y;
//    this->current_vectors = move_xyz(this->vectors, this->count_vector, this->move_x, this->move_y, 0, this->current_vectors); // перемещение по  y
    this->Shift_Y->setValue(this->diff.y_move);
//     this->update();
    this->recalc();
}

void glView::SetRotate_X(double X) {
//    this->x=X;
    this->diff.x_alpha=X;
//    this->current_vectors = rotation_x(this->vectors, this->count_vector, this->x, this->current_vectors); // поворот по x
    // add spinbox
//    this->update();
      this->recalc();
}

void glView::SetRotate_Y(double Y) {
//    this->y=Y;
        this->diff.y_alpha=Y;
//    this->current_vectors = rotation_y(this->vectors, this->count_vector, this->y, this->current_vectors); // поворот по y
    // add spinbox
//    this->update();
    this->recalc();
}

void glView::SetRotate_Z(double Z) {
    this->diff.z_alpha=Z;
//    this->current_vectors = rotation_z(this->vectors, this->count_vector, Z, this->current_vectors); // поворот по z
//    this->update();
    //add spinbox
    this->recalc();
}

void glView::wheelEvent(QWheelEvent *event) {
    if (event->position().x()>0 && event->position().y()>0)
    {
//        this->scale+=(double)event->angleDelta().y()/speed;
        this->diff.size+=(double)event->angleDelta().y()/speed;
        if (diff.size<0) diff.size=0;
//        this->SetShift_Z(this->scale);
        this->SetScaling(this->diff.size);
    }
}

void glView::mousePressEvent(QMouseEvent *event) {
    this->position_x=event->scenePosition().x();
    this->position_y=event->scenePosition().y();
}

void glView::mouseMoveEvent(QMouseEvent *event){
    if (!shift)
    {
//        this->x=event->position().x()/this->size().height();
        this->diff.x_alpha=event->position().x()/this->size().height();
//        this->y=event->position().y()/this->size().width();
        this->diff.y_alpha=event->position().y()/this->size().width();
//        this->current_vectors = rotation_x(this->vectors, this->count_vector, this->x, this->current_vectors); // поворот по x
//        this->current_vectors = rotation_y(this->vectors, this->count_vector, this->y, this->current_vectors); // поворот по y
    } else {
//        this->move_x+= (event->scenePosition().x() - this->position_x)/speed*scale;
        this->diff.x_move+=(event->scenePosition().x() - this->position_x)/speed*(this->diff.size*0.5);
//        this->move_y+=  (event->scenePosition().y() - this->position_y)/speed*scale;
        this->diff.y_move+= (event->scenePosition().y() - this->position_y)/speed*(this->diff.size*0.5);
//        this->current_vectors = move_xyz(this->vectors, this->count_vector, this->move_x, this->move_y, 0, this->current_vectors); // перемещение по x, y,
        this->position_x=event->scenePosition().x();
        this->position_y=event->scenePosition().y();
        this->Shift_X->setValue(this->diff.x_move);
        this->Shift_Y->setValue(this->diff.y_move);
    }
//    this->update();
    this->recalc();
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
      //команды отрисовки вершин
      glColor3f(this->colorEdges->Red(), this->colorEdges->Blue(), this->colorEdges->Green());
//      glColor3d(1, 1, 0.5);
      glPointSize(this->size_edges);
      glBegin(GL_POINTS);
      for (int i = 0; i < this->count_vector; i++) {
          glVertex3d(this->current_vectors[i].x, this->current_vectors[i].y, this->current_vectors[i].z);
      }
      glEnd();
      //команды отрисовки векторов
      glColor3f(this->colorVertex->Red(), this->colorVertex->Blue(), this->colorVertex->Green());
//      glColor3d(0.5, 0.5, 0.5);
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
