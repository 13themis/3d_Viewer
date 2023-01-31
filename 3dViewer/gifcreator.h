#ifndef GIFCREATOR_H
#define GIFCREATOR_H
#include <QObject>
#include <QStandardPaths>
#include <QString>

class GifCreator : public QObject {
  Q_OBJECT
 public:
  GifCreator() = default;
  ~GifCreator() = default;
 public slots:
  void set_filename(const QString& _path);
  void create_gif();
  QString image_file_pathmask();

 private:
  QString path;
};

#endif  // GIFCREATOR_H
