#include "app/CompositionRoot.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QUrl>

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    app::CompositionRoot compositionRoot;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("machineListViewModel", compositionRoot.machineListViewModel());

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        [] {
            QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.load(QUrl(QStringLiteral("qrc:/ModernQtArchitecture/qml/Main.qml")));

    return app.exec();
}
