/*
 * Event_Sender.h
 *
 *  Created on: Jan 25, 2015
 *      Author: Austin
 */

#ifndef EVENT_SENDER_H_
#define EVENT_SENDER_H_

#include "Event.h"
#include "Event_Queue.h"

class Event_Sender
{
public:
	void send_event(Event e);
	void send_event(Event e, Event_Queue q);

	void set_event_queue(Event_Queue e_queue) {event_queue = &e_queue;}

	Event_Queue* get_event_queue() {return event_queue;}

private:
	Event_Queue* event_queue;
};





#endif /* EVENT_SENDER_H_ */
