#include "UnknownMessage.h"

IMessage::MessageType UnknownMessage::getMessageType() const
{
    return UNKNOWN;
}

void UnknownMessage::setFrom(const std::string& from)
{
    mFrom = from;
}

void UnknownMessage::setTo(const std::string& to)
{
    mTo = to;
}
void UnknownMessage::setBody(const std::string& body)
{
    mBody = body;
}

const std::string& UnknownMessage::getFrom()
{
    return mFrom;
}

const std::string& UnknownMessage::getTo()
{
    return mTo;
}

const std::string& UnknownMessage::getBody()
{
    return mBody;
}

void UnknownMessage::show()
{
    std::cout << "Message from: " << mFrom << std::endl;
    std::cout << "Message to: " << mTo << std::endl;
    std::cout << "Message data: " << mBody << std::endl;
}