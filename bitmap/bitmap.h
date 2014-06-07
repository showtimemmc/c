#include "bitmap.h"
class bitmap
{
private:
	int mask=0x07;
	int* a;


public:
	bitmap(unsigned long);
	~bitmap();
	
	void clear(unsigned long);
	void set(unsigned long);
	bool contain(unsigned long);
};