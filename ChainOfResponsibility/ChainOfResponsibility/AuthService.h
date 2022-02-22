#pragma once
#include "IService.h"

class AuthService :
    public IService
{
public:
    IService::Primitive handleMessage(IMessage* message);

private:
    std::vector<std::string> users = { "authUser", "oneMoreUser", "user", "admin" };
};