#pragma once
#include "IAsyncEvent.h"

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

