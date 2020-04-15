#pragma once
#include <fstream>
using namespace std;

template<typename T>
class MessageSender
{
	T m_message;
public:
	void setMessage(T &message) {
		m_message = message;
	}

	void sendMessage(const char *address)
	{
		fstream f;
		f.open(address, ios::binary | ios::out | ios::app);
		f.write((char*)&m_message, sizeof(m_message));
		f.close();
	}
};