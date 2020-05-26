

namespace A
{
	namespace B
	{
		// ...
	}
}


namespace N
{
	class Class
	{
		// ...
	};
}


class Obj
{
	class ObjSubClass
	{
		// ...
	};
};


// Example from Peter Milev
class MyClass
{
private:
	unsigned int count = 0;


public:
	void f1() { }
	void f2(int, int) { }
public:
	class Ptr
	{
	private:
		MyClass* s;
	public:
		Ptr(): s( nullptr )
		{
		}
		Ptr( MyClass* s ): s( s )
		{
			++s->count;
		}
		Ptr( const Ptr& p ): s( p.s )
		{
			++s->count;
		}
		~Ptr()
		{
			if ( !is_null() && --s->count == 0 ) delete s;
		}

		Ptr& operator= ( const Ptr& p )
		{
			MyClass* const old = s;
			s = p.s;
			++s->count;
			if ( --old->count == 0 ) delete old;
			return *this;
		}

		MyClass* operator-> () const
		{
			return s;
		}
		MyClass& operator* ()
		{
			return *s;
		}

		bool is_null() const
		{
			return s == nullptr;
		}
	};
};