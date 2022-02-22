#pragma once
#include "IMessage.h"

class UnknownMessage :
    public IMessage
{
public:

    // Сеттеры
    void setFrom(const std::string& from);
    void setTo(const std::string& to);
    void setBody(const std::string& body);

    // Геттеры
    const std::string& getFrom();
    const std::string& getTo();
    const std::string& getBody();

    // Вывод сообщения в консоль
    void show();

    // Каждый наследник возвращает свой тип
    IMessage::MessageType getMessageType() const;

private:
    std::string mFrom;
    std::string mTo;
    std::string mBody;
};

