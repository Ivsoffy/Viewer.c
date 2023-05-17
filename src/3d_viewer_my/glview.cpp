#include "glview.h"
#include <QTimer>
#include "gif.h"

#define GL_SILENCE_DEPRECATION

glView::glView(QWidget*parent):QOpenGLWidget(parent) {
    this->colorBackground.push_back(ColorPallette("Saphire", 0, 1, 0, 0));
    this->colorBackground.push_back(ColorPallette("White", 255, 255, 255, 0));
    this->colorBackground.push_back(ColorPallette("Black", 0, 0, 0, 0));

    this->colorVertex = new ColorPallette("Standart", 0.5, 0.5, 0.5, 0);
    this->colorEdges = new ColorPallette("Standart", 1, 0.5, 1, 0);
    currentBackground = new ColorPallette();
    this->shift=0;
    this->filename= "";
    this->speed = 120;
    this->size_edges = 5;
    this->size_vertex = 0.5;
    this->count_vector = 0, this->count_surface = 0;
    pointType=0;
    VertexType=0;
    ProjectionType = 0;
    setMetrics();
}

void glView::initializeGL() {
//  glMatrixMode(GL_PROJECTION);
//  glLoadIdentity();
//  glOrtho(-4, 4, 4, -4, -100, 100);
    this->UpdateProjection(0);
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
         this->filename=filename;
         setMetrics();
     }
}

void glView::recalc() {
   recalculation(this->vectors, this->count_vector, this->current_vectors, diff);
   this->update();
}

void glView::SetScaling(double size) {
    this->diff.size = size;
    this->Shift_Size->setValue(size);
    this->recalc();
}

void glView::SetShift_Z(double Z) {
    this->diff.z_move= Z;
    this->Shift_Z->setValue(Z);
    this->recalc();
}

void glView::SetShift_X(double X) {
    this->diff.x_move=X;
    this->Shift_X->setValue(this->diff.x_move);
    this->recalc();
}
void glView::SetShift_Y(double Y){
    this->diff.y_move=Y;
    this->Shift_Y->setValue(this->diff.y_move);
    this->recalc();
}

void glView::SetRotate_X(double X) {
    this->diff.x_alpha=X;
    // add spinbox
      this->recalc();
}

void glView::SetRotate_Y(double Y) {
    this->diff.y_alpha=Y;
    // add spinbox
    this->recalc();
}

void glView::SetRotate_Z(double Z) {
    this->diff.z_alpha=Z;
    //add spinbox
    this->recalc();
}

void glView::wheelEvent(QWheelEvent *event) {
    if (event->position().x()>0 && event->position().y()>0)
    {
        this->diff.size+=(double)event->angleDelta().y()/speed;
        if (diff.size<0) diff.size=0;
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
        this->diff.x_alpha=event->position().x()/this->size().height();
        this->diff.y_alpha=event->position().y()/this->size().width();
    } else {
        this->diff.x_move+=(event->scenePosition().x() - this->position_x)/speed*(this->diff.size*0.5);
        this->diff.y_move+= (event->scenePosition().y() - this->position_y)/speed*(this->diff.size*0.5);
        this->position_x=event->scenePosition().x();
        this->position_y=event->scenePosition().y();
        this->Shift_X->setValue(this->diff.x_move);
        this->Shift_Y->setValue(this->diff.y_move);
    }
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

void glView::TakePic() {
     QImage e = this->grabFramebuffer();
     this->Time->setValue(this->Time->value()+1);
     e = e.scaled( 640, 480, Qt::IgnoreAspectRatio);
    frames.push_back(e);
       if (frames.size()==30)
       {
       timer->stop();
       SaveGif();
       }
}


void glView::TakeGif(QString file){
    this->Time->setValue(0);
    this->fileGIF=file;
    timer = new QTimer();
    timer->setInterval(100);
    // connect
    connect(timer, SIGNAL(timeout()), this, SLOT(TakePic()));
    timer->start(100);
}

void glView::SaveGif() {
    int width = 640;
    int height = 480;
    uint32_t delay = 60 / 10; // fps
    GifWriter writer;
        GifBegin(&writer, fileGIF.toStdString().c_str(), width, height, delay, 8, true);
        for (int i =0; i< 30; i++) {
                     GifWriteFrame(&writer, frames[i].convertToFormat(QImage::Format_Indexed8).
                                   convertToFormat(QImage::Format_RGBA8888).constBits(), width, height, delay, 8, true);
        }
        GifEnd(&writer);
        frames.clear();
}

void glView::UpdateProjection(int index) { // do not work
   this->ProjectionType = index;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     if ( this->ProjectionType==1)
     {
         glFrustum(-1, 1, 1, -1, 1, 1);
     }
     else
     {
         glOrtho(-4, 4, 4, -4, -100, 100);
     }
     glMatrixMode(GL_MODELVIEW);
    this->update();
}

void glView::paintGL() {
    if (this->count_vector)
  {

        if (this->pointType==0)
      glEnable(GL_POINT_SMOOTH);
        else glDisable(GL_POINT_SMOOTH);
      glClearColor(this->currentBackground->Red(), this->currentBackground->Green(), this->currentBackground->Blue(), this->currentBackground->Alpha());
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      //команды отрисовки векторов

      glColor3f(this->colorVertex->Red(), this->colorVertex->Green(), this->colorVertex->Blue());
      glLineWidth(this->size_vertex);
      glEnable(GL_LINE_STIPPLE);
      if (VertexType)
      glLineStipple(2,10);
      for (int i = 0; i < this->count_surface; i++) {
          glBegin(GL_LINE_LOOP);
          for (int j = 0; j < surface[i].number_dot_surface; j++) {
              int index = surface[i].v[j] - 1;
              glVertex3d(this->current_vectors[index].x, this->current_vectors[index].y, this->current_vectors[index].z);
          }
          glEnd();
      }

      //команды отрисовки вершин

      if (this->pointType!=2)
      {
          glColor3f(this->colorEdges->Red(), this->colorEdges->Green(), this->colorEdges->Blue());
          glPointSize(this->size_edges);

          glBegin(GL_POINTS);
          for (int i = 0; i < this->count_vector; i++) {
              glVertex3d(this->current_vectors[i].x, this->current_vectors[i].y, this->current_vectors[i].z);
          }
          glEnd();
      }

  }
}
