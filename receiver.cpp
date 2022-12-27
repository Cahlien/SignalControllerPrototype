#include "receiver.h"

#include "singleton_signal_controller.h"

#include <QDebug>

Receiver::Receiver(QObject *parent)
    : QObject{parent}
    , ISignalReceiver{this, SingletonSignalController::instance()}
{
    QObject::connect(this, &Receiver::broadcast, SingletonSignalController::instance(), &AbstractSignalController::broadcast);
}

void Receiver::receive(QVariant data)
{
    qDebug() << "Received" << data;
}

