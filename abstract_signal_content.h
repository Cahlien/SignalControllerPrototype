#ifndef SIGNALCONTENT_H
#define SIGNALCONTENT_H

#include <QObject>

#include "channels.h"

class AbstractSignalContent
{
public:
    AbstractSignalContent(QObject* sender = nullptr, Channels channel = Channels::General);

    const QObject& sender();
    const QObject& sender(QObject* value);

    const Channels& channel();
    const Channels& channel(Channels value);

private:
    QObject* sender_;
    Channels channel_;
};

#endif // SIGNALCONTENT_H
