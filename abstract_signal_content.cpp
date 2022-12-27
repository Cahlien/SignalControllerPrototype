#include "abstract_signal_content.h"

AbstractSignalContent::AbstractSignalContent(QObject* sender, Channels channel)
    : channel_{channel}
{

}

const QObject &AbstractSignalContent::sender()
{
    return *this->sender_;
}

const QObject &AbstractSignalContent::sender(QObject* value)
{
    this->sender_ = value;
    return *this->sender_;
}

const Channels& AbstractSignalContent::channel()
{
    return this->channel_;
}

const Channels& AbstractSignalContent::channel(const Channels value)
{
    this->channel_ = value;
    return this->channel_;
}
