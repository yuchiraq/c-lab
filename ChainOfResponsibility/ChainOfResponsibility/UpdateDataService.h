#pragma once
#include "IService.h"

class UpdateDataService :
    public IService
{
public:
    IService::Primitive handleMessage(IMessage* message);
};