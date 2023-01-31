#include "modeiinstance.h"

void ModeIinstance::change_scale(float scale) {
  _scale = scale;
  markDirty();
  update();
}

ModeIinstance::ModeIinstance(ModelView *model) { _model = model; }

ModeIinstance::~ModeIinstance() {}

QColor ModeIinstance::color() const { return _color; }

void ModeIinstance::setColor(const QColor &newColor) {
  if (_color == newColor) return;
  _color = newColor;
  markDirty();
}

void ModeIinstance::change() {
  markDirty();
  update();
}

QByteArray ModeIinstance::getInstanceBuffer(int *instanceCount) {
  QByteArray instanceData;
  for (int i = 0; i < _model->vex.over_mem; ++i) {
    auto entry = calculateTableEntry(
        {_model->vex.arr[i].x, _model->vex.arr[i].y, _model->vex.arr[i].z},
        {_scale, _scale, _scale}, {0, 0, 0}, _color, {});
    instanceData.append(reinterpret_cast<const char *>(&entry), sizeof(entry));
  }
  *instanceCount = _model->vex.over_mem;
  return instanceData;
}
