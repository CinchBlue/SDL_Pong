#ifndef PADDLE_H_
#define PADDLE_H_

#include "Common.h"
#include "Event_Receivable.h"
#include "Event_Receiver.h"
#include "Event_Sender.h"

class Paddle : public Event_Receivable
{
public:
	Paddle();
	~Paddle();

	virtual void on_notify(Event* e);

	Event_Receiver e_rec;


};





#endif /* PADDLE_H_ */
