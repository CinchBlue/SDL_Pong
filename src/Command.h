#ifndef COMMAND_H_
#define COMMAND_H_

//This is the functor that will be used as the template for all action in Pong.
class Command
{
	virtual ~Command();
	virtual void operator() = 0;
};


#endif /* COMMAND_H_ */
