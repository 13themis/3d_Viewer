#include <QtQuick3D/qquick3d.h>

#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtGui>

#include "gifcreator.h"
#include "gradienttex.h"
#include "modeiinstance.h"
#include "modelview.h"
#include "saveload.h"

int main(int argc, char *argv[]) {
  SaveLoad save_load;
  ModelView models;
  GradientTex texture;
  ModeIinstance instance(&models);
  QGuiApplication app(argc, argv);
  GifCreator gif;
  qmlRegisterType<ModelView>("models", 1, 0, "ModelView");
  qmlRegisterType<GradientTex>("gradientTex", 1, 0, "GradientTex");
  QSurfaceFormat::setDefaultFormat(QQuick3D::idealSurfaceFormat(3));
  QQmlApplicationEngine engine;
  QQmlContext *context = engine.rootContext();
  context->setContextProperty("model_context", &models);
  context->setContextProperty("inst", &instance);
  context->setContextProperty("save_load", &save_load);
  context->setContextProperty("gif_creator", &gif);
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty()) return -1;
  return app.exec();
}
