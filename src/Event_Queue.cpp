#include "Event_Queue.h"


void Event_Queue::add_receiver(Event_Receiver* receiver_ptr)
{
	receiver_list.push_back(receiver_ptr);
}

//Returns TRUE on removing receiver
bool Event_Queue::remove_receiver(Event_Receiver* receiver_ptr)
{
	for(std::vector<Event_Receiver*>::iterator it = receiver_list.begin(); it != receiver_list.end(); ++it)
	{
		if(*it == receiver_ptr)
		{
			receiver_list.erase(it);
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}

void Event_Queue::push_event(Event e)
{
	event_queue.push(e);
}

void Event_Queue::poll_input()
{
	Event* input_event = new Event("input", "sdl_input_all");
	input_event->attach_data(input);

	for(std::vector<Event_Receiver*>::iterator it = receiver_list.begin(); it != receiver_list.end(); ++it)
	{
		(*it)->receive_event(input_event);
	}
}
