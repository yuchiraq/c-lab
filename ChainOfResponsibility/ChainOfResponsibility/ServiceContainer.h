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

    // ������������ ��������� �� ���������� ��������
    void handleMessage(IMessage* message);

private:

    // ��������� ������� � ���������
    void addService();

    // ����������-��������� � ����������� �� ������� (����������� ����������, ��������� ��� STL ���������)
    std::map<std::string, IService*> services;
    /*std::pair<std::string, IService*> services = {
        "AuthService", new(AuthService),
        "GetDataService", new(GetDataService),
        "UpdateDataService", new(UpdateDataService)
    };*/
    //std::vector<IService*> services;
};