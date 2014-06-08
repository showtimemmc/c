
#include <iostream>

class bitmap
{

private:
	int* _a;
	unsigned long _size;//size of int array

public:
	static const int _mask;//
	bitmap(unsigned long);
	~bitmap();
	
	void clear(unsigned long);
	void set(unsigned long);
	bool contain(unsigned long);
};

