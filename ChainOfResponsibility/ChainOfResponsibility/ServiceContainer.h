#pragma once
#include <list>
#include "IMessage.h"
#include "IService.h"
#include "AuthService.h"
#include "GetDataService.h"
#include "UpdateDataService.h"

class ServiceContainer
{
public:

    // Добавляет сервисЫ в контейнер
    void addService(IService* service);

    // Обрабатывает сообщение на контейнере сервисов
    void handleMessage(IMessage* message);

private:

    // переменная-контейнер с указателями на сервисы (используйте подходящий, известный вам STL контейнер)
    std::list<IService*> services;
};