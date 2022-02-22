#pragma once
#include <map>
#include "IMessage.h"
#include "IService.h"
#include "AuthService.h"
#include "GetDataService.h"
#include "UpdateDataService.h"

class ServiceContainer
{
public:

    ServiceContainer();

    // Обрабатывает сообщение на контейнере сервисов
    void handleMessage(IMessage* message);

private:

    // Добавляет сервисЫ в контейнер
    void addService();

    // переменная-контейнер с указателями на сервисы (используйте подходящий, известный вам STL контейнер)
    std::map<std::string, IService*> services;
    /*std::pair<std::string, IService*> services = {
        "AuthService", new(AuthService),
        "GetDataService", new(GetDataService),
        "UpdateDataService", new(UpdateDataService)
    };*/
    //std::vector<IService*> services;
};