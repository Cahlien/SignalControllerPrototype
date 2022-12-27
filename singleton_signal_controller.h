#ifndef SINGLETONSIGNALCONTROLLER_H
#define SINGLETONSIGNALCONTROLLER_H

#include <QObject>

#include "abstract_signal_controller.h"

class SingletonSignalController final : public AbstractSignalController
{
    Q_OBJECT
public:
    ~SingletonSignalController() override = default;

    static SingletonSignalController* instance();

private:
    explicit SingletonSignalController(QObject* parent = nullptr);
};

#endif // SINGLETONSIGNALCONTROLLER_H
