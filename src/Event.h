#ifndef EVENT_H_
#define EVENT_H_

#include "Common.h"
#include "boost/any.hpp"

/*
 * Event is used extensively within the program.
 * It is the basis for all messages in the event system.
 * Objects will send and receive events.
 *
 * It uses boost::any in order to be able to
 * attach any kind of data to be read.
 *
 * Event is meant to be extremely flexible in order to
 * be extensible to many different types of games.
 */
class Event
{
private:
	std::string name;
	std::string type;
	std::vector<boost::any> info;
public:
	Event(std::string name_str, std::string type_str)
	{
		name = name_str;
		type = type_str;
	}

	void set_name(std::string str) {name = str;}
	void set_type(std::string str) {type = str;}
	void attach_data(boost::any data) {info.push_back(data);}

	std::string get_name() {return name;}
	std::string get_type() {return type;}
	boost::any get_info() {return info;}
};


#endif /* EVENT_H_ */
