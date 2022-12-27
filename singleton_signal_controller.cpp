#include "singleton_signal_controller.h"

SingletonSignalController* SingletonSignalController::instance()
{
    static SingletonSignalController controller{};
    return &controller;
}

SingletonSignalController::SingletonSignalController(QObject* parent)
    : AbstractSignalController{parent}
{

}
