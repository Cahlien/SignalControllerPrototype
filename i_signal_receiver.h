#ifndef ISIGNALRECEIVER_H
#define ISIGNALRECEIVER_H

#include <QDebug>
#include <QObject>
#include <QVariant>

#include "abstract_signal_controller.h"

class ISignalReceiver
{
public:
    ISignalReceiver(QObject* receiver, AbstractSignalController* controller);
    ISignalReceiver(QObject* receiver, QList<AbstractSignalController*> controllers);
    virtual ~ISignalReceiver() = default;

    virtual void broadcast(QVariant data) = 0;
    virtual void receive(QVariant data) = 0;
};

#endif // ISIGNALRECEIVER_H
