#include "GetDataService.h"

IService::Primitive GetDataService::handleMessage(IMessage* message)
{

    if (message->getMessageType() == IMessage::GET_DATA)
        return STOP;
    else
        return CONTINUE;
    return CONTINUE;

}
