#include "abstract_signal_controller.h"

#include <QDebug>

AbstractSignalController::AbstractSignalController(QObject *parent)
    : QObject{parent}
    , subscriptions{}
    , channels{}
{
    channels[Channels::General] = &AbstractSignalController::general;
}

AbstractSignalController::~AbstractSignalController()
{

}

quint64 AbstractSignalController::broadcast(QVariant data)
{
    emit general(data);
    return this->subscriptions[Channels::General].count();
}

bool AbstractSignalController::subscribe(QObject* subscriber, Channels channel, std::function<void(QVariant)> handler)
{
    bool result{};

    try
    {
        this->subscriptions[channel].append(subscriber);
        this->connect(this, this->channels[channel], subscriber, handler);
        result = true;
    }
    catch (...)
    {
        qDebug() << "Failure: unable to subscribe" << subscriber << "to" << channels[channel];
    }

    for(auto& subscriber : subscriptions[Channels::General])
    {
        qDebug() << subscriber;

    }
    return result;
}

bool AbstractSignalController::unsubscribe(QObject* subscriber, Channels channel, std::function<void(QVariant)> handler)
{
    bool result{};

    try
    {
        this->subscriptions[channel].removeAll(subscriber);
    }
    catch(...)
    {
        qDebug() << "Failure: unable to unsubscribe" << subscriber << "from" << channels[channel];
    }

    return result;
}
