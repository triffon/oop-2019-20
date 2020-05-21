#pragma once
class Singleton
{
private:

	static Singleton * _instance;
	int _data;

	Singleton();
	Singleton(const Singleton& other) = delete;
	const Singleton& operator=(const Singleton& other) = delete;
	
public:

	static Singleton* getInstance();

	void setData(int data);

	int getData();

	~Singleton();

	static void destroy();

	static void print();
};

