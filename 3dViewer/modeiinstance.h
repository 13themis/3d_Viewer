#ifndef MODEIINSTANCE_H
#define MODEIINSTANCE_H

#include <QQuick3DInstancing>

#include "modelview.h"

class ModeIinstance : public QQuick3DInstancing {
  Q_OBJECT
  QML_NAMED_ELEMENT(modelInstance);

 public:
  ModeIinstance(ModelView* model);
  ~ModeIinstance();
  QColor color() const;
 public slots:
  void change();
  void change_scale(float scale);
  void setColor(const QColor& newColor);

 private:
  DynamicArrayVex* _vex;
  ModelView* _model;
  QColor _color;
  float _scale;

 protected:
  QByteArray getInstanceBuffer(int* instanceCount);
};

#endif  // MODEIINSTANCE_H
