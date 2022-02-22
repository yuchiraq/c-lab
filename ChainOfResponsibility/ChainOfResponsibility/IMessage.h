#pragma once
#include <iostream>

class IMessage
{
public:
    // Тип сообщения
    enum MessageType
    {
        GET_DATA,
        UPDATE_DATA
    };

    // Сеттеры
    virtual void setFrom(const std::string& from) = 0;
    virtual void setTo(const std::string& to) = 0;
    virtual void setBody(const std::string& body) = 0;

    // Геттеры
    virtual const std::string& getFrom() = 0;
    virtual const std::string& getTo() = 0;
    virtual const std::string& getBody() = 0;

    // Вывод сообщения в консоль
    virtual void show() = 0;

    // Каждый наследник возвращает свой тип
    virtual MessageType getMessageType() const = 0;

private:
    std::string mFrom;
    std::string mTo;
    std::string mBody;
};