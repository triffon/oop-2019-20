
#define deprecate __declspec(deprecated)

#define deprecateWithMessage(msg) __declspec(deprecated(msg))


deprecate
void foo()
{
	// do something
}

struct deprecate X
{
	void f()
	{
	}
};

struct deprecateWithMessage(" X2 is deprecated **") X2
{
	void f()
	{
	}
};


int main()
{
	foo();
	X x;   // C4996
	X2 x2;   // C4996

	return 0;
}