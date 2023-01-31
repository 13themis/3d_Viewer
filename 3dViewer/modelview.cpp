#include "modelview.h"

#include <QVector3D>
#include <algorithm>
ModelView::ModelView() {
  int status = 0;
  init_v(&vex);
  init_t(&trg);
  init_line(&line);
  if (!status) {
    num_of_faces = trg.over_mem;
    num_of_vertex = vex.over_mem;
    updateGeometry();
  }
}

ModelView::ModelView(int a) {
  lineTypeFlag = 4;
  int status = 0;
  init_v(&vex);
  init_t(&trg);
  init_line(&line);

  if (!status) {
    num_of_faces = trg.over_mem;
    num_of_vertex = vex.over_mem;
    updateGeometry();
  }
}

ModelView::~ModelView() {}

long ModelView::get_num_of_vertexe() {
  updateGeometry();
  return this->num_of_vertex;
}

long ModelView::get_num_of_faces() {
  updateGeometry();
  return this->num_of_faces;
}

void ModelView::set_solid() {
  if (lineTypeFlag == 1) {
    lineTypeFlag = 0;
  } else if (lineTypeFlag == 3) {
    lineTypeFlag = 2;
  }
  updateGeometry();
  update();
}

void ModelView::set_dodet() {
  if (lineTypeFlag == 0) {
    lineTypeFlag = 1;
  } else if (lineTypeFlag == 2) {
    lineTypeFlag = 3;
  }
  updateGeometry();
  update();
}

void ModelView::set_lines() {
  if (lineTypeFlag == 3) {
    lineTypeFlag = 1;
  } else if (lineTypeFlag == 2) {
    lineTypeFlag = 0;
  }
  updateGeometry();
  update();
}

void ModelView::set_textur() {
  if (lineTypeFlag == 1) {
    lineTypeFlag = 3;
  } else if (lineTypeFlag == 0) {
    lineTypeFlag = 2;
  }
  updateGeometry();
  update();
}

void ModelView::updateGeometry() {
  this->clear();
  QByteArray v;
  QByteArray t;
  if (lineTypeFlag == 0) {
    setPrimitiveType(QQuick3DGeometry::PrimitiveType::Lines);
    t.resize(line.over_mem * sizeof(Line));
    memcpy(t.data(), line.arr, line.over_mem * sizeof(Line));
  } else if (lineTypeFlag == 1) {
    setPrimitiveType(QQuick3DGeometry::PrimitiveType::Points);
    t.resize(line.over_mem * sizeof(Line));
    memcpy(t.data(), line.arr, line.over_mem * sizeof(Line));
  } else if (lineTypeFlag == 2) {
    setPrimitiveType(QQuick3DGeometry::PrimitiveType::Triangles);
    t.resize(trg.over_mem * sizeof(Triangle));
    memcpy(t.data(), trg.arr, trg.over_mem * sizeof(Triangle));
  } else if (lineTypeFlag == 4) {
    setPrimitiveType(QQuick3DGeometry::PrimitiveType::Points);
  }
  v.resize(vex.over_mem * sizeof(Vertex));
  setStride(sizeof(Vertex));
  memcpy(v.data(), vex.arr, vex.over_mem * sizeof(Vertex));
  setVertexData(v);
  setIndexData(t);
  QVector3D boundsMin, boundsMax;
  for (size_t i = 0; i < vex.over_mem; ++i) {
    boundsMin[0] = (std::min(vex.arr[i].x, boundsMin[0]));
    boundsMin[1] = (std::min(vex.arr[i].y, boundsMin[1]));
    boundsMin[2] = (std::min(vex.arr[i].z, boundsMin[2]));
    boundsMax[0] = (std::max(vex.arr[i].x, boundsMin[0]));
    boundsMax[1] = (std::max(vex.arr[i].y, boundsMin[1]));
    boundsMax[2] = (std::max(vex.arr[i].z, boundsMin[2]));
  }
  setBounds(boundsMin, boundsMax);
  addAttribute(QQuick3DGeometry::Attribute::PositionSemantic, 0,
               QQuick3DGeometry::Attribute::F32Type);
  addAttribute(QQuick3DGeometry::Attribute::IndexSemantic, 0,
               QQuick3DGeometry::Attribute::U32Type);
  addAttribute(Attribute::NormalSemantic, 0, Attribute::F32Type);
  addAttribute(QQuick3DGeometry::Attribute::TexCoord0Semantic,
               3 * sizeof(float), QQuick3DGeometry::Attribute::F32Type);
}

void ModelView::translation(float x, float y, float z) {
  ::translation(&vex, (x - translation_x) * 0.1, (y - translation_y) * 0.1,
                (z - translation_z) * 0.1);
  translation_x = x;
  translation_y = y;
  translation_z = z;
  updateGeometry();
  update();
}

void ModelView::rotation(float x, float y, float z) {
  ::rotation(&vex, (x - rotate_x) * 0.017, (y - rotate_y) * 0.017,
             (z - rotate_z) * 0.017);
  rotate_x = x;
  rotate_y = y;
  rotate_z = z;
  updateGeometry();
  update();
}

void ModelView::scaling(float x, float y, float z) {
  ::scaling(&vex, pow(1.1, x - scale_x), pow(1.1, y - scale_y),
            pow(1.1, z - scale_z));
  scale_x = x;
  scale_y = y;
  scale_z = z;
  updateGeometry();
  update();
}

void ModelView::loadFile(QString _path) {
  int status = 0;
  vex.over_mem = 0;
  trg.over_mem = 0;
  line.over_mem = 0;
  path = _path;
  path = path.remove(0, 7);
  status = parser(path.toStdString().c_str(), &vex, &trg, &line);
  if (!status) {
    num_of_faces = trg.over_mem;
    num_of_vertex = vex.over_mem;
    updateGeometry();
    update();
  }
}
