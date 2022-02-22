#pragma once
#include "IMessage.h"

class UnknownMessage :
    public IMessage
{
public:

    // �������
    void setFrom(const std::string& from);
    void setTo(const std::string& to);
    void setBody(const std::string& body);

    // �������
    const std::string& getFrom();
    const std::string& getTo();
    const std::string& getBody();

    // ����� ��������� � �������
    void show();

    // ������ ��������� ���������� ���� ���
    IMessage::MessageType getMessageType() const;

private:
    std::string mFrom;
    std::string mTo;
    std::string mBody;
};

