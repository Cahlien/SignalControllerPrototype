#ifndef MULTIRECEIVER_H
#define MULTIRECEIVER_H

#include <QObject>

#include "i_signal_receiver.h"

class MultiReceiver : public QObject, public ISignalReceiver
{
    Q_OBJECT
public:
    explicit MultiReceiver(QObject *parent = nullptr, QList<AbstractSignalController*> controllers = QList<AbstractSignalController*>{});

signals:
    void broadcast(QVariant data) override;

public slots:
    void receive(QVariant data) override;

private:
    QList<AbstractSignalController*> controllers_;
};

#endif // MULTIRECEIVER_H
