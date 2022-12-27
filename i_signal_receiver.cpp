#include "i_signal_receiver.h"

ISignalReceiver::ISignalReceiver(QObject* receiver, AbstractSignalController* controller)
{

        qDebug() << "Controller:" << controller;
        controller->subscribe(receiver, Channels::General, [&](QVariant data){ this->receive(data);});
}

ISignalReceiver::ISignalReceiver(QObject *receiver, QList<AbstractSignalController *> controllers)
{
    for(const auto& controller : controllers)
    {
        qDebug() << "Controller:" << controller;
        controller->subscribe(receiver, Channels::General, [&](QVariant data){ this->receive(data);});
    }
}
