#include "bitmap.h"
const int bitmap::_mask=0x1f;

	//max is the max value of the data
	bitmap::bitmap(unsigned long max)
	{
		_size=max/32+1;
		//new 分配失败会抛异常，不需要检查返回是否为null
		_a = new int[_size];
		memset(_a,0,sizeof(int)*_size);
	}
	void bitmap::set(unsigned long input)
	{
		_a[input>>5] |= 1<<(input&bitmap::_mask) ;
	}
	void bitmap::clear(unsigned long input)
	{
		_a[input>>5] &= 1<<(input&bitmap::_mask);
	}
	bool bitmap::contain(unsigned long input)
	{
		if (_a[input>>5]&(1<<(input&bitmap::_mask)))
		{
			return true;
		}
		return false;
	}
	
