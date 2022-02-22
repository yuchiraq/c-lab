#include "AuthService.h"

IService::Primitive AuthService::handleMessage(IMessage* message)
{

    auto it = find(users.begin(), users.end(), message->getFrom());

    if (it == users.end())
        return FAIL;
    else
        return CONTINUE;

}