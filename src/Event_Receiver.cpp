#include "Event_Receiver.h"

Event_Receiver::~Event_Receiver()
{

}

Event_Receiver::Event_Receiver(Event_Receivable* owner_class)
{
	owner = owner_class;
}

void Event_Receiver::receive_event(Event* e)
{
	std::cout << "Event received!" << std::endl;
	notify_owner(e);
}

void Event_Receiver::notify_owner(Event* e)
{
	owner->on_notify(e);
}

