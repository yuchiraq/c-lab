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

    // ��������� ������� � ���������
    void addService(IService* service);

    // ������������ ��������� �� ���������� ��������
    void handleMessage(IMessage* message);

private:

    // ����������-��������� � ����������� �� ������� (����������� ����������, ��������� ��� STL ���������)
    std::list<IService*> services;
};