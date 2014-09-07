#include <QApplication>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQmlApplicationEngine>
#include "gamebgnd.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GameBgnd bgn;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("bgn", &bgn);

    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
