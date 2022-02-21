#pragma once

class IAsyncEvent
{
public:
	virtual ~IAsyncEvent() = default;

	virtual void executeEvent() = 0;
};

class AddUserAsyncEvent : public IAsyncEvent {
public:
	void executeEvent() override;
};

class ModifyUserAsyncEvent : public IAsyncEvent {
public:
	void executeEvent() override;
};

class RemoveUserAsyncEvent : public IAsyncEvent {
public:
	void executeEvent() override;
};