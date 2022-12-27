#include "multi_receiver.h"

MultiReceiver::MultiReceiver(QObject *parent, QList<AbstractSignalController*> controllers)
    : QObject{parent}
    , ISignalReceiver{this, controllers}
    , controllers_{controllers}
{
    for(const auto& controller : controllers)
    {
        QObject::connect(this, &MultiReceiver::broadcast, controller, &AbstractSignalController::broadcast);
    }
}

void MultiReceiver::receive(QVariant data)
{
    qDebug() << "Received" << data;
}
