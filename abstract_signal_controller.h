#ifndef ABSTRACTSIGNALCONTROLLER_H
#define ABSTRACTSIGNALCONTROLLER_H

#include <QFunctionPointer>

#include <QObject>
#include <QMap>
#include <QVariant>

#include "channels.h"

class AbstractSignalController : public QObject
{
    Q_OBJECT
public:
    virtual ~AbstractSignalController() = 0;

    virtual quint64 broadcast(QVariant);
    virtual bool subscribe(QObject* = nullptr, Channels = Channels::General, std::function<void(QVariant)> = nullptr);
    virtual bool unsubscribe(QObject* = nullptr, Channels = Channels::General, std::function<void(QVariant)> = nullptr);

signals:
    void general(QVariant data);

protected:
    explicit AbstractSignalController(QObject *parent = nullptr);

    QMap<Channels, QList<QObject*>> subscriptions;
    QMap<Channels, void(AbstractSignalController::*)(QVariant)> channels;

private:

};

#endif // ABSTRACTSIGNALCONTROLLER_H
