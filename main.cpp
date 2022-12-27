#include <QCoreApplication>

#include "singleton_signal_controller.h"
#include "receiver.h"
#include "multi_receiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Starting application";
    auto* controller = SingletonSignalController::instance();
    Receiver receiver{};

    controller->broadcast("Hey there!");
    emit receiver.broadcast("Test broadcast from receiver!");

    QList<AbstractSignalController*> controllers{SingletonSignalController::instance()};
    MultiReceiver multireceiver{&a, controllers};
    emit multireceiver.broadcast("Test broadcast from multireceiver!");
    return a.exec();
}
