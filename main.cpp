#include <QCoreApplication>

#include "singleton_signal_controller.h"
#include "receiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Starting application";
    auto* controller = SingletonSignalController::instance();
    Receiver receiver{};

    controller->broadcast("Hey there!");
    emit receiver.broadcast("Test broadcast from receiver!");

    return a.exec();
}
