#include <iostream>
#include "EventHandler.h"
#include "IAsyncEvent.h"


int main() {
	int key;
	IAsyncEvent *event = nullptr;
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		key = rand() % 3 + 1;
		switch (key)
		{
		case 1:
			event = new(AddUserAsyncEvent);
			break;
		case 2:
			event = new(ModifyUserAsyncEvent);
			break;
		case 3:
			event = new(RemoveUserAsyncEvent);
			break;
		}
		EventHandler::GetInstance()->sceduleEvent(event);
	}

	return 1;
}