#ifndef CLONEABLE_H
#define CLONEABLE_H

class Clonable { 
public:
	virtual Clonable * clone()=0;
};

#endif /* CLONEABLE_H */
