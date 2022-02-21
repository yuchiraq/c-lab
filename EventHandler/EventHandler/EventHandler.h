#pragma once
#include "IAsyncEvent.h"
#include <queue>



class EventHandler
{
public:

	///
	/// Add event to queue
	///
	void sceduleEvent(IAsyncEvent *asyncEvent);

	///
	/// Pop from queue
	/// 
	void popEvents();

	///
	/// @return number of sceduled events
	///
	size_t getNumberOfEvents() const;
	
	static EventHandler* GetInstance();

private:

	std::queue<IAsyncEvent*> queue;

	/*		Singleton	 */
	EventHandler() = default;
	EventHandler(EventHandler & other) = delete;

	static EventHandler* singleton;

	void operator = (const EventHandler & second) = delete;
	//
};