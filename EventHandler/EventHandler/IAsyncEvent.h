#pragma once

class IAsyncEvent
{
public:
	virtual ~IAsyncEvent() = default;

	virtual void executeEvent() = 0;
};