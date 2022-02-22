#pragma once
#include <vector>
#include "IMessage.h"

class IService
{
public:

    enum Primitive
    {
        CONTINUE, // ���� ������ ������ CONTINUE - ���������� ��������� ���������� �������
        STOP,     // ���� ������ ������ STOP - �������� ��������� � ��� � ��������� ���������
        FAIL      // ���� ������ ������ FAIL - �������� ��������� � ��� � ��������� ���������
    };

    // ����� ����� � ������ ��� ��������� ���������
    virtual Primitive handleMessage(IMessage* message) = 0;
};