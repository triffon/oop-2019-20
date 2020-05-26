

class A
{

};

class B : A
{

};

struct C final : B
{

};

class D : B
{

};

class E : C
{

};