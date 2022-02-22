#include "UpdateDataMessage.h"

IMessage::MessageType UpdateDataMessage::getMessageType() const
{
    return UPDATE_DATA;
}

void UpdateDataMessage::setFrom(const std::string& from)
{
    mFrom = from;
}

void UpdateDataMessage::setTo(const std::string& to)
{
    mTo = to;
}
void UpdateDataMessage::setBody(const std::string& body)
{
    mBody = body;
}

const std::string& UpdateDataMessage::getFrom()
{
    return mFrom;
}

const std::string& UpdateDataMessage::getTo()
{
    return mTo;
}

const std::string& UpdateDataMessage::getBody()
{
    return mBody;
}

void UpdateDataMessage::show()
{
    std::cout << "Message from: " << mFrom << std::endl;
    std::cout << "Message to: " << mTo << std::endl;
    std::cout << "Message data: " << mBody << std::endl;
}