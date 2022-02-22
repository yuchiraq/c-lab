#pragma once
#include <vector>
#include "IMessage.h"

class IService
{
public:

    enum Primitive
    {
        CONTINUE, // ≈сли сервис вернул CONTINUE - управление передаЄтс€ следующему сервису
        STOP,     // ≈сли сервис вернул STOP - выведите сообщение в лог и завершите обработку
        FAIL      // ≈сли сервис вернул FAIL - выведите сообщение в лог и завершите обработку
    };

    // “очка входа в сервис дл€ обработки сообщени€
    virtual Primitive handleMessage(IMessage* message) = 0;
};