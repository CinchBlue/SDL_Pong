/*
 * Use this as the base for all classes that need to receive events.
 */

#ifndef EVENT_RECEIVABLE_H_
#define EVENT_RECEIVABLE_H_

#include "Common.h"
#include "Event.h"

class Event_Receivable
{
public:
	virtual ~Event_Receivable() = 0;
	virtual void on_notify(Event* e) = 0;

};





#endif /* EVENT_RECEIVABLE_H_ */
