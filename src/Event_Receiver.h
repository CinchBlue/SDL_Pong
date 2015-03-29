#ifndef EVENT_RECEIVER_H_
#define EVENT_RECEIVER_H_

#include "Common.h"
#include "Event.h"
#include "Event_Receivable.h"

class Event_Receiver
{
public:
	Event_Receiver(Event_Receivable* owner_obj);
	~Event_Receiver();

	void receive_event(Event* e);
	void notify_owner(Event* e);
	void set_owner(Event_Receivable* owner_obj) {owner = owner_obj;}

	Event_Receivable* get_owner_obj() {return owner;}

private:
	Event_Receivable* owner;

};

#endif /* EVENT_RECEIVER_H_ */
