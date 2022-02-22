#include "UpdateDataService.h"

IService::Primitive UpdateDataService::handleMessage(IMessage* message)
{

    if (message->getMessageType() == IMessage::UPDATE_DATA)
        return STOP;
    else
        return CONTINUE;
    
}
