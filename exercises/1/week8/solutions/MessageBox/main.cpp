#include <iostream>
#include <fstream>
#include "Message.h"
#include "MessageSender.h"
#include "MessageBox.h"
using namespace std;

int main()
{
	Message m1(1, "Message1");
	Message m2(2, "Message2");

	MessageSender<Message> ms;
	ms.setMessage(m1);
	ms.sendMessage("address.bin");

	ms.setMessage(m2);
	ms.sendMessage("address.bin");
	MessageBox<Message> mb;
	mb.readFrom("address.bin");

	MessageBox<Message> mb2 = mb;


	for (size_t i = 0; i < mb2.size(); i++)
	{
		cout << mb2[i].payload << endl;
	}
	
	return 0;
}
