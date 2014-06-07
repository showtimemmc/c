#include "bitmap.h"
#include "iostream"
class bitmap
{
public:
	bitmap(unsigned long N)
	{
		//new 分配失败会抛异常，不需要检查返回是否为null
		a = new int[N/32+1];
	}
	~bitmap();
	void set(unsigned long input)
	{
		a[input>>5] |= 1<<(input&mask) ;
	}
	void clear(unsigned long input)
	{
		a[input>>5] &= 1<<(input&mask);
	}
	bool contain(unsigned long input)
	{
		if (a[input>>5]&(1<<(input&mask))
		{
			return true;
		}
		return false;
	}
	
};