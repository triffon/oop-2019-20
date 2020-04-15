#pragma once
#include <cstring>

struct Message {
	int id;
	char payload[100];

	Message(int _id = 0, const char * _payload ="No payload"):id(_id)
	{
		strcpy(payload, _payload);
	}

	Message(const Message & other)
	{
		id = other.id;
		strcpy(payload, other.payload);
	}

	Message& operator=(const Message & other)
	{
		if (this != &other)
		{
			id = other.id;
			strcpy(payload, other.payload);
		}

		return *this;
	}

};
