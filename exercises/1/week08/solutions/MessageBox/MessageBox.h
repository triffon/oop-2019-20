#pragma once
#include <fstream>
using namespace std;

template<typename T>
class MessageBox
{
	T** m_messages;
	int m_size = 0;


	void clean()
	{
		if (m_messages != nullptr)
		{
			for (int i = 0; i < m_size; i++)
			{
				delete m_messages[i];
			}
			delete [] m_messages;
		}
	}

	void copy(const MessageBox &other)
	{
		clean();
		m_size = other.m_size;
		m_messages = new T*[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_messages[i] = new T(*other.m_messages[i]);
		}
	}

public:
	MessageBox()
		:m_messages(nullptr), m_size(0)
	{}

	~MessageBox()
	{
		clean();
	}

	MessageBox(const MessageBox &other)
		:m_messages(nullptr), m_size(0)
	{
		copy(other);
	}

	MessageBox& operator=(const MessageBox &other)
	{
		if (this != &other)
		{
			copy(other);
		}
		return *this;
	}

	void readFrom(const char* address)
	{
		fstream f;
		f.open(address, ios::in | ios::binary);

		f.seekg(0, ios::end);
		
		int raw_size = f.tellg();
		int messages_count = raw_size / sizeof(T);
		
		f.seekg(0, ios::beg);

		T** tmp = m_messages;
		int tmp_size = m_size;

		m_size += messages_count;
		m_messages = new T*[m_size];

		int cnt = 0;
		for (; cnt < tmp_size; cnt++)
		{
			m_messages[cnt] = tmp[cnt];
		}

		delete [] tmp;

		T msg;
		while (f.read((char*)&msg, sizeof(msg)) )
		{
			m_messages[cnt++] = new T(msg);
		}

		f.close();

//		f.open(address, ios::out | ios::trunc);
	//	f.close();


	}


	int size()
	{
		return m_size;
	}


	T& operator[](int i)
	{
		return *m_messages[i];
	}


};
