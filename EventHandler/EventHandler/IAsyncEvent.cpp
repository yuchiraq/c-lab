#include <iostream>
#include "IAsyncEvent.h"

void AddUserAsyncEvent::executeEvent()
{
	std::cout << "User Added" << std::endl;
}

void ModifyUserAsyncEvent::executeEvent()
{
	std::cout << "User Modified" << std::endl;
}

void RemoveUserAsyncEvent::executeEvent()
{
	std::cout << "User Removed" << std::endl;
}
