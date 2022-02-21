#include "EventHandler.h"
#include "IAsyncEvent.h"
#include <queue>
#include <iostream>

EventHandler* EventHandler::singleton = nullptr;

void EventHandler::sceduleEvent(IAsyncEvent* asyncEvent)
{
    queue.push(asyncEvent);
    if (getNumberOfEvents() == 5) {
        std::cout << "\t\tNew iteration" << std::endl;
        for (int i = 0; i < 5; i++) {
            queue.front()->executeEvent();
            queue.pop();
        }
    }
}

size_t EventHandler::getNumberOfEvents() const
{
    return queue.size();
}

EventHandler* EventHandler::GetInstance()
{
    if (singleton == nullptr) {
        singleton = new EventHandler();
    }
    return singleton;
}

