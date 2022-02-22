#pragma once
#include "IService.h"

class GetDataService :
    public IService
{
public:
    IService::Primitive handleMessage(IMessage* message);
};