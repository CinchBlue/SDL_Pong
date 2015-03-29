#include "Paddle.h"

Event_Receivable::~Event_Receivable()
{

}

Paddle::~Paddle()
{

}

Paddle::Paddle() : e_rec(this)
{

}


void Paddle::on_notify(Event* e)
{

}

