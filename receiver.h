#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QVariant>

#include "i_signal_receiver.h"

class Receiver : public QObject, public ISignalReceiver
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = nullptr);
    ~Receiver() = default;

signals:
    void broadcast(QVariant) override;

public slots:
    void receive(QVariant) override;
};

#endif // RECEIVER_H
