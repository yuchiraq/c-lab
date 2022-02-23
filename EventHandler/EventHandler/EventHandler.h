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
	/// @return number of sceduled events
	///
	size_t getNumberOfEvents() const;
	
	static EventHandler* GetInstance();

private:

	///
	/// Pop from queue
	/// 
	void popEvents();

	std::queue<IAsyncEvent*> queue;

	/*		Singleton	 */
	EventHandler() = default;
	EventHandler(EventHandler& other) = delete;
	EventHandler(EventHandler&& other) = default;
	EventHandler& operator=(EventHandler&& other) = default;

	static EventHandler* singleton;

	void operator = (const EventHandler & second) = delete;
	//
};