#ifndef MODELVIEW_H
#define MODELVIEW_H

#include <QtQuick3D/QQuick3DGeometry>

#include "../affine_transfomation_.h"
#include "../parser_.h"

class ModelView : public QQuick3DGeometry {
  Q_OBJECT
  QML_NAMED_ELEMENT(modelView);

 public:
  ModelView();
  ModelView(int a);
  ~ModelView();
  long num_of_vertex;
  long num_of_faces;
  QString path;
  DynamicArrayVex vex;

 private:
  float rotate_x = 0.0;
  float rotate_y = 0.0;
  float rotate_z = 0.0;
  float translation_x = 0.0;
  float translation_y = 0.0;
  float translation_z = 0.0;
  float scale_x = 0.0;
  float scale_y = 0.0;
  float scale_z = 0.0;
  int lineTypeFlag = 0;
  DynamicArrayTrg trg;
  DynamicArrayLine line;
  void updateGeometry();
 public slots:
  void translation(float x, float y, float z);
  void rotation(float x, float y, float z);
  void scaling(float x, float y, float z);
  void loadFile(QString _path);
  long get_num_of_vertexe();
  long get_num_of_faces();
  void set_solid();
  void set_dodet();
  void set_lines();
  void set_textur();
};

#endif  // MODELVIEW_H
