#include "GetDataMessage.h"

IMessage::MessageType GetDataMessage::getMessageType() const
{
    return GET_DATA;
}

void GetDataMessage::setFrom(const std::string& from)
{
    mFrom = from;
}

void GetDataMessage::setTo(const std::string& to)
{
    mTo = to;
}
void GetDataMessage::setBody(const std::string& body)
{
    mBody = body;
}

const std::string& GetDataMessage::getFrom()
{
    return mFrom;
}

const std::string& GetDataMessage::getTo()
{
    return mTo;
}

const std::string& GetDataMessage::getBody()
{
    return mBody;
}

void GetDataMessage::show()
{
    std::cout << "Message from: " << mFrom << std::endl;
    std::cout << "Message to: " << mTo << std::endl;
    std::cout << "Message data: " << mBody << std::endl;
}