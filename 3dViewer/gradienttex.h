#ifndef GRADIENTTEX_H
#define GRADIENTTEX_H
#include <QColor>
#include <QQuick3DTextureData>

class GradientTex : public QQuick3DTextureData {
 public:
  Q_OBJECT
  QML_NAMED_ELEMENT(gradientTex);

 public:
  GradientTex();
  ~GradientTex();
 public slots:
  void setProperty(QColor color1, QColor color2);
  void setDashed();
  void setSolid();

 private:
  int flag_dashed;
  QColor _color1;
  QColor _color2;
  void regenerateTextureData();
  QColor linearInterpolate(const QColor &color1, const QColor &color2,
                           float value);
};

#endif  // GRADIENTTEX_H
