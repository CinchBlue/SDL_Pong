#ifndef EVENT_QUEUE_H_
#define EVENT_QUEUE_H_

#include "Common.h"
#include "Event.h"
#include "Event_Receiver.h"
#include "Event_Receivable.h"

class Event_Queue
{
private:

	SDL_Event input;

	std::queue<Event> event_queue;
	std::vector<Event_Receiver*> receiver_list;
public:
	void add_receiver(Event_Receiver* receiver_ptr);
	bool remove_receiver(Event_Receiver* receiver_ptr);

	void push_event(Event e);

	void poll_input();
	void poll_event();

};


#endif /* EVENT_QUEUE_H_ */
